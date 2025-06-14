import * as Parser from "tree-sitter";
import * as Calculator from "./bindings/node";

// Initialize the parser with the calculator grammar
const parser = new Parser();
parser.setLanguage(Calculator);

const curlCode0 = `curl --request POST \
     -X GET \
     --url https://example.com/api \
     --header 'Content-Type: application/json' \
     --header 'Content-Type: application/json' \
     -H 'Authotization: Bearer 1234567890' \
     --data '{"name": "test"}'`;

const curlCode1 = `curl --request POST \
  --url http://121.40.102.152:9969/v1/chat/completions \
  --header 'Content-Type: application/json' \
  --data '{
  "max_tokens": 0,
  "messages": [
        {
      "content": "hi",
      "role": "user"
    }
  ],
  "model": "CHAT",
  "stream": true,
  "temperature": 0,
  "ip": "121.40.102.152"
}'`;

const curlCode2 = `
curl --location 'https://api.example.com/users?id=123' \
--header 'Content-Type: application/json' \
--header 'Authorization: Bearer your_access_token_here' \
--data-raw ''
`;

const curlCode3 = `curl --request POST \
  http://121.40.102.152:9969/v1/chat/completions \
  --header 'Content-Type: application/json' \
  --data '{
  "max_tokens": 0,
  "messages": [
        {
      "content": "hi",
      "role": "user"
    }
  ],
  "model": "CHAT",
  "stream": true,
  "temperature": 0,
  "ip": "121.40.102.152"
}'`;

// Example 2: Parse and traverse the AST
function parseAndTraverse(curlCode: string) {
  const sourceCode = curlCode;
  const tree = parser.parse(sourceCode);

  function traverse(node: Parser.SyntaxNode, depth = 0) {
    const indent = "  ".repeat(depth);
    console.log(`${indent}type:${node.type} text:"${node.text}"`);

    for (const child of node.children) {
      traverse(child, depth + 1);
    }
  }

  console.log("\nTraversing AST for:", sourceCode);
  traverse(tree.rootNode);

  return tree;
}

function extractHeaders(sourceCode: string): string[] {
  const tree = parser.parse(sourceCode);
  const strings: string[] = [];

  function findHeaders(node: Parser.SyntaxNode) {
    if (node.type === "header_option") {
      strings.push(node.children[1].text);
    }

    for (const child of node.children) {
      findHeaders(child);
    }
  }

  findHeaders(tree.rootNode);
  return strings;
}

function extractMethod(sourceCode: string): string[] {
  const tree = parser.parse(sourceCode);
  const method_types: string[] = [];

  function findMethodType(node: Parser.SyntaxNode) {
    if (node.type === "method_option") {
      method_types.push(node.children[1].text);
    }

    for (const child of node.children) {
      findMethodType(child);
    }
  }

  findMethodType(tree.rootNode);
  return method_types;
}

function extractUrl(sourceCode: string): string[] {
  const tree = parser.parse(sourceCode);
  const urls: string[] = [];

  function findUrl(node: Parser.SyntaxNode) {
    if (node.type === "url_option" || node.type === "location_option") {
      urls.push(node.children[1].text);
      return urls;
    }
    if (node.type === "url") {
      urls.push(node.text);
      return urls;
    }

    for (const child of node.children) {
      findUrl(child);
    }
  }

  findUrl(tree.rootNode);
  return urls;
}

function extractData(sourceCode: string): string[] {
  const tree = parser.parse(sourceCode);
  const data: string[] = [];

  function findData(node: Parser.SyntaxNode) {
    if (node.type === "data_option") {
      data.push(node.children[1].text);
    }

    for (const child of node.children) {
      findData(child);
    }
  }

  findData(tree.rootNode);
  return data;
}

function analyzeCurlCommand(
  curlCode: string,
  index: number
): {
  headers: string[];
  methods: string[];
  urls: string[];
  data: string[];
} {
  const result = {
    headers: [] as string[],
    methods: [] as string[],
    urls: [] as string[],
    data: [] as string[],
  };

  console.log(`\n===== Analyzing curlCode${index} =====`);

  // 1. Print AST structure
  console.log("\n[AST Structure]");
  parseAndTraverse(curlCode);

  // 2. Extract and check elements
  console.log("\n[Extracted Elements]");

  // Extract values
  result.headers = extractHeaders(curlCode);
  result.methods = extractMethod(curlCode);
  result.urls = extractUrl(curlCode);
  result.data = extractData(curlCode);

  console.log("Headers:", result.headers);
  console.log("Methods:", result.methods);
  console.log("URLs:", result.urls);
  console.log("Data:", result.data);

  return result;
}

// Example 4: Validate expression syntax
function validateExpression(sourceCode: string): {
  valid: boolean;
  errors: string[];
} {
  const tree = parser.parse(sourceCode);
  const errors: string[] = [];

  function checkForErrors(node: Parser.SyntaxNode) {
    if (node.hasError) {
      errors.push(`Syntax error at "${node.text}"`);
    }

    for (const child of node.children) {
      checkForErrors(child);
    }
  }

  checkForErrors(tree.rootNode);

  return {
    valid: errors.length === 0,
    errors,
  };
}

// Run analysis for all curl commands
export function runExamples() {
  console.log("=== Curl Command Analysis Examples ===\n");

  let res = analyzeCurlCommand(curlCode0, 0);
  assertEqual(res.headers, [
    "'Content-Type: application/json'",
    "'Content-Type: application/json'",
    "'Authotization: Bearer 1234567890'",
  ]);
  assertEqual(res.methods, ["POST", "GET"]);
  assertEqual(res.urls, ["https://example.com/api"]);
  assertEqual(res.data, [`'{"name": "test"}'`]);

  res = analyzeCurlCommand(curlCode1, 1);
  assertEqual(res.headers, ["'Content-Type: application/json'"]);
  assertEqual(res.methods, ["POST"]);
  assertEqual(res.urls, ["http://121.40.102.152:9969/v1/chat/completions"]);
  assertEqual(res.data, [
    "'{\n" +
      '  "max_tokens": 0,\n' +
      '  "messages": [\n' +
      "        {\n" +
      '      "content": "hi",\n' +
      '      "role": "user"\n' +
      "    }\n" +
      "  ],\n" +
      '  "model": "CHAT",\n' +
      '  "stream": true,\n' +
      '  "temperature": 0,\n' +
      '  "ip": "121.40.102.152"\n' +
      "}'",
  ]);

  res = analyzeCurlCommand(curlCode2, 2);
  assertEqual(res.headers, [
    "'Content-Type: application/json'",
    "'Authorization: Bearer your_access_token_here'",
  ]);
  assertEqual(res.methods, []);
  assertEqual(res.urls, ["'https://api.example.com/users?id=123'"]);
  assertEqual(res.data, ["''"]);

  res = analyzeCurlCommand(curlCode3, 3);
  assertEqual(res.headers, ["'Content-Type: application/json'"]);
  assertEqual(res.methods, ["POST"]);
  assertEqual(res.urls, ["http://121.40.102.152:9969/v1/chat/completions"]);
  assertEqual(res.data, [
    "'{\n" +
      '  "max_tokens": 0,\n' +
      '  "messages": [\n' +
      "        {\n" +
      '      "content": "hi",\n' +
      '      "role": "user"\n' +
      "    }\n" +
      "  ],\n" +
      '  "model": "CHAT",\n' +
      '  "stream": true,\n' +
      '  "temperature": 0,\n' +
      '  "ip": "121.40.102.152"\n' +
      "}'",
  ]);
}

// Run examples if this file is executed directly
if (require.main === module) {
  runExamples();
}

function assertEqual(actual: any, expected: any, message?: string) {
  if (JSON.stringify(actual) !== JSON.stringify(expected)) {
    throw new Error(
      message ||
        `Expected ${JSON.stringify(expected)}, but got ${JSON.stringify(
          actual
        )}`
    );
  }
  console.log("✓ Assertion passed");
}

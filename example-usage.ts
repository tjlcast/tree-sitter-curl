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

`

// Example 1: Parse a simple expression
function parseSimpleExpression() {
  const sourceCode = `curl --request POST \
     -X GET \
     --url https://example.com/api \
     --header 'Content-Type: application/json' \
     -H 'Authotization: Bearer 1234567890' \
     --data '{"name": "test"}'`;
  const tree = parser.parse(sourceCode);

  console.log("Source:", sourceCode);
  console.log("Parse tree:", tree.rootNode.toString());

  return tree;
}

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

// Example 3: Extract numbers from expression
function extractHeaders(sourceCode: string): string[] {
  const tree = parser.parse(sourceCode);
  const strings: string[] = [];

  // 递归查找节点中的数字
  function findNumbers(node: Parser.SyntaxNode) {
    // 如果节点类型为header_value，则将节点文本转换为浮点数并添加到numbers数组中
    if (node.type === "header_option") {
      // numbers.push(parseFloat(node.text));
      strings.push(node.children[1].text);
    }

    // 遍历节点的子节点
    for (const child of node.children) {
      // 递归调用findNumbers函数
      findNumbers(child);
    }
  }

  findNumbers(tree.rootNode);
  // return numbers;
  return strings;
}

function extractMethod(sourceCode: string): string[] {
  const tree = parser.parse(sourceCode);
  const method_types: string[] = [];

  // 递归查找节点中的数字
  function findMethodType(node: Parser.SyntaxNode) {
    // 如果节点类型为header_value，则将节点文本转换为浮点数并添加到numbers数组中
    if (node.type === "method_option") {
      // numbers.push(parseFloat(node.text));
      method_types.push(node.children[1].text);
    }

    // 遍历节点的子节点
    for (const child of node.children) {
      // 递归调用findNumbers函数
      findMethodType(child);
    }
  }

  findMethodType(tree.rootNode);
  // return numbers;
  return method_types;
}

function extractUrl(sourceCode: string): string[] {
  const tree = parser.parse(sourceCode);
  const method_types: string[] = [];

  // 递归查找节点中的数字
  function findType(node: Parser.SyntaxNode) {
    // 如果节点类型为header_value，则将节点文本转换为浮点数并添加到numbers数组中
    if (node.type === "url_option") {
      // numbers.push(parseFloat(node.text));
      method_types.push(node.children[1].text);
    }

    // 遍历节点的子节点
    for (const child of node.children) {
      // 递归调用findNumbers函数
      findType(child);
    }
  }

  findType(tree.rootNode);
  // return numbers;
  return method_types;
}

function extractData(sourceCode: string): string[] {
  const tree = parser.parse(sourceCode);
  const method_types: string[] = [];

  // 递归查找节点中的数字
  function findType(node: Parser.SyntaxNode) {
    // 如果节点类型为header_value，则将节点文本转换为浮点数并添加到numbers数组中
    if (node.type === "data_option") {
      // numbers.push(parseFloat(node.text));
      method_types.push(node.children[1].text);
    }

    // 遍历节点的子节点
    for (const child of node.children) {
      // 递归调用findNumbers函数
      findType(child);
    }
  }

  findType(tree.rootNode);
  // return numbers;
  return method_types;
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

// Example 5: Get operator precedence information
function analyzeOperators(sourceCode: string) {
  const tree = parser.parse(sourceCode);
  const operators: Array<{ operator: string; precedence: number }> = [];

  function findOperators(node: Parser.SyntaxNode) {
    if (node.type === "binary_expression") {
      // Find the operator in this binary expression
      for (const child of node.children) {
        const text = child.text;
        if (["+", "-", "*", "/", "%"].includes(text)) {
          const precedence = ["*", "/", "%"].includes(text) ? 2 : 1;
          operators.push({ operator: text, precedence });
          break;
        }
      }
    }

    for (const child of node.children) {
      findOperators(child);
    }
  }

  findOperators(tree.rootNode);
  return operators;
}

// Example 6: Pretty print the expression tree
function prettyPrintTree(sourceCode: string): string {
  const tree = parser.parse(sourceCode);

  function printNode(node: Parser.SyntaxNode, depth = 0): string {
    const indent = "  ".repeat(depth);
    let result = `${indent}(${node.type}`;

    if (node.children.length === 0) {
      result += ` "${node.text}"`;
    } else {
      result += "\n";
      for (const child of node.children) {
        result += printNode(child, depth + 1);
      }
      result += indent;
    }

    result += ")\n";
    return result;
  }

  return printNode(tree.rootNode);
}

// Example usage
export function runExamples() {
  console.log("=== Tree-sitter Calculator Parser Examples ===\n");

  // Example 1
  console.log("1. Simple expression parsing:");
  parseSimpleExpression();
  console.log();

  // Example 2
  const code = curlCode2;
  console.log("2. AST traversal:");
  parseAndTraverse(code);
  console.log();

  // Example 3
  const curlCode = curlCode2;
  console.log("3. Extract numbers:");
  const numbers = extractHeaders(curlCode);
  console.log("Numbers found:", numbers);
  const nodes = extractMethod(curlCode);
  console.log("method_type: ", nodes);
  const url = extractUrl(curlCode);
  console.log("url: ", url);
  const data_option = extractData(curlCode);
  console.log("data: ", data_option);
  console.log();

  // // Example 4
  // console.log("4. Validate expressions:");
  // console.log("Valid:", validateExpression("2 + 3"));
  // console.log("Invalid:", validateExpression("2 + + 3"));
  // console.log();

  // // Example 5
  // console.log("5. Analyze operators:");
  // const ops = analyzeOperators("2 + 3 * 4 - 1");
  // console.log("Operators:", ops);
  // console.log();

  // // Example 6
  // console.log("6. Pretty print tree:");
  // console.log(prettyPrintTree("(2 + 3) * 4"));
}

// Simple calculator evaluator using the AST
export function evaluateExpression(sourceCode: string): number {
  const tree = parser.parse(sourceCode);

  function evaluate(node: Parser.SyntaxNode): number {
    switch (node.type) {
      case "source_file":
        // Evaluate the first expression
        return evaluate(node.children[0]);

      case "expression":
        // Evaluate the child expression
        return evaluate(node.children[0]);

      case "number":
        return parseFloat(node.text);

      case "binary_expression":
        const left = evaluate(node.children[0]);
        const operator = node.children[1].text;
        const right = evaluate(node.children[2]);

        switch (operator) {
          case "+":
            return left + right;
          case "-":
            return left - right;
          case "*":
            return left * right;
          case "/":
            return left / right;
          case "%":
            return left % right;
          default:
            throw new Error(`Unknown operator: ${operator}`);
        }

      case "grouped_expression":
        // Evaluate the expression inside parentheses
        return evaluate(node.children[1]);

      default:
        throw new Error(`Unknown node type: ${node.type}`);
    }
  }

  return evaluate(tree.rootNode);
}

// Run examples if this file is executed directly
if (require.main === module) {
  runExamples();

  // Test the evaluator
  console.log("\n=== Expression Evaluator ===");
  const expressions = [
    "2 + 3",
    "2 + 3 * 4",
    "(2 + 3) * 4",
    "10 / 2 + 3",
    "15 % 4 + 1",
  ];

  expressions.forEach((expr) => {
    try {
      const result = evaluateExpression(expr);
      console.log(`${expr} = ${result}`);
    } catch (error) {
      console.log(`${expr} = ERROR: ${(error as Error).message}`);
    }
  });
}

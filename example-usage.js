"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.runExamples = runExamples;
var Parser = require("tree-sitter");
var Calculator = require("./bindings/node");
// Initialize the parser with the calculator grammar
var parser = new Parser();
parser.setLanguage(Calculator);
var curlCode0 = "curl --request POST      -X GET      --url https://example.com/api      --header 'Content-Type: application/json'      --header 'Content-Type: application/json'      -H 'Authotization: Bearer 1234567890'      --data '{\"name\": \"test\"}'";
var curlCode1 = "curl --request POST   --url http://121.40.102.152:9969/v1/chat/completions   --header 'Content-Type: application/json'   --data '{\n  \"max_tokens\": 0,\n  \"messages\": [\n        {\n      \"content\": \"hi\",\n      \"role\": \"user\"\n    }\n  ],\n  \"model\": \"CHAT\",\n  \"stream\": true,\n  \"temperature\": 0,\n  \"ip\": \"121.40.102.152\"\n}'";
var curlCode2 = "\ncurl --location 'https://api.example.com/users?id=123' --header 'Content-Type: application/json' --header 'Authorization: Bearer your_access_token_here' --data-raw ''\n";
var curlCode3 = "curl --request POST   http://121.40.102.152:9969/v1/chat/completions   --header 'Content-Type: application/json'   --data '{\n  \"max_tokens\": 0,\n  \"messages\": [\n        {\n      \"content\": \"hi\",\n      \"role\": \"user\"\n    }\n  ],\n  \"model\": \"CHAT\",\n  \"stream\": true,\n  \"temperature\": 0,\n  \"ip\": \"121.40.102.152\"\n}'";
// Example 2: Parse and traverse the AST
function parseAndTraverse(curlCode) {
    var sourceCode = curlCode;
    var tree = parser.parse(sourceCode);
    function traverse(node, depth) {
        if (depth === void 0) { depth = 0; }
        var indent = "  ".repeat(depth);
        console.log("".concat(indent, "type:").concat(node.type, " text:\"").concat(node.text, "\""));
        for (var _i = 0, _a = node.children; _i < _a.length; _i++) {
            var child = _a[_i];
            traverse(child, depth + 1);
        }
    }
    console.log("\nTraversing AST for:", sourceCode);
    traverse(tree.rootNode);
    return tree;
}
function extractHeaders(sourceCode) {
    var tree = parser.parse(sourceCode);
    var strings = [];
    function findHeaders(node) {
        if (node.type === "header_option") {
            strings.push(node.children[1].text);
        }
        for (var _i = 0, _a = node.children; _i < _a.length; _i++) {
            var child = _a[_i];
            findHeaders(child);
        }
    }
    findHeaders(tree.rootNode);
    return strings;
}
function extractMethod(sourceCode) {
    var tree = parser.parse(sourceCode);
    var method_types = [];
    function findMethodType(node) {
        if (node.type === "method_option") {
            method_types.push(node.children[1].text);
        }
        for (var _i = 0, _a = node.children; _i < _a.length; _i++) {
            var child = _a[_i];
            findMethodType(child);
        }
    }
    findMethodType(tree.rootNode);
    return method_types;
}
function extractUrl(sourceCode) {
    var tree = parser.parse(sourceCode);
    var urls = [];
    function findUrl(node) {
        if (node.type === "url_option" || node.type === "location_option") {
            urls.push(node.children[1].text);
            return urls;
        }
        if (node.type === "url") {
            urls.push(node.text);
            return urls;
        }
        for (var _i = 0, _a = node.children; _i < _a.length; _i++) {
            var child = _a[_i];
            findUrl(child);
        }
    }
    findUrl(tree.rootNode);
    return urls;
}
function extractData(sourceCode) {
    var tree = parser.parse(sourceCode);
    var data = [];
    function findData(node) {
        if (node.type === "data_option") {
            data.push(node.children[1].text);
        }
        for (var _i = 0, _a = node.children; _i < _a.length; _i++) {
            var child = _a[_i];
            findData(child);
        }
    }
    findData(tree.rootNode);
    return data;
}
function analyzeCurlCommand(curlCode, index) {
    var result = {
        headers: [],
        methods: [],
        urls: [],
        data: [],
    };
    console.log("\n===== Analyzing curlCode".concat(index, " ====="));
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
function validateExpression(sourceCode) {
    var tree = parser.parse(sourceCode);
    var errors = [];
    function checkForErrors(node) {
        if (node.hasError) {
            errors.push("Syntax error at \"".concat(node.text, "\""));
        }
        for (var _i = 0, _a = node.children; _i < _a.length; _i++) {
            var child = _a[_i];
            checkForErrors(child);
        }
    }
    checkForErrors(tree.rootNode);
    return {
        valid: errors.length === 0,
        errors: errors,
    };
}
// Run analysis for all curl commands
function runExamples() {
    console.log("=== Curl Command Analysis Examples ===\n");
    var res = analyzeCurlCommand(curlCode0, 0);
    assertEqual(res.headers, [
        "'Content-Type: application/json'",
        "'Content-Type: application/json'",
        "'Authotization: Bearer 1234567890'",
    ]);
    assertEqual(res.methods, ["POST", "GET"]);
    assertEqual(res.urls, ["https://example.com/api"]);
    assertEqual(res.data, ["'{\"name\": \"test\"}'"]);
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
function assertEqual(actual, expected, message) {
    if (JSON.stringify(actual) !== JSON.stringify(expected)) {
        throw new Error(message ||
            "Expected ".concat(JSON.stringify(expected), ", but got ").concat(JSON.stringify(actual)));
    }
    console.log("✓ Assertion passed");
}

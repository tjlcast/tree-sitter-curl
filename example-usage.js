"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.runExamples = runExamples;
exports.evaluateExpression = evaluateExpression;
var Parser = require("tree-sitter");
var Calculator = require("./bindings/node");
// Initialize the parser with the calculator grammar
var parser = new Parser();
parser.setLanguage(Calculator);
var curlCode0 = "curl --request POST      -X GET      --url https://example.com/api      --header 'Content-Type: application/json'      --header 'Content-Type: application/json'      -H 'Authotization: Bearer 1234567890'      --data '{\"name\": \"test\"}'";
var curlCode1 = "curl --request POST   --url http://121.40.102.152:9969/v1/chat/completions   --header 'Content-Type: application/json'   --data '{\n  \"max_tokens\": 0,\n  \"messages\": [\n        {\n      \"content\": \"hi\",\n      \"role\": \"user\"\n    }\n  ],\n  \"model\": \"CHAT\",\n  \"stream\": true,\n  \"temperature\": 0,\n  \"ip\": \"121.40.102.152\"\n}'";
var curlCode2 = "\ncurl --location 'https://api.example.com/users?id=123' --header 'Content-Type: application/json' --header 'Authorization: Bearer your_access_token_here' --data-raw ''\n\n";
// Example 1: Parse a simple expression
function parseSimpleExpression() {
    var sourceCode = "curl --request POST      -X GET      --url https://example.com/api      --header 'Content-Type: application/json'      -H 'Authotization: Bearer 1234567890'      --data '{\"name\": \"test\"}'";
    var tree = parser.parse(sourceCode);
    console.log("Source:", sourceCode);
    console.log("Parse tree:", tree.rootNode.toString());
    return tree;
}
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
// Example 3: Extract numbers from expression
function extractHeaders(sourceCode) {
    var tree = parser.parse(sourceCode);
    var strings = [];
    // 递归查找节点中的数字
    function findNumbers(node) {
        // 如果节点类型为header_value，则将节点文本转换为浮点数并添加到numbers数组中
        if (node.type === "header_option") {
            // numbers.push(parseFloat(node.text));
            strings.push(node.children[1].text);
        }
        // 遍历节点的子节点
        for (var _i = 0, _a = node.children; _i < _a.length; _i++) {
            var child = _a[_i];
            // 递归调用findNumbers函数
            findNumbers(child);
        }
    }
    findNumbers(tree.rootNode);
    // return numbers;
    return strings;
}
function extractMethod(sourceCode) {
    var tree = parser.parse(sourceCode);
    var method_types = [];
    // 递归查找节点中的数字
    function findMethodType(node) {
        // 如果节点类型为header_value，则将节点文本转换为浮点数并添加到numbers数组中
        if (node.type === "method_option") {
            // numbers.push(parseFloat(node.text));
            method_types.push(node.children[1].text);
        }
        // 遍历节点的子节点
        for (var _i = 0, _a = node.children; _i < _a.length; _i++) {
            var child = _a[_i];
            // 递归调用findNumbers函数
            findMethodType(child);
        }
    }
    findMethodType(tree.rootNode);
    // return numbers;
    return method_types;
}
function extractUrl(sourceCode) {
    var tree = parser.parse(sourceCode);
    var method_types = [];
    // 递归查找节点中的数字
    function findType(node) {
        // 如果节点类型为header_value，则将节点文本转换为浮点数并添加到numbers数组中
        if (node.type === "url_option") {
            // numbers.push(parseFloat(node.text));
            method_types.push(node.children[1].text);
        }
        // 遍历节点的子节点
        for (var _i = 0, _a = node.children; _i < _a.length; _i++) {
            var child = _a[_i];
            // 递归调用findNumbers函数
            findType(child);
        }
    }
    findType(tree.rootNode);
    // return numbers;
    return method_types;
}
function extractData(sourceCode) {
    var tree = parser.parse(sourceCode);
    var method_types = [];
    // 递归查找节点中的数字
    function findType(node) {
        // 如果节点类型为header_value，则将节点文本转换为浮点数并添加到numbers数组中
        if (node.type === "data_option") {
            // numbers.push(parseFloat(node.text));
            method_types.push(node.children[1].text);
        }
        // 遍历节点的子节点
        for (var _i = 0, _a = node.children; _i < _a.length; _i++) {
            var child = _a[_i];
            // 递归调用findNumbers函数
            findType(child);
        }
    }
    findType(tree.rootNode);
    // return numbers;
    return method_types;
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
// Example 5: Get operator precedence information
function analyzeOperators(sourceCode) {
    var tree = parser.parse(sourceCode);
    var operators = [];
    function findOperators(node) {
        if (node.type === "binary_expression") {
            // Find the operator in this binary expression
            for (var _i = 0, _a = node.children; _i < _a.length; _i++) {
                var child = _a[_i];
                var text = child.text;
                if (["+", "-", "*", "/", "%"].includes(text)) {
                    var precedence = ["*", "/", "%"].includes(text) ? 2 : 1;
                    operators.push({ operator: text, precedence: precedence });
                    break;
                }
            }
        }
        for (var _b = 0, _c = node.children; _b < _c.length; _b++) {
            var child = _c[_b];
            findOperators(child);
        }
    }
    findOperators(tree.rootNode);
    return operators;
}
// Example 6: Pretty print the expression tree
function prettyPrintTree(sourceCode) {
    var tree = parser.parse(sourceCode);
    function printNode(node, depth) {
        if (depth === void 0) { depth = 0; }
        var indent = "  ".repeat(depth);
        var result = "".concat(indent, "(").concat(node.type);
        if (node.children.length === 0) {
            result += " \"".concat(node.text, "\"");
        }
        else {
            result += "\n";
            for (var _i = 0, _a = node.children; _i < _a.length; _i++) {
                var child = _a[_i];
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
function runExamples() {
    console.log("=== Tree-sitter Calculator Parser Examples ===\n");
    // Example 1
    console.log("1. Simple expression parsing:");
    parseSimpleExpression();
    console.log();
    // Example 2
    var code = curlCode2;
    console.log("2. AST traversal:");
    parseAndTraverse(code);
    console.log();
    // Example 3
    var curlCode = curlCode2;
    console.log("3. Extract numbers:");
    var numbers = extractHeaders(curlCode);
    console.log("Numbers found:", numbers);
    var nodes = extractMethod(curlCode);
    console.log("method_type: ", nodes);
    var url = extractUrl(curlCode);
    console.log("url: ", url);
    var data_option = extractData(curlCode);
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
function evaluateExpression(sourceCode) {
    var tree = parser.parse(sourceCode);
    function evaluate(node) {
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
                var left = evaluate(node.children[0]);
                var operator = node.children[1].text;
                var right = evaluate(node.children[2]);
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
                        throw new Error("Unknown operator: ".concat(operator));
                }
            case "grouped_expression":
                // Evaluate the expression inside parentheses
                return evaluate(node.children[1]);
            default:
                throw new Error("Unknown node type: ".concat(node.type));
        }
    }
    return evaluate(tree.rootNode);
}
// Run examples if this file is executed directly
if (require.main === module) {
    runExamples();
    // Test the evaluator
    console.log("\n=== Expression Evaluator ===");
    var expressions = [
        "2 + 3",
        "2 + 3 * 4",
        "(2 + 3) * 4",
        "10 / 2 + 3",
        "15 % 4 + 1",
    ];
    expressions.forEach(function (expr) {
        try {
            var result = evaluateExpression(expr);
            console.log("".concat(expr, " = ").concat(result));
        }
        catch (error) {
            console.log("".concat(expr, " = ERROR: ").concat(error.message));
        }
    });
}

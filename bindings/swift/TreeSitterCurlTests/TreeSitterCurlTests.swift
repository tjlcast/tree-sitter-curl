import XCTest
import SwiftTreeSitter
import TreeSitterCurl

final class TreeSitterCurlTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_curl())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading Curl grammar")
    }
}

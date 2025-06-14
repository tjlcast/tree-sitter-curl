package tree_sitter_curl_test

import (
	"testing"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	tree_sitter_curl "github.com/tree-sitter/tree-sitter-curl/bindings/go"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_curl.Language())
	if language == nil {
		t.Errorf("Error loading Curl grammar")
	}
}

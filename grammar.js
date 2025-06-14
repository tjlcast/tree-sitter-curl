module.exports = grammar({
  name: "curl",

  extras: ($) => [/\s+/, $.comment],

  rules: {
    source_file: ($) => repeat($.curl_command),

    comment: (_) => token(seq("#", /.*/)),

    // 修改：允许 URL 直接出现在 curl 命令中
    curl_command: ($) => seq("curl", optional($.url), repeat($.option)),

    option: ($) =>
      choice(
        $.method_option,
        $.url_option,
        $.header_option,
        $.data_option,
        $.location_option,
        $.other_option
      ),

    method_option: ($) =>
      seq(choice("--request", "-X"), field("method", $.word)),

    url_option: ($) =>
      seq(
        choice("--url", "-U"),
        field("url", choice($.url, $.quoted_string))
      ),

    location_option: ($) =>
      seq(
        choice("--location", "-L"),
        field("url", choice($.url, $.quoted_string))
      ),

    header_option: ($) =>
      seq(choice("--header", "-H"), field("header", $.quoted_string)),

    data_option: ($) =>
      seq(
        choice("--data", "-d", "--data-raw", "--data-ascii", "--data-binary"),
        field("data", choice($.quoted_string, $.unquoted_data))
      ),

    other_option: ($) => seq(/-\w+/, optional($.word)),

    word: (_) => /[^\s\\]+/,
    url: (_) => /https?:\/\/[^\s\\'"]+/,

    quoted_string: (_) => /'(?:[^'\\]|\\.)*'|"(?:[^"\\]|\\.)*"/,

    unquoted_data: (_) => /[^\s\\][^\n\\]*/,
  },
});
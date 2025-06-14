module.exports = grammar({
  name: "curl",

  extras: ($) => [/\s+/, $.comment],

  rules: {
    source_file: ($) => repeat($.curl_command),

    comment: (_) => token(seq("#", /.*/)),

    curl_command: ($) => seq("curl", repeat($.option)),

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
        field("url", choice($.url, $.quoted_string)) // 修改为接受两种形式
      ),

    location_option: ($) =>
      seq(
        choice("--location", "-L"),
        field("url", choice($.url, $.quoted_string)) // 关键修改：接受引号或裸URL
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

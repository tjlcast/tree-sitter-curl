#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 21
#define LARGE_STATE_COUNT 13
#define SYMBOL_COUNT 32
#define ALIAS_COUNT 0
#define TOKEN_COUNT 21
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 4
#define MAX_ALIAS_SEQUENCE_LENGTH 2
#define PRODUCTION_ID_COUNT 5

enum ts_symbol_identifiers {
  sym_comment = 1,
  anon_sym_curl = 2,
  anon_sym_DASH_DASHrequest = 3,
  anon_sym_DASHX = 4,
  anon_sym_DASH_DASHurl = 5,
  anon_sym_DASHU = 6,
  anon_sym_DASH_DASHlocation = 7,
  anon_sym_DASHL = 8,
  anon_sym_DASH_DASHheader = 9,
  anon_sym_DASHH = 10,
  anon_sym_DASH_DASHdata = 11,
  anon_sym_DASHd = 12,
  anon_sym_DASH_DASHdata_DASHraw = 13,
  anon_sym_DASH_DASHdata_DASHascii = 14,
  anon_sym_DASH_DASHdata_DASHbinary = 15,
  aux_sym_other_option_token1 = 16,
  sym_word = 17,
  sym_url = 18,
  sym_quoted_string = 19,
  sym_unquoted_data = 20,
  sym_source_file = 21,
  sym_curl_command = 22,
  sym_option = 23,
  sym_method_option = 24,
  sym_url_option = 25,
  sym_location_option = 26,
  sym_header_option = 27,
  sym_data_option = 28,
  sym_other_option = 29,
  aux_sym_source_file_repeat1 = 30,
  aux_sym_curl_command_repeat1 = 31,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_comment] = "comment",
  [anon_sym_curl] = "curl",
  [anon_sym_DASH_DASHrequest] = "--request",
  [anon_sym_DASHX] = "-X",
  [anon_sym_DASH_DASHurl] = "--url",
  [anon_sym_DASHU] = "-U",
  [anon_sym_DASH_DASHlocation] = "--location",
  [anon_sym_DASHL] = "-L",
  [anon_sym_DASH_DASHheader] = "--header",
  [anon_sym_DASHH] = "-H",
  [anon_sym_DASH_DASHdata] = "--data",
  [anon_sym_DASHd] = "-d",
  [anon_sym_DASH_DASHdata_DASHraw] = "--data-raw",
  [anon_sym_DASH_DASHdata_DASHascii] = "--data-ascii",
  [anon_sym_DASH_DASHdata_DASHbinary] = "--data-binary",
  [aux_sym_other_option_token1] = "other_option_token1",
  [sym_word] = "word",
  [sym_url] = "url",
  [sym_quoted_string] = "quoted_string",
  [sym_unquoted_data] = "unquoted_data",
  [sym_source_file] = "source_file",
  [sym_curl_command] = "curl_command",
  [sym_option] = "option",
  [sym_method_option] = "method_option",
  [sym_url_option] = "url_option",
  [sym_location_option] = "location_option",
  [sym_header_option] = "header_option",
  [sym_data_option] = "data_option",
  [sym_other_option] = "other_option",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_curl_command_repeat1] = "curl_command_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_comment] = sym_comment,
  [anon_sym_curl] = anon_sym_curl,
  [anon_sym_DASH_DASHrequest] = anon_sym_DASH_DASHrequest,
  [anon_sym_DASHX] = anon_sym_DASHX,
  [anon_sym_DASH_DASHurl] = anon_sym_DASH_DASHurl,
  [anon_sym_DASHU] = anon_sym_DASHU,
  [anon_sym_DASH_DASHlocation] = anon_sym_DASH_DASHlocation,
  [anon_sym_DASHL] = anon_sym_DASHL,
  [anon_sym_DASH_DASHheader] = anon_sym_DASH_DASHheader,
  [anon_sym_DASHH] = anon_sym_DASHH,
  [anon_sym_DASH_DASHdata] = anon_sym_DASH_DASHdata,
  [anon_sym_DASHd] = anon_sym_DASHd,
  [anon_sym_DASH_DASHdata_DASHraw] = anon_sym_DASH_DASHdata_DASHraw,
  [anon_sym_DASH_DASHdata_DASHascii] = anon_sym_DASH_DASHdata_DASHascii,
  [anon_sym_DASH_DASHdata_DASHbinary] = anon_sym_DASH_DASHdata_DASHbinary,
  [aux_sym_other_option_token1] = aux_sym_other_option_token1,
  [sym_word] = sym_word,
  [sym_url] = sym_url,
  [sym_quoted_string] = sym_quoted_string,
  [sym_unquoted_data] = sym_unquoted_data,
  [sym_source_file] = sym_source_file,
  [sym_curl_command] = sym_curl_command,
  [sym_option] = sym_option,
  [sym_method_option] = sym_method_option,
  [sym_url_option] = sym_url_option,
  [sym_location_option] = sym_location_option,
  [sym_header_option] = sym_header_option,
  [sym_data_option] = sym_data_option,
  [sym_other_option] = sym_other_option,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_curl_command_repeat1] = aux_sym_curl_command_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_curl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_DASHrequest] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASHX] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_DASHurl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASHU] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_DASHlocation] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASHL] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_DASHheader] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASHH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_DASHdata] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASHd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_DASHdata_DASHraw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_DASHdata_DASHascii] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_DASHdata_DASHbinary] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_other_option_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_word] = {
    .visible = true,
    .named = true,
  },
  [sym_url] = {
    .visible = true,
    .named = true,
  },
  [sym_quoted_string] = {
    .visible = true,
    .named = true,
  },
  [sym_unquoted_data] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_curl_command] = {
    .visible = true,
    .named = true,
  },
  [sym_option] = {
    .visible = true,
    .named = true,
  },
  [sym_method_option] = {
    .visible = true,
    .named = true,
  },
  [sym_url_option] = {
    .visible = true,
    .named = true,
  },
  [sym_location_option] = {
    .visible = true,
    .named = true,
  },
  [sym_header_option] = {
    .visible = true,
    .named = true,
  },
  [sym_data_option] = {
    .visible = true,
    .named = true,
  },
  [sym_other_option] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_curl_command_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_data = 1,
  field_header = 2,
  field_method = 3,
  field_url = 4,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_data] = "data",
  [field_header] = "header",
  [field_method] = "method",
  [field_url] = "url",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 1},
  [4] = {.index = 3, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_method, 1},
  [1] =
    {field_url, 1},
  [2] =
    {field_header, 1},
  [3] =
    {field_data, 1},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(57);
      if (lookahead == '#') ADVANCE(59);
      if (lookahead == '-') ADVANCE(91);
      if (lookahead == 'c') ADVANCE(134);
      if (lookahead == 'h') ADVANCE(132);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (lookahead != 0 &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(141);
      if (lookahead == '\\') ADVANCE(53);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(143);
      if (lookahead == '#') ADVANCE(58);
      if (lookahead == '\'') ADVANCE(144);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (lookahead != 0 &&
          lookahead != '\\') ADVANCE(145);
      END_STATE();
    case 3:
      if (lookahead == '#') ADVANCE(59);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (lookahead != 0 &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 4:
      if (lookahead == '\'') ADVANCE(141);
      if (lookahead == '\\') ADVANCE(54);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 5:
      if (lookahead == '-') ADVANCE(19);
      if (lookahead == 'H') ADVANCE(78);
      if (lookahead == 'L') ADVANCE(74);
      if (lookahead == 'U') ADVANCE(70);
      if (lookahead == 'X') ADVANCE(66);
      if (lookahead == 'd') ADVANCE(82);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(90);
      END_STATE();
    case 6:
      if (lookahead == '/') ADVANCE(52);
      END_STATE();
    case 7:
      if (lookahead == '/') ADVANCE(6);
      END_STATE();
    case 8:
      if (lookahead == ':') ADVANCE(7);
      END_STATE();
    case 9:
      if (lookahead == ':') ADVANCE(7);
      if (lookahead == 's') ADVANCE(8);
      END_STATE();
    case 10:
      if (lookahead == 'a') ADVANCE(20);
      END_STATE();
    case 11:
      if (lookahead == 'a') ADVANCE(80);
      END_STATE();
    case 12:
      if (lookahead == 'a') ADVANCE(50);
      END_STATE();
    case 13:
      if (lookahead == 'a') ADVANCE(41);
      if (lookahead == 'b') ADVANCE(25);
      if (lookahead == 'r') ADVANCE(12);
      END_STATE();
    case 14:
      if (lookahead == 'a') ADVANCE(47);
      END_STATE();
    case 15:
      if (lookahead == 'a') ADVANCE(39);
      END_STATE();
    case 16:
      if (lookahead == 'a') ADVANCE(44);
      END_STATE();
    case 17:
      if (lookahead == 'c') ADVANCE(28);
      END_STATE();
    case 18:
      if (lookahead == 'c') ADVANCE(16);
      END_STATE();
    case 19:
      if (lookahead == 'd') ADVANCE(14);
      if (lookahead == 'h') ADVANCE(24);
      if (lookahead == 'l') ADVANCE(33);
      if (lookahead == 'r') ADVANCE(21);
      if (lookahead == 'u') ADVANCE(40);
      END_STATE();
    case 20:
      if (lookahead == 'd') ADVANCE(23);
      END_STATE();
    case 21:
      if (lookahead == 'e') ADVANCE(36);
      END_STATE();
    case 22:
      if (lookahead == 'e') ADVANCE(42);
      END_STATE();
    case 23:
      if (lookahead == 'e') ADVANCE(38);
      END_STATE();
    case 24:
      if (lookahead == 'e') ADVANCE(10);
      END_STATE();
    case 25:
      if (lookahead == 'i') ADVANCE(32);
      END_STATE();
    case 26:
      if (lookahead == 'i') ADVANCE(85);
      END_STATE();
    case 27:
      if (lookahead == 'i') ADVANCE(34);
      END_STATE();
    case 28:
      if (lookahead == 'i') ADVANCE(26);
      END_STATE();
    case 29:
      if (lookahead == 'l') ADVANCE(61);
      END_STATE();
    case 30:
      if (lookahead == 'l') ADVANCE(67);
      END_STATE();
    case 31:
      if (lookahead == 'n') ADVANCE(71);
      END_STATE();
    case 32:
      if (lookahead == 'n') ADVANCE(15);
      END_STATE();
    case 33:
      if (lookahead == 'o') ADVANCE(18);
      END_STATE();
    case 34:
      if (lookahead == 'o') ADVANCE(31);
      END_STATE();
    case 35:
      if (lookahead == 'p') ADVANCE(9);
      END_STATE();
    case 36:
      if (lookahead == 'q') ADVANCE(49);
      END_STATE();
    case 37:
      if (lookahead == 'r') ADVANCE(29);
      END_STATE();
    case 38:
      if (lookahead == 'r') ADVANCE(75);
      END_STATE();
    case 39:
      if (lookahead == 'r') ADVANCE(51);
      END_STATE();
    case 40:
      if (lookahead == 'r') ADVANCE(30);
      END_STATE();
    case 41:
      if (lookahead == 's') ADVANCE(17);
      END_STATE();
    case 42:
      if (lookahead == 's') ADVANCE(45);
      END_STATE();
    case 43:
      if (lookahead == 't') ADVANCE(35);
      END_STATE();
    case 44:
      if (lookahead == 't') ADVANCE(27);
      END_STATE();
    case 45:
      if (lookahead == 't') ADVANCE(63);
      END_STATE();
    case 46:
      if (lookahead == 't') ADVANCE(43);
      END_STATE();
    case 47:
      if (lookahead == 't') ADVANCE(11);
      END_STATE();
    case 48:
      if (lookahead == 'u') ADVANCE(37);
      END_STATE();
    case 49:
      if (lookahead == 'u') ADVANCE(22);
      END_STATE();
    case 50:
      if (lookahead == 'w') ADVANCE(83);
      END_STATE();
    case 51:
      if (lookahead == 'y') ADVANCE(87);
      END_STATE();
    case 52:
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(140);
      END_STATE();
    case 53:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(1);
      END_STATE();
    case 54:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(4);
      END_STATE();
    case 55:
      if (eof) ADVANCE(57);
      if (lookahead == '"') ADVANCE(1);
      if (lookahead == '#') ADVANCE(60);
      if (lookahead == '\'') ADVANCE(4);
      if (lookahead == '-') ADVANCE(5);
      if (lookahead == 'c') ADVANCE(48);
      if (lookahead == 'h') ADVANCE(46);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(55);
      END_STATE();
    case 56:
      if (eof) ADVANCE(57);
      if (lookahead == '#') ADVANCE(59);
      if (lookahead == '-') ADVANCE(91);
      if (lookahead == 'c') ADVANCE(134);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(56);
      if (lookahead != 0 &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead == '\\') ADVANCE(60);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(58);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ' ||
          lookahead == '\\') ADVANCE(60);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(59);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(60);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_curl);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_curl);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_DASH_DASHrequest);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_DASH_DASHrequest);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_DASHX);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(89);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_DASHX);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(90);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_DASH_DASHurl);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_DASH_DASHurl);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_DASHU);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(89);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_DASHU);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(90);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_DASH_DASHlocation);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_DASH_DASHlocation);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_DASHL);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(89);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_DASHL);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(90);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_DASH_DASHheader);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_DASH_DASHheader);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_DASHH);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(89);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_DASHH);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(90);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_DASH_DASHdata);
      if (lookahead == '-') ADVANCE(99);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(anon_sym_DASH_DASHdata);
      if (lookahead == '-') ADVANCE(13);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_DASHd);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(89);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(anon_sym_DASHd);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(90);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_DASH_DASHdata_DASHraw);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_DASH_DASHdata_DASHraw);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_DASH_DASHdata_DASHascii);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_DASH_DASHdata_DASHascii);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_DASH_DASHdata_DASHbinary);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(anon_sym_DASH_DASHdata_DASHbinary);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(aux_sym_other_option_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(89);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(aux_sym_other_option_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(90);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '-') ADVANCE(105);
      if (lookahead == 'H') ADVANCE(77);
      if (lookahead == 'L') ADVANCE(73);
      if (lookahead == 'U') ADVANCE(69);
      if (lookahead == 'X') ADVANCE(65);
      if (lookahead == 'd') ADVANCE(81);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(89);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '/') ADVANCE(138);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '/') ADVANCE(92);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == ':') ADVANCE(93);
      if (lookahead == 's') ADVANCE(95);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == ':') ADVANCE(93);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'a') ADVANCE(106);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'a') ADVANCE(79);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'a') ADVANCE(136);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'a') ADVANCE(127);
      if (lookahead == 'b') ADVANCE(111);
      if (lookahead == 'r') ADVANCE(98);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'a') ADVANCE(133);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'a') ADVANCE(125);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'a') ADVANCE(130);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'c') ADVANCE(114);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'c') ADVANCE(102);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'd') ADVANCE(100);
      if (lookahead == 'h') ADVANCE(110);
      if (lookahead == 'l') ADVANCE(119);
      if (lookahead == 'r') ADVANCE(107);
      if (lookahead == 'u') ADVANCE(126);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'd') ADVANCE(109);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'e') ADVANCE(122);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'e') ADVANCE(128);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'e') ADVANCE(124);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'e') ADVANCE(96);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'i') ADVANCE(118);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'i') ADVANCE(86);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'i') ADVANCE(120);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'i') ADVANCE(112);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'l') ADVANCE(62);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'l') ADVANCE(68);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'n') ADVANCE(72);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'n') ADVANCE(101);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'o') ADVANCE(104);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'o') ADVANCE(117);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'p') ADVANCE(94);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'q') ADVANCE(135);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'r') ADVANCE(115);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'r') ADVANCE(76);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'r') ADVANCE(137);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'r') ADVANCE(116);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 's') ADVANCE(103);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 's') ADVANCE(131);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 't') ADVANCE(121);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 't') ADVANCE(113);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 't') ADVANCE(64);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 't') ADVANCE(129);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 't') ADVANCE(97);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'u') ADVANCE(123);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'u') ADVANCE(108);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'w') ADVANCE(84);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == 'y') ADVANCE(88);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '"' ||
          lookahead == '\'') ADVANCE(139);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(138);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(sym_word);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(sym_url);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(140);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(sym_quoted_string);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(sym_quoted_string);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\\') ADVANCE(145);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(sym_unquoted_data);
      if (lookahead == '\n') ADVANCE(1);
      if (lookahead == '"') ADVANCE(142);
      if (lookahead == '\\') ADVANCE(53);
      if (lookahead != 0) ADVANCE(143);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(sym_unquoted_data);
      if (lookahead == '\n') ADVANCE(4);
      if (lookahead == '\'') ADVANCE(142);
      if (lookahead == '\\') ADVANCE(54);
      if (lookahead != 0) ADVANCE(144);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(sym_unquoted_data);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\\') ADVANCE(145);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 55},
  [2] = {.lex_state = 55},
  [3] = {.lex_state = 55},
  [4] = {.lex_state = 55},
  [5] = {.lex_state = 56},
  [6] = {.lex_state = 55},
  [7] = {.lex_state = 55},
  [8] = {.lex_state = 55},
  [9] = {.lex_state = 55},
  [10] = {.lex_state = 55},
  [11] = {.lex_state = 55},
  [12] = {.lex_state = 55},
  [13] = {.lex_state = 55},
  [14] = {.lex_state = 55},
  [15] = {.lex_state = 55},
  [16] = {.lex_state = 55},
  [17] = {.lex_state = 2},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 3},
  [20] = {.lex_state = 55},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
    [anon_sym_curl] = ACTIONS(1),
    [anon_sym_DASH_DASHrequest] = ACTIONS(1),
    [anon_sym_DASHX] = ACTIONS(1),
    [anon_sym_DASH_DASHurl] = ACTIONS(1),
    [anon_sym_DASHU] = ACTIONS(1),
    [anon_sym_DASH_DASHlocation] = ACTIONS(1),
    [anon_sym_DASHL] = ACTIONS(1),
    [anon_sym_DASH_DASHheader] = ACTIONS(1),
    [anon_sym_DASHH] = ACTIONS(1),
    [anon_sym_DASH_DASHdata] = ACTIONS(1),
    [anon_sym_DASHd] = ACTIONS(1),
    [anon_sym_DASH_DASHdata_DASHraw] = ACTIONS(1),
    [anon_sym_DASH_DASHdata_DASHascii] = ACTIONS(1),
    [anon_sym_DASH_DASHdata_DASHbinary] = ACTIONS(1),
    [aux_sym_other_option_token1] = ACTIONS(1),
    [sym_word] = ACTIONS(1),
    [sym_url] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(18),
    [sym_curl_command] = STATE(13),
    [aux_sym_source_file_repeat1] = STATE(13),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_comment] = ACTIONS(3),
    [anon_sym_curl] = ACTIONS(7),
  },
  [2] = {
    [sym_option] = STATE(3),
    [sym_method_option] = STATE(6),
    [sym_url_option] = STATE(6),
    [sym_location_option] = STATE(6),
    [sym_header_option] = STATE(6),
    [sym_data_option] = STATE(6),
    [sym_other_option] = STATE(6),
    [aux_sym_curl_command_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(9),
    [sym_comment] = ACTIONS(3),
    [anon_sym_curl] = ACTIONS(9),
    [anon_sym_DASH_DASHrequest] = ACTIONS(11),
    [anon_sym_DASHX] = ACTIONS(13),
    [anon_sym_DASH_DASHurl] = ACTIONS(15),
    [anon_sym_DASHU] = ACTIONS(17),
    [anon_sym_DASH_DASHlocation] = ACTIONS(19),
    [anon_sym_DASHL] = ACTIONS(21),
    [anon_sym_DASH_DASHheader] = ACTIONS(23),
    [anon_sym_DASHH] = ACTIONS(25),
    [anon_sym_DASH_DASHdata] = ACTIONS(27),
    [anon_sym_DASHd] = ACTIONS(27),
    [anon_sym_DASH_DASHdata_DASHraw] = ACTIONS(29),
    [anon_sym_DASH_DASHdata_DASHascii] = ACTIONS(29),
    [anon_sym_DASH_DASHdata_DASHbinary] = ACTIONS(29),
    [aux_sym_other_option_token1] = ACTIONS(31),
  },
  [3] = {
    [sym_option] = STATE(4),
    [sym_method_option] = STATE(6),
    [sym_url_option] = STATE(6),
    [sym_location_option] = STATE(6),
    [sym_header_option] = STATE(6),
    [sym_data_option] = STATE(6),
    [sym_other_option] = STATE(6),
    [aux_sym_curl_command_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(33),
    [sym_comment] = ACTIONS(3),
    [anon_sym_curl] = ACTIONS(33),
    [anon_sym_DASH_DASHrequest] = ACTIONS(11),
    [anon_sym_DASHX] = ACTIONS(13),
    [anon_sym_DASH_DASHurl] = ACTIONS(15),
    [anon_sym_DASHU] = ACTIONS(17),
    [anon_sym_DASH_DASHlocation] = ACTIONS(19),
    [anon_sym_DASHL] = ACTIONS(21),
    [anon_sym_DASH_DASHheader] = ACTIONS(23),
    [anon_sym_DASHH] = ACTIONS(25),
    [anon_sym_DASH_DASHdata] = ACTIONS(27),
    [anon_sym_DASHd] = ACTIONS(27),
    [anon_sym_DASH_DASHdata_DASHraw] = ACTIONS(29),
    [anon_sym_DASH_DASHdata_DASHascii] = ACTIONS(29),
    [anon_sym_DASH_DASHdata_DASHbinary] = ACTIONS(29),
    [aux_sym_other_option_token1] = ACTIONS(31),
  },
  [4] = {
    [sym_option] = STATE(4),
    [sym_method_option] = STATE(6),
    [sym_url_option] = STATE(6),
    [sym_location_option] = STATE(6),
    [sym_header_option] = STATE(6),
    [sym_data_option] = STATE(6),
    [sym_other_option] = STATE(6),
    [aux_sym_curl_command_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(35),
    [sym_comment] = ACTIONS(3),
    [anon_sym_curl] = ACTIONS(35),
    [anon_sym_DASH_DASHrequest] = ACTIONS(37),
    [anon_sym_DASHX] = ACTIONS(40),
    [anon_sym_DASH_DASHurl] = ACTIONS(43),
    [anon_sym_DASHU] = ACTIONS(46),
    [anon_sym_DASH_DASHlocation] = ACTIONS(49),
    [anon_sym_DASHL] = ACTIONS(52),
    [anon_sym_DASH_DASHheader] = ACTIONS(55),
    [anon_sym_DASHH] = ACTIONS(58),
    [anon_sym_DASH_DASHdata] = ACTIONS(61),
    [anon_sym_DASHd] = ACTIONS(61),
    [anon_sym_DASH_DASHdata_DASHraw] = ACTIONS(64),
    [anon_sym_DASH_DASHdata_DASHascii] = ACTIONS(64),
    [anon_sym_DASH_DASHdata_DASHbinary] = ACTIONS(64),
    [aux_sym_other_option_token1] = ACTIONS(67),
  },
  [5] = {
    [ts_builtin_sym_end] = ACTIONS(70),
    [sym_comment] = ACTIONS(3),
    [anon_sym_curl] = ACTIONS(72),
    [anon_sym_DASH_DASHrequest] = ACTIONS(72),
    [anon_sym_DASHX] = ACTIONS(72),
    [anon_sym_DASH_DASHurl] = ACTIONS(72),
    [anon_sym_DASHU] = ACTIONS(72),
    [anon_sym_DASH_DASHlocation] = ACTIONS(72),
    [anon_sym_DASHL] = ACTIONS(72),
    [anon_sym_DASH_DASHheader] = ACTIONS(72),
    [anon_sym_DASHH] = ACTIONS(72),
    [anon_sym_DASH_DASHdata] = ACTIONS(72),
    [anon_sym_DASHd] = ACTIONS(72),
    [anon_sym_DASH_DASHdata_DASHraw] = ACTIONS(72),
    [anon_sym_DASH_DASHdata_DASHascii] = ACTIONS(72),
    [anon_sym_DASH_DASHdata_DASHbinary] = ACTIONS(72),
    [aux_sym_other_option_token1] = ACTIONS(72),
    [sym_word] = ACTIONS(74),
  },
  [6] = {
    [ts_builtin_sym_end] = ACTIONS(76),
    [sym_comment] = ACTIONS(3),
    [anon_sym_curl] = ACTIONS(76),
    [anon_sym_DASH_DASHrequest] = ACTIONS(76),
    [anon_sym_DASHX] = ACTIONS(78),
    [anon_sym_DASH_DASHurl] = ACTIONS(76),
    [anon_sym_DASHU] = ACTIONS(78),
    [anon_sym_DASH_DASHlocation] = ACTIONS(76),
    [anon_sym_DASHL] = ACTIONS(78),
    [anon_sym_DASH_DASHheader] = ACTIONS(76),
    [anon_sym_DASHH] = ACTIONS(78),
    [anon_sym_DASH_DASHdata] = ACTIONS(78),
    [anon_sym_DASHd] = ACTIONS(78),
    [anon_sym_DASH_DASHdata_DASHraw] = ACTIONS(76),
    [anon_sym_DASH_DASHdata_DASHascii] = ACTIONS(76),
    [anon_sym_DASH_DASHdata_DASHbinary] = ACTIONS(76),
    [aux_sym_other_option_token1] = ACTIONS(78),
  },
  [7] = {
    [ts_builtin_sym_end] = ACTIONS(80),
    [sym_comment] = ACTIONS(3),
    [anon_sym_curl] = ACTIONS(80),
    [anon_sym_DASH_DASHrequest] = ACTIONS(80),
    [anon_sym_DASHX] = ACTIONS(82),
    [anon_sym_DASH_DASHurl] = ACTIONS(80),
    [anon_sym_DASHU] = ACTIONS(82),
    [anon_sym_DASH_DASHlocation] = ACTIONS(80),
    [anon_sym_DASHL] = ACTIONS(82),
    [anon_sym_DASH_DASHheader] = ACTIONS(80),
    [anon_sym_DASHH] = ACTIONS(82),
    [anon_sym_DASH_DASHdata] = ACTIONS(82),
    [anon_sym_DASHd] = ACTIONS(82),
    [anon_sym_DASH_DASHdata_DASHraw] = ACTIONS(80),
    [anon_sym_DASH_DASHdata_DASHascii] = ACTIONS(80),
    [anon_sym_DASH_DASHdata_DASHbinary] = ACTIONS(80),
    [aux_sym_other_option_token1] = ACTIONS(82),
  },
  [8] = {
    [ts_builtin_sym_end] = ACTIONS(84),
    [sym_comment] = ACTIONS(3),
    [anon_sym_curl] = ACTIONS(84),
    [anon_sym_DASH_DASHrequest] = ACTIONS(84),
    [anon_sym_DASHX] = ACTIONS(86),
    [anon_sym_DASH_DASHurl] = ACTIONS(84),
    [anon_sym_DASHU] = ACTIONS(86),
    [anon_sym_DASH_DASHlocation] = ACTIONS(84),
    [anon_sym_DASHL] = ACTIONS(86),
    [anon_sym_DASH_DASHheader] = ACTIONS(84),
    [anon_sym_DASHH] = ACTIONS(86),
    [anon_sym_DASH_DASHdata] = ACTIONS(86),
    [anon_sym_DASHd] = ACTIONS(86),
    [anon_sym_DASH_DASHdata_DASHraw] = ACTIONS(84),
    [anon_sym_DASH_DASHdata_DASHascii] = ACTIONS(84),
    [anon_sym_DASH_DASHdata_DASHbinary] = ACTIONS(84),
    [aux_sym_other_option_token1] = ACTIONS(86),
  },
  [9] = {
    [ts_builtin_sym_end] = ACTIONS(88),
    [sym_comment] = ACTIONS(3),
    [anon_sym_curl] = ACTIONS(88),
    [anon_sym_DASH_DASHrequest] = ACTIONS(88),
    [anon_sym_DASHX] = ACTIONS(90),
    [anon_sym_DASH_DASHurl] = ACTIONS(88),
    [anon_sym_DASHU] = ACTIONS(90),
    [anon_sym_DASH_DASHlocation] = ACTIONS(88),
    [anon_sym_DASHL] = ACTIONS(90),
    [anon_sym_DASH_DASHheader] = ACTIONS(88),
    [anon_sym_DASHH] = ACTIONS(90),
    [anon_sym_DASH_DASHdata] = ACTIONS(90),
    [anon_sym_DASHd] = ACTIONS(90),
    [anon_sym_DASH_DASHdata_DASHraw] = ACTIONS(88),
    [anon_sym_DASH_DASHdata_DASHascii] = ACTIONS(88),
    [anon_sym_DASH_DASHdata_DASHbinary] = ACTIONS(88),
    [aux_sym_other_option_token1] = ACTIONS(90),
  },
  [10] = {
    [ts_builtin_sym_end] = ACTIONS(92),
    [sym_comment] = ACTIONS(3),
    [anon_sym_curl] = ACTIONS(92),
    [anon_sym_DASH_DASHrequest] = ACTIONS(92),
    [anon_sym_DASHX] = ACTIONS(94),
    [anon_sym_DASH_DASHurl] = ACTIONS(92),
    [anon_sym_DASHU] = ACTIONS(94),
    [anon_sym_DASH_DASHlocation] = ACTIONS(92),
    [anon_sym_DASHL] = ACTIONS(94),
    [anon_sym_DASH_DASHheader] = ACTIONS(92),
    [anon_sym_DASHH] = ACTIONS(94),
    [anon_sym_DASH_DASHdata] = ACTIONS(94),
    [anon_sym_DASHd] = ACTIONS(94),
    [anon_sym_DASH_DASHdata_DASHraw] = ACTIONS(92),
    [anon_sym_DASH_DASHdata_DASHascii] = ACTIONS(92),
    [anon_sym_DASH_DASHdata_DASHbinary] = ACTIONS(92),
    [aux_sym_other_option_token1] = ACTIONS(94),
  },
  [11] = {
    [ts_builtin_sym_end] = ACTIONS(96),
    [sym_comment] = ACTIONS(3),
    [anon_sym_curl] = ACTIONS(96),
    [anon_sym_DASH_DASHrequest] = ACTIONS(96),
    [anon_sym_DASHX] = ACTIONS(98),
    [anon_sym_DASH_DASHurl] = ACTIONS(96),
    [anon_sym_DASHU] = ACTIONS(98),
    [anon_sym_DASH_DASHlocation] = ACTIONS(96),
    [anon_sym_DASHL] = ACTIONS(98),
    [anon_sym_DASH_DASHheader] = ACTIONS(96),
    [anon_sym_DASHH] = ACTIONS(98),
    [anon_sym_DASH_DASHdata] = ACTIONS(98),
    [anon_sym_DASHd] = ACTIONS(98),
    [anon_sym_DASH_DASHdata_DASHraw] = ACTIONS(96),
    [anon_sym_DASH_DASHdata_DASHascii] = ACTIONS(96),
    [anon_sym_DASH_DASHdata_DASHbinary] = ACTIONS(96),
    [aux_sym_other_option_token1] = ACTIONS(98),
  },
  [12] = {
    [ts_builtin_sym_end] = ACTIONS(100),
    [sym_comment] = ACTIONS(3),
    [anon_sym_curl] = ACTIONS(100),
    [anon_sym_DASH_DASHrequest] = ACTIONS(100),
    [anon_sym_DASHX] = ACTIONS(102),
    [anon_sym_DASH_DASHurl] = ACTIONS(100),
    [anon_sym_DASHU] = ACTIONS(102),
    [anon_sym_DASH_DASHlocation] = ACTIONS(100),
    [anon_sym_DASHL] = ACTIONS(102),
    [anon_sym_DASH_DASHheader] = ACTIONS(100),
    [anon_sym_DASHH] = ACTIONS(102),
    [anon_sym_DASH_DASHdata] = ACTIONS(102),
    [anon_sym_DASHd] = ACTIONS(102),
    [anon_sym_DASH_DASHdata_DASHraw] = ACTIONS(100),
    [anon_sym_DASH_DASHdata_DASHascii] = ACTIONS(100),
    [anon_sym_DASH_DASHdata_DASHbinary] = ACTIONS(100),
    [aux_sym_other_option_token1] = ACTIONS(102),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_curl,
    ACTIONS(104), 1,
      ts_builtin_sym_end,
    STATE(14), 2,
      sym_curl_command,
      aux_sym_source_file_repeat1,
  [14] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(106), 1,
      ts_builtin_sym_end,
    ACTIONS(108), 1,
      anon_sym_curl,
    STATE(14), 2,
      sym_curl_command,
      aux_sym_source_file_repeat1,
  [28] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(111), 2,
      sym_url,
      sym_quoted_string,
  [36] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(113), 2,
      sym_url,
      sym_quoted_string,
  [44] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(115), 2,
      sym_quoted_string,
      sym_unquoted_data,
  [52] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(117), 1,
      ts_builtin_sym_end,
  [59] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(119), 1,
      sym_word,
  [66] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(121), 1,
      sym_quoted_string,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(13)] = 0,
  [SMALL_STATE(14)] = 14,
  [SMALL_STATE(15)] = 28,
  [SMALL_STATE(16)] = 36,
  [SMALL_STATE(17)] = 44,
  [SMALL_STATE(18)] = 52,
  [SMALL_STATE(19)] = 59,
  [SMALL_STATE(20)] = 66,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [9] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_curl_command, 1, 0, 0),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_curl_command, 2, 0, 0),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_curl_command_repeat1, 2, 0, 0),
  [37] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_curl_command_repeat1, 2, 0, 0), SHIFT_REPEAT(19),
  [40] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_curl_command_repeat1, 2, 0, 0), SHIFT_REPEAT(19),
  [43] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_curl_command_repeat1, 2, 0, 0), SHIFT_REPEAT(15),
  [46] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_curl_command_repeat1, 2, 0, 0), SHIFT_REPEAT(15),
  [49] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_curl_command_repeat1, 2, 0, 0), SHIFT_REPEAT(16),
  [52] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_curl_command_repeat1, 2, 0, 0), SHIFT_REPEAT(16),
  [55] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_curl_command_repeat1, 2, 0, 0), SHIFT_REPEAT(20),
  [58] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_curl_command_repeat1, 2, 0, 0), SHIFT_REPEAT(20),
  [61] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_curl_command_repeat1, 2, 0, 0), SHIFT_REPEAT(17),
  [64] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_curl_command_repeat1, 2, 0, 0), SHIFT_REPEAT(17),
  [67] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_curl_command_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_other_option, 1, 0, 0),
  [72] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_other_option, 1, 0, 0),
  [74] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_option, 1, 0, 0),
  [78] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_option, 1, 0, 0),
  [80] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_data_option, 2, 0, 4),
  [82] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_data_option, 2, 0, 4),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_method_option, 2, 0, 1),
  [86] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_method_option, 2, 0, 1),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_url_option, 2, 0, 2),
  [90] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_url_option, 2, 0, 2),
  [92] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_location_option, 2, 0, 2),
  [94] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_location_option, 2, 0, 2),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_header_option, 2, 0, 3),
  [98] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_header_option, 2, 0, 3),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_other_option, 2, 0, 0),
  [102] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_other_option, 2, 0, 0),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [106] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [108] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [115] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [117] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [119] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_curl(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif

#include "Compiler.hpp"
#include "Lexer.hpp"

#include <ios>
#include <limits>
#include <vector>

void Compiler::run()
{
  Lexer lexer;

  std::string line;
  std::vector<std::string> files;
  std::filesystem::path path = std::filesystem::current_path();



  int index = 0;
  bool success = true;
  std::vector<Token> tokens;
  
  std::cout << "Lexer Test 1...";
  std::string filename = "Lexer_Test_1.spk";
  tokens = lexer.lex(filename);

  if (tokens[index++].getType() != TokenType::tok_bool) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  if (tokens[index++].getType() != TokenType::tok_byte) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  if (tokens[index++].getType() != TokenType::tok_char) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  if (tokens[index++].getType() != TokenType::tok_uchar) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  if (tokens[index++].getType() != TokenType::tok_string) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  if (tokens[index++].getType() != TokenType::tok_int) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  if (tokens[index++].getType() != TokenType::tok_uint) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  if (tokens[index++].getType() != TokenType::tok_short) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  if (tokens[index++].getType() != TokenType::tok_ushort) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  if (tokens[index++].getType() != TokenType::tok_long) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  if (tokens[index++].getType() != TokenType::tok_ulong) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  if (tokens[index++].getType() != TokenType::tok_long_long) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  if (tokens[index++].getType() != TokenType::tok_ulong_long) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  if (tokens[index++].getType() != TokenType::tok_float) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  if (tokens[index++].getType() != TokenType::tok_double) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  if (tokens[index++].getType() != TokenType::tok_long_double) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  if (success) std::cout << "Passed\n";
  else         std::cout << "Failed\n";

  std::cout << tokens.size() - index << " tokens remaining\n";

  index   = 0;
  success = true;

  std::cout << "Lexer Test 2...\n";
  filename = "Lexer_Test_2.spk";
  tokens = lexer.lex(filename);

  std::cout << success << '\n';
  if (tokens[index++].getType() != TokenType::tok_function) success = false;
  if (tokens[index++].getType() != TokenType::tok_int) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_lparen) success = false;
  if (tokens[index++].getType() != TokenType::tok_rparen) success = false;
  if (tokens[index++].getType() != TokenType::tok_lbrace) success = false;

  std::cout << success << '\n';
  if (tokens[index++].getType() != TokenType::tok_uint) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_assign) success = false;
  if (tokens[index++].getType() != TokenType::tok_uint_literal) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  std::cout << success << '\n';
  if (tokens[index++].getType() != TokenType::tok_short) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_assign) success = false;
  if (tokens[index++].getType() != TokenType::tok_short_literal) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  std::cout << success << '\n';
  if (tokens[index++].getType() != TokenType::tok_ushort) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_assign) success = false;
  if (tokens[index++].getType() != TokenType::tok_ushort_literal) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  std::cout << success << '\n';
  if (tokens[index++].getType() != TokenType::tok_long) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_assign) success = false;
  if (tokens[index++].getType() != TokenType::tok_long_literal) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  std::cout << success << '\n';
  if (tokens[index++].getType() != TokenType::tok_ulong) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_assign) success = false;
  if (tokens[index++].getType() != TokenType::tok_ulong_literal) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  std::cout << success << '\n';
  if (tokens[index++].getType() != TokenType::tok_long_long) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_assign) success = false;
  if (tokens[index++].getType() != TokenType::tok_long_long_literal) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  std::cout << success << '\n';
  if (tokens[index++].getType() != TokenType::tok_ulong_long) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_assign) success = false;
  if (tokens[index++].getType() != TokenType::tok_ulong_long_literal) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  std::cout << success << '\n';
  if (tokens[index++].getType() != TokenType::tok_short) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_assign) success = false;
  if (tokens[index++].getType() != TokenType::tok_short_literal) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  std::cout << success << '\n';
  if (tokens[index++].getType() != TokenType::tok_ushort) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_assign) success = false;
  if (tokens[index++].getType() != TokenType::tok_ushort_literal) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  std::cout << success << '\n';
  if (tokens[index++].getType() != TokenType::tok_long) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_assign) success = false;
  if (tokens[index++].getType() != TokenType::tok_long_literal) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  std::cout << success << '\n';
  if (tokens[index++].getType() != TokenType::tok_ulong) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_assign) success = false;
  if (tokens[index++].getType() != TokenType::tok_ulong_literal) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  std::cout << success << '\n';
  if (tokens[index++].getType() != TokenType::tok_long_long) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_assign) success = false;
  if (tokens[index++].getType() != TokenType::tok_long_long_literal) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  std::cout << success << '\n';
  if (tokens[index++].getType() != TokenType::tok_ulong_long) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_assign) success = false;
  if (tokens[index++].getType() != TokenType::tok_ulong_long_literal) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  std::cout << success << '\n';
  if (tokens[index++].getType() != TokenType::tok_int) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_assign) success = false;
  if (tokens[index++].getType() != TokenType::tok_int_literal) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  std::cout << success << '\n';
  if (tokens[index++].getType() != TokenType::tok_int) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_assign) success = false;
  if (tokens[index++].getType() != TokenType::tok_int_literal) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  std::cout << success << '\n';
  if (tokens[index++].getType() != TokenType::tok_int) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_assign) success = false;
  if (tokens[index++].getType() != TokenType::tok_int_literal) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  std::cout << success << '\n';
  if (tokens[index++].getType() != TokenType::tok_int) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_assign) success = false;
  if (tokens[index++].getType() != TokenType::tok_int_literal) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  std::cout << success << '\n';
  if (tokens[index++].getType() != TokenType::tok_int) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_assign) success = false;
  if (tokens[index++].getType() != TokenType::tok_int_literal) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  std::cout << success << '\n';
  if (tokens[index++].getType() != TokenType::tok_return) success = false;
  if (tokens[index++].getType() != TokenType::tok_int_literal) success = false;
  if (tokens[index++].getType() != TokenType::tok_assign) success = false;
  if (tokens[index++].getType() != TokenType::tok_int_literal) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  std::cout << success << '\n';
  if (tokens[index++].getType() != TokenType::tok_rbrace) success = false;

  std::cout << success << '\n';
  if (success) std::cout << "Passed\n";
  else         std::cout << "Failed\n";

  std::cout << tokens.size() - index << " tokens remaining\n";

  index = 0;
  success = true;

  std::cout << "Lexer Test 3...";
  filename = "Lexer_Test_3.spk";
  tokens = lexer.lex(filename);

  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  if (tokens[index++].getType() != TokenType::tok_int_literal) success = false;
  if (tokens[index++].getType() != TokenType::tok_char) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_modulo) success = false;
  if (tokens[index++].getType() != TokenType::tok_int_literal) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  if (tokens[index++].getType() != TokenType::tok_uint) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_multiply) success = false;
  if (tokens[index++].getType() != TokenType::tok_bitwise_and) success = false;
  if (tokens[index++].getType() != TokenType::tok_bitwise_xor) success = false;
  if (tokens[index++].getType() != TokenType::tok_modulo) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  if (tokens[index++].getType() != TokenType::tok_ushort) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_modulo) success = false;
  if (tokens[index++].getType() != TokenType::tok_bitwise_xor) success = false;
  if (tokens[index++].getType() != TokenType::tok_logical_not) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  if (tokens[index++].getType() != TokenType::tok_long) success = false;
  if (tokens[index++].getType() != TokenType::tok_lparen) success = false;
  if (tokens[index++].getType() != TokenType::tok_multiply) success = false;
  if (tokens[index++].getType() != TokenType::tok_rparen) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_bitwise_xor) success = false;
  if (tokens[index++].getType() != TokenType::tok_logical_not) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_logical_xor) success = false;
  if (tokens[index++].getType() != TokenType::tok_logical_not) success = false;
  if (tokens[index++].getType() != TokenType::tok_bitwise_xor) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_int_literal) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  if (tokens[index++].getType() != TokenType::tok_float) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  if (tokens[index++].getType() != TokenType::tok_double) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;

  if (success) std::cout << "Passed\n";
  else         std::cout << "Failed\n";

  std::cout << tokens.size() - index << " tokens remaining\n";

  index = 0;
  success = true;

  std::cout << "Lexer Test 4...";
  filename = "Lexer_Test_4.spk";
  tokens = lexer.lex(filename);

  if (tokens[index++].getType() != TokenType::tok_class) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_assign) success = false;
  if (tokens[index++].getType() != TokenType::tok_lbrace) success = false;

  if (tokens[index++].getType() != TokenType::tok_public) success = false;
  if (tokens[index++].getType() != TokenType::tok_colon) success = false;

  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_lparen) success = false;
  if (tokens[index++].getType() != TokenType::tok_rparen) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;
  
  if (tokens[index++].getType() != TokenType::tok_private) success = false;
  if (tokens[index++].getType() != TokenType::tok_colon) success = false;

  if (tokens[index++].getType() != TokenType::tok_int) success = false;
  if (tokens[index++].getType() != TokenType::tok_identifier) success = false;
  if (tokens[index++].getType() != TokenType::tok_semi_colon) success = false;
  
  if (tokens[index++].getType() != TokenType::tok_rbrace) success = false;

  if (success) std::cout << "Passed\n";
  else         std::cout << "Failed\n";

  std::cout << tokens.size() - index << " tokens remaining\n";


  std::cin.ignore(10, '\n');
}
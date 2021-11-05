#include "Lexer.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <ctype.h>

std::vector<Token> Lexer::lex(std::string _file)
{
  std::ifstream file(_file);
  std::stringstream buffer;
  std::string data;

  buffer << file.rdbuf();
  data = buffer.str();

  std::string identifier;
  double number;
  std::vector<Token> tokens;
  for (int i = 0; i < data.length(); ++i)
  {
    Token newToken;
    
    // WHITE SPACE
    if (isspace(data[i]))
    {
      continue;
    }
    // STRINGS
    if (isalpha(data[i]))
    {
      identifier = data[i];
      ++i;
      while (isalnum(data[i]))
      {
        identifier += data[i];
        ++i;
      }
      --i;
      newToken.setTokenString(identifier);
      //
      // DATA TYPES
      //
      if (identifier == "byte")
      {
        newToken.setType(TokenType::tok_byte);
      }
      else if (identifier == "bool")
      {
        newToken.setType(TokenType::tok_bool);
      }
      else if (identifier == "char")
      {
        newToken.setType(TokenType::tok_char);
      }
      else if (identifier == "uchar")
      {
        newToken.setType(TokenType::tok_uchar);
      }
      else if (identifier == "char8")
      {
        newToken.setType(TokenType::tok_char8);
      }
      else if (identifier == "char16")
      {
        newToken.setType(TokenType::tok_char16);
      }
      else if (identifier == "char32")
      {
        newToken.setType(TokenType::tok_char32);
      }
      else if (identifier == "string")
      {
        newToken.setType(TokenType::tok_string);
      }
      else if (identifier == "string8")
      {
        newToken.setType(TokenType::tok_string8);
      }
      else if (identifier == "string16")
      {
        newToken.setType(TokenType::tok_string16);
      }
      else if (identifier == "string32")
      {
        newToken.setType(TokenType::tok_string32);
      }
      else if (identifier == "int")
      {
        newToken.setType(TokenType::tok_int);
      }
      else if (identifier == "uint")
      {
        newToken.setType(TokenType::tok_uint);
      }
      else if (identifier == "short")
      {
        newToken.setType(TokenType::tok_short);
      }
      else if (identifier == "ushort")
      {
        newToken.setType(TokenType::tok_ushort);
      }
      else if (identifier == "long")  
      {
        newToken.setType(TokenType::tok_long);
      }
      else if (identifier == "ulong")
      {
        newToken.setType(TokenType::tok_ulong);
      }
      else if (identifier == "float")
      {
        newToken.setType(TokenType::tok_float);
      }
      else if (identifier == "double")
      {
        newToken.setType(TokenType::tok_double);
      }
      //
      // FLOW CONTROL
      //
      else if (identifier == "if")
      {
        newToken.setType(TokenType::tok_if);
      }
      else if (identifier == "else")
      {
        newToken.setType(TokenType::tok_else);
      }
      else if (identifier == "switch")
      {
        newToken.setType(TokenType::tok_switch);
      }
      else if (identifier == "case")
      {
        newToken.setType(TokenType::tok_case);
      }
      else if (identifier == "default")
      {
        newToken.setType(TokenType::tok_default);
      }
      else if (identifier == "for")
      {
        newToken.setType(TokenType::tok_for);
      }
      else if (identifier == "while")
      {
        newToken.setType(TokenType::tok_while);
      }
      else if (identifier == "do")
      {
        newToken.setType(TokenType::tok_do);
      }
      else if (identifier == "break")
      {
        newToken.setType(TokenType::tok_break);
      }
      else if (identifier == "continue")
      {
        newToken.setType(TokenType::tok_continue);
      }
      else if (identifier == "return")
      {
        newToken.setType(TokenType::tok_return);
      }
      //
      // COMPARISON TOKENS
      //
      else if (identifier == "in")
      {
        newToken.setType(TokenType::tok_in);
      }
      else if (identifier == "not")
      {
       newToken.setType(TokenType::tok_logical_not);
      }
      else if (identifier == "or")
      {
        newToken.setType(TokenType::tok_logical_or);
      }
      else if (identifier == "xor")
      {
        newToken.setType(TokenType::tok_logical_xor);
      }
      else if (identifier == "and")
      {
        newToken.setType(TokenType::tok_logical_and);
      }
      else if (identifier == "equals")
      {
        newToken.setType(TokenType::tok_equals);
      }
      //
      // VALUE TOKENS
      //
      else if (identifier == "true")
      {
        newToken.setType(TokenType::tok_bool_literal);
      }
      else if (identifier == "false")
      {
       newToken.setType(TokenType::tok_bool_literal);
      }
      else if (identifier == "null")
      {
        newToken.setType(TokenType::tok_null);
      }
      else if (identifier == "this")
      {
        newToken.setType(TokenType::tok_this);
      }
      //
      // DEPENDENCY TOKENS
      //
      else if (identifier == "import")
      {
        newToken.setType(TokenType::tok_import);
      }
      else if (identifier == "export")
      {
        newToken.setType(TokenType::tok_export);
      }
      //
      // EXCEPTION TOKENS
      //
      else if (identifier == "try")
      {
        newToken.setType(TokenType::tok_try);
      }
      else if (identifier == "catch")
      {
        newToken.setType(TokenType::tok_catch);
      }
      else if (identifier == "finally")
      {
        newToken.setType(TokenType::tok_finally);
      }
      else if (identifier == "throw")
      {
        newToken.setType(TokenType::tok_throw);
      }
      //
      // OTHERS
      //
      else if (identifier == "const")
      {
        newToken.setType(TokenType::tok_const);
      }
      else if (identifier == "static")
      {
        newToken.setType(TokenType::tok_static);
      }
      else if (identifier == "void")
      {
        newToken.setType(TokenType::tok_void);
      }
      else if (identifier == "function")
      {
        newToken.setType(TokenType::tok_function);
      }
      else if (identifier == "class")
      {
        newToken.setType(TokenType::tok_class);
      }
      else if (identifier == "public")
      {
      newToken.setType(TokenType::tok_public);
      }
      else if (identifier == "private")
      {
      newToken.setType(TokenType::tok_private);
      }
      else if (identifier == "enum")
      {
        newToken.setType(TokenType::tok_enum);
      }
      //
      // NOT A KEYWORD
      //
      else
      {
        newToken.setType(TokenType::tok_identifier);
      }
      tokens.push_back(newToken);
    }
    // NUMBERS
    else if (isdigit(data[i]))
    {
      identifier = data[i];
      ++i;
      while (isdigit(data[i]) || data[i] == '.' 
            || data[i] == 'b' || data[i] == 'B'
            || data[i] == 'e' || data[i] == 'E'
            || data[i] == 'f' || data[i] == 'F'
            || data[i] == 'l' || data[i] == 'L'
            || data[i] == 's' || data[i] == 'S'
            || data[i] == 'u' || data[i] == 'U'
            || data[i] == 'x' || data[i] == 'X')
      {
        identifier += data[i];
        ++i;
      }
      --i;

       
      if (std::regex_match(identifier, std::regex("([0][bB][0-1]*[uU]?)"))          // Checks if its a binary int
       || std::regex_match(identifier, std::regex("([0][xX][0-9a-fA-F]{2}[uU]?)"))  // Checks if its a hex int
       || std::regex_match(identifier, std::regex("([0][0-7]*[uU]?)"))              // Checks if its an oct int
       || std::regex_match(identifier, std::regex("([1-9][0-9]*[uU]?)")))           // Checks if it a decimal int
      {
        newToken.setTokenInt(std::stoi(identifier));
        newToken.setType(TokenType::tok_int_literal);
      }
      // Checks if its a short
      else if (std::regex_match(identifier, std::regex()))
      {
        newToken.setTokenShort((short)std::stoi(identifier));
        newToken.setType(TokenType::tok_short_literal);
      }
      // Checks if its a long
      else if (std::regex_match(identifier, std::regex()))
      {
        // Checks if its a long long
        if (std::regex_match(identifier, std::regex()))
        {
          newToken.setTokenLongLong(std::stoll(identifier));
          newToken.setType(TokenType::tok_long_long_literal);
        }
        else
        {
          newToken.setTokenLong(std::stol(identifier));
          newToken.setType(TokenType::tok_long_literal);
        }
      }
      // Checks if its a float
      else if (std::regex_match(identifier, std::regex()))
      {
        newToken.setTokenFloat(std::stof(identifier));
        newToken.setType(TokenType::tok_float_literal);
      }
      // Checks if its a long double
      else if (std::regex_match(identifier, std::regex()))
      {
        newToken.setTokenLongDouble(std::stold(identifier));
        newToken.setType(TokenType::tok_long_double_literal);
      }
      // Checks if its a double
      else if (std::regex_match(identifier, std::regex()))
      {
        newToken.setTokenDouble(std::stod(identifier));
        newToken.setType(TokenType::tok_double_literal);
      }
      // Otherwise its not a valid number
      else
      {
        newToken.setTokenString("Invalid numeric literal");
        newToken.setType(TokenType::tok_error);
      }

      tokens.push_back(newToken);
    }
    // COMMENTS
    else if (data[i] == '#')
    {
      while (i < data.length() && data[i] != '\n' && data[i] != '\r')
      {
        ++i;
      }
      --i;
    }
    // OPERATORS
    else
    {
      identifier = data[i];
      //
      // We shouldn't need to look ahead for these. Theyre special operators
      //
      if (data[i] == '(')
      {
        newToken.setType(TokenType::tok_lparen);
        newToken.setTokenString(identifier);
      }
      else if (data[i] == ')')
      {
        newToken.setType(TokenType::tok_rparen);
        newToken.setTokenString(identifier);
      }
      else if (data[i] == '[')
      {
        newToken.setType(TokenType::tok_lbracket);
        newToken.setTokenString(identifier);
      }
      else if (data[i] == ']')
      {
        newToken.setType(TokenType::tok_rbracket);
        newToken.setTokenString(identifier);
      }
      else if (data[i] == '{')
      {
        newToken.setType(TokenType::tok_lbrace);
        newToken.setTokenString(identifier);
      }
      else if (data[i] == '}')
      {
        newToken.setType(TokenType::tok_rbrace);
        newToken.setTokenString(identifier);
      }
      else if (data[i] == '.')
      {
        newToken.setType(TokenType::tok_period);
        newToken.setTokenString(identifier);
      }
      else if (data[i] == ',')
      {
        newToken.setType(TokenType::tok_comma);
        newToken.setTokenString(identifier);
      }
      else if (data[i] == '\'')
      {
        newToken.setType(TokenType::tok_single_quote);
        newToken.setTokenString(identifier);
      }
      else if (data[i] == '\"')
      {
        newToken.setType(TokenType::tok_quote);
        newToken.setTokenString(identifier);
      }
      //
      // These we need to look ahead for
      // +, -, *, /, %, <, >, &, ^, |, =, !
      // In case they're multi char operators
      //
      else if (data[i] == '+')
      {
        if (data[i + 1] == '+')
        {
          ++i;
          identifier += data[i];
          newToken.setType(TokenType::tok_increment);
          newToken.setTokenString(identifier);
        }
        else if (data[i + 1] == '=')
        {
          ++i;
          identifier += data[i];
          newToken.setType(TokenType::tok_plus_assign);
          newToken.setTokenString(identifier);
        }
        else
        {
          newToken.setType(TokenType::tok_plus);
          newToken.setTokenString(identifier);
        }
      }
      else if (data[i] == '-')
      {
        if (data[i + 1] == '-')
        {
          ++i;
          identifier += data[i];
          newToken.setType(TokenType::tok_decrement);
          newToken.setTokenString(identifier);
        }
        else if (data[i + 1] == '=')
        {
          ++i;
          identifier += data[i];
          newToken.setType(TokenType::tok_plus_assign);
          newToken.setTokenString(identifier);
        }
        else
        {
          newToken.setType(TokenType::tok_minus);
          newToken.setTokenString(identifier);
        }
      }
      else if (data[i] == '/')
      {
        if (data[i + 1] == '=')
        {
          ++i;
          identifier += data[i];
          newToken.setType(TokenType::tok_divide_assign);
          newToken.setTokenString(identifier);
        }
        else
        {
          newToken.setType(TokenType::tok_divide);
          newToken.setTokenString(identifier);
        }
      }
      else if (data[i] == '*')
      {
        if (data[i + 1] == '=')
        {
          ++i;
          identifier += data[i];
          newToken.setType(TokenType::tok_multiply_assign);
          newToken.setTokenString(identifier);
        }
        else
        {
          newToken.setType(TokenType::tok_multiply);
          newToken.setTokenString(identifier);
        }
      }
      else if (data[i] == '%')
      {
        if (data[i + 1] == '=')
        {
          ++i;
          identifier += data[i];
          newToken.setType(TokenType::tok_modulo_assign);
          newToken.setTokenString(identifier);
        }
        else
        {
          newToken.setType(TokenType::tok_modulo);
          newToken.setTokenString(identifier);
        }
      }
      else if (data[i] == '&')
      {
        if (data[i + 1] == '&')
        {
          ++i;
          identifier += data[i];
          newToken.setType(TokenType::tok_logical_and);
          newToken.setTokenString(identifier);
        }
        else if (data[i + 1] == '=')
        {
          ++i;
          identifier += data[i];
          newToken.setType(TokenType::tok_bitwise_and_assign);
          newToken.setTokenString(identifier);
        }
        else
        {
          newToken.setType(TokenType::tok_bitwise_and);
          newToken.setTokenString(identifier);
        }
      }
      else if (data[i] == '|')
      {
        if (data[i + 1] == '|')
        {
          ++i;
          identifier += data[i];
          newToken.setType(TokenType::tok_logical_or);
          newToken.setTokenString(identifier);
        }
        else if (data[i + 1] == '=')
        {
          ++i;
          identifier += data[i];
          newToken.setType(TokenType::tok_bitwise_or_assign);
          newToken.setTokenString(identifier);
        }
        else
        {
          newToken.setType(TokenType::tok_bitwise_or);
          newToken.setTokenString(identifier);
        }
      }
      else if (data[i] == '^')
      {
        if (data[i + 1] == '^')
        {
          ++i;
          identifier += data[i];
          newToken.setType(TokenType::tok_logical_xor);
          newToken.setTokenString(identifier);
        }
        else if (data[i + 1] == '=')
        {
          ++i;
          identifier += data[i];
          newToken.setType(TokenType::tok_bitwise_xor_assign);
          newToken.setTokenString(identifier);
        }
        else
        {
          newToken.setType(TokenType::tok_bitwise_xor);
          newToken.setTokenString(identifier);
        }
      }
      else if (data[i] == '>')
      {
        if (data[i + 1] == '>')
        {
          ++i;
          identifier += data[i];
          if (data[i + 1] == '=')
          {
            ++i;
            identifier += data[i];
            newToken.setType(TokenType::tok_bitwise_shift_right_assign);
          }
          else
          {
            newToken.setType(TokenType::tok_bitwise_shift_right);
          }
          newToken.setTokenString(identifier);
        }
        else if (data[i + 1] == '=')
        {
          ++i;
          identifier += data[i];
          newToken.setType(TokenType::tok_greater_than_equals);
          newToken.setTokenString(identifier);
        }
        else
        {
          newToken.setType(TokenType::tok_greater_than);
          newToken.setTokenString(identifier);
        }
      }
      else if (data[i] == '<')
      {
        if (data[i + 1] == '<')
        {
          ++i;
          identifier += data[i];
          if (data[i + 1] == '=')
          {
            ++i;
            identifier += data[i];
            newToken.setType(TokenType::tok_bitwise_shift_left_assign);
          }
          else
          {
            newToken.setType(TokenType::tok_bitwise_shift_left);
          }
          newToken.setTokenString(identifier);
        }
        else if (data[i + 1] == '=')
        {
          ++i;
          identifier += data[i];
          newToken.setType(TokenType::tok_less_than_equals);
          newToken.setTokenString(identifier);
        }
        else
        {
          newToken.setType(TokenType::tok_less_than);
          newToken.setTokenString(identifier);
        }
      }
      else if (data[i] == '=')
      {
        if (data[i + 1] == '=')
        {
          ++i;
          identifier += data[i];
          newToken.setType(TokenType::tok_equals);
          newToken.setTokenString(identifier);
        }
        else
        {
          newToken.setType(TokenType::tok_assign);
          newToken.setTokenString(identifier);
        }
      }
      else if (data[i] == '!')
      {
        if (data[i + 1] == '=')
        {
          ++i;
          identifier += data[i];
          newToken.setType(TokenType::tok_not_equals);
          newToken.setTokenString(identifier);
        }
        else
        {
          newToken.setType(TokenType::tok_logical_not);
          newToken.setTokenString(identifier);
        }
      }
      else if (data[i] == ';')
      {
        newToken.setType(TokenType::tok_semi_colon);
        newToken.setTokenString(identifier);
      }
      else if (data[i] == ':')
      {
        newToken.setType(TokenType::tok_colon);
        newToken.setTokenString(identifier);
      }
      tokens.push_back(newToken);
    }
  }

  return tokens;
}

bool Lexer::isspec(char c)
{
  if (c == '[' || c == ']' || c == '{' || c == '}' || c == '(' || c == ')'
   || c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '.' || c == '='
   || c == '|' || c == ',' || c == ':' || c == '\?' || c == '!' || c == ';'
   || c == '<' || c == '>' || c == '^' || c == '&' || c == '~'
   || c == '\'' || c == '\"')
  {
    return true;
  }
  return false;
}
#include "Parser.hpp"

#include "AST.hpp"

#include <memory>

Parser::Parser()
{
  // Assignment
  this->binopPrecedence["="]   = 1;
  this->binopPrecedence["-="]  = 1;
  this->binopPrecedence["+="]  = 1;
  this->binopPrecedence["/="]  = 1;
  this->binopPrecedence["%="]  = 1;
  this->binopPrecedence["*="]  = 1;
  this->binopPrecedence["^="]  = 1; // XOR ASSIGNMENT
  this->binopPrecedence["|="]  = 1; // OR ASSIGNMENT
  this->binopPrecedence["&="]  = 1; // AND ASSIGNMENT
  this->binopPrecedence["<<="] = 1; // SHIFT LEFT ASSIGNMENT
  this->binopPrecedence[">>="] = 1; // SHIFT RIGHT ASSIGNMENT
  
  // Comparison
  this->binopPrecedence["=="] = 1;
  this->binopPrecedence["!="] = 1;
  this->binopPrecedence["<"]  = 1;
  this->binopPrecedence[">"]  = 1;
  this->binopPrecedence["<="] = 1;
  this->binopPrecedence[">="] = 1;

  // Arithmetic
  this->binopPrecedence["-"] = 10;
  this->binopPrecedence["+"] = 10;
  this->binopPrecedence["/"] = 20;
  this->binopPrecedence["%"] = 20;
  this->binopPrecedence["*"] = 20;

  // Logical
  this->binopPrecedence["||"] = 20; // OR
  this->binopPrecedence["&&"] = 20; // AND
  this->binopPrecedence["^^"] = 20; // XOR
  
  // Bitwise
  this->binopPrecedence["^"]  = 20; // XOR
  this->binopPrecedence["|"]  = 20; // OR
  this->binopPrecedence["&"]  = 20; // AND
  this->binopPrecedence["<<"] = 20; // SHIFT LEFT
  this->binopPrecedence[">>"] = 20; // SHIFT RIGHT
}

//
// MAIN PARSING LOOPS/CONTROL
//
void Parser::parse()
{
  while (true)
  {
    switch (this->tokens[this->currTokenIndex].getType())
    {
      // SKIP THESE
      case TokenType::tok_semi_colon:
        this->currTokenIndex += 1;
        break;
      case TokenType::tok_eof:
        return;
      case TokenType::tok_error:
        return;
      default:
        break;
    }
  }
}
std::unique_ptr<ExprAST> Parser::parsePrimary()
{
  switch (this->tokens[this->currTokenIndex].getType())
  {
  // LITERALS
    case TokenType::tok_byte_literal:
      return parseByteLiteralExpr();
    case TokenType::tok_bool_literal:
      return parseBoolLiteralExpr();
    case TokenType::tok_char_literal:
      return parseCharLiteralExpr();
    case TokenType::tok_uchar_literal:
      return parseUCharLiteralExpr();
    case TokenType::tok_string_literal:
      return parseStringLiteralExpr();
    case TokenType::tok_int_literal:
      return parseIntLiteralExpr();
    case TokenType::tok_uint_literal:
      return parseUIntLiteralExpr();
    case TokenType::tok_short_literal:
      return parseShortLiteralExpr();
    case TokenType::tok_ushort_literal:
      return parseUShortLiteralExpr();
    case TokenType::tok_long_literal:
      return parseLongLiteralExpr();
    case TokenType::tok_ulong_literal:
      return parseULongLiteralExpr();
    case TokenType::tok_long_long_literal:
      return parseLongLongLiteralExpr();
    case TokenType::tok_ulong_long_literal:
      return parseULongLongLiteralExpr();
    case TokenType::tok_float_literal:
      return parseFloatLiteralExpr();
    case TokenType::tok_double_literal:
      return parseDoubleLiteralExpr();

  // DATA TYPE KEYWORDS
    case TokenType::tok_byte:
    case TokenType::tok_bool:
    case TokenType::tok_char:
    case TokenType::tok_uchar:
    case TokenType::tok_char16:
    case TokenType::tok_uchar16:
    case TokenType::tok_char32:
    case TokenType::tok_uchar32:
    case TokenType::tok_string:
    case TokenType::tok_int:
    case TokenType::tok_uint:
    case TokenType::tok_short:
    case TokenType::tok_ushort:
    case TokenType::tok_long:
    case TokenType::tok_ulong:
    case TokenType::tok_float:
    case TokenType::tok_double:
      return parseVariableExpr();

    case TokenType::tok_identifier:
      return parseIdentifierExpr();
    case TokenType::tok_lparen:
      return parseParenExpr();
    default:
      return this->logError("Unknown token when expecting an expression.");
  }
}

//
// RECURSIVE PARSE EXPR
//
std::unique_ptr<ExprAST> Parser::parseExpr()
{
  std::unique_ptr<ExprAST> LHS = this->parsePrimary();
  if (!LHS)
  {
    return nullptr;
  }
  return parseBinOpRHS(0, std::move(LHS));
}

//
// PARSE LITERAL EXPRESSIONS
//
std::unique_ptr<ExprAST> Parser::parseByteLiteralExpr()
{
  std::unique_ptr<LiteralExprAST<unsigned char>> result = std::make_unique<LiteralExprAST<unsigned char>>(tokens[this->currTokenIndex].getTokenByte(), DataType::type_byte);
  this->currTokenIndex += 1;
  return result;
}
std::unique_ptr<ExprAST> Parser::parseBoolLiteralExpr()
{
  std::unique_ptr<LiteralExprAST<bool>> result = std::make_unique<LiteralExprAST<bool>>(tokens[this->currTokenIndex].getTokenBool(), DataType::type_bool);
  this->currTokenIndex += 1;
  return result;
}
std::unique_ptr<ExprAST> Parser::parseCharLiteralExpr()
{
  std::unique_ptr<LiteralExprAST<signed char>> result = std::make_unique<LiteralExprAST<signed char>>(tokens[this->currTokenIndex].getTokenChar(), DataType::type_char);
  this->currTokenIndex += 1;
  return result;
}
std::unique_ptr<ExprAST> Parser::parseUCharLiteralExpr()
{
  std::unique_ptr<LiteralExprAST<unsigned char>> result = std::make_unique<LiteralExprAST<unsigned char>>(tokens[this->currTokenIndex].getTokenUChar(), DataType::type_uchar);
  this->currTokenIndex += 1;
  return result;
}
std::unique_ptr<ExprAST> Parser::parseChar8LiteralExpr()
{
  std::unique_ptr<LiteralExprAST<char8_t>> result = std::make_unique<LiteralExprAST<char8_t>>(tokens[this->currTokenIndex].getTokenChar(), DataType::type_char8);
  this->currTokenIndex += 1;
  return result;
}
std::unique_ptr<ExprAST> Parser::parseChar16LiteralExpr()
{
  std::unique_ptr<LiteralExprAST<char16_t>> result = std::make_unique<LiteralExprAST<char16_t>>(tokens[this->currTokenIndex].getTokenChar(), DataType::type_char16);
  this->currTokenIndex += 1;
  return result;
}
std::unique_ptr<ExprAST> Parser::parseChar32LiteralExpr()
{
  std::unique_ptr<LiteralExprAST<char32_t>> result = std::make_unique<LiteralExprAST<char32_t>>(tokens[this->currTokenIndex].getTokenChar(), DataType::type_char32);
  this->currTokenIndex += 1;
  return result;
}
std::unique_ptr<ExprAST> Parser::parseStringLiteralExpr()
{
  std::unique_ptr<LiteralExprAST<std::string>> result = std::make_unique<LiteralExprAST<std::string>>(tokens[this->currTokenIndex].getTokenString(), DataType::type_string);
  this->currTokenIndex += 1;
  return result;
}
std::unique_ptr<ExprAST> Parser::parseString8LiteralExpr()
{
  std::unique_ptr<LiteralExprAST<std::u8string>> result = std::make_unique<LiteralExprAST<std::u8string>>(tokens[this->currTokenIndex].getTokenString(), DataType::type_string8);
  this->currTokenIndex += 1;
  return result;
}
std::unique_ptr<ExprAST> Parser::parseString16LiteralExpr()
{
  std::unique_ptr<LiteralExprAST<std::u16string>> result = std::make_unique<LiteralExprAST<std::u16string>>(tokens[this->currTokenIndex].getTokenString(), DataType::type_string16);
  this->currTokenIndex += 1;
  return result;
}
std::unique_ptr<ExprAST> Parser::parseString32LiteralExpr()
{
  std::unique_ptr<LiteralExprAST<std::u32string>> result = std::make_unique<LiteralExprAST<std::u32string>>(tokens[this->currTokenIndex].getTokenString(), DataType::type_string32);
  this->currTokenIndex += 1;
  return result;
}
std::unique_ptr<ExprAST> Parser::parseIntLiteralExpr()
{
  std::unique_ptr<LiteralExprAST<int>> result = std::make_unique<LiteralExprAST<int>>(tokens[this->currTokenIndex].getTokenInt(), DataType::type_int);
  this->currTokenIndex += 1;
  return result;
}
std::unique_ptr<ExprAST> Parser::parseUIntLiteralExpr()
{
  std::unique_ptr<LiteralExprAST<unsigned int>> result = std::make_unique<LiteralExprAST<unsigned int>>(tokens[this->currTokenIndex].getTokenUInt(), DataType::type_uint);
  this->currTokenIndex += 1;
  return result;
}
std::unique_ptr<ExprAST> Parser::parseShortLiteralExpr()
{
  std::unique_ptr<LiteralExprAST<short>> result = std::make_unique<LiteralExprAST<short>>(tokens[this->currTokenIndex].getTokenShort(), DataType::type_short);
  this->currTokenIndex += 1;
  return result;
}
std::unique_ptr<ExprAST> Parser::parseUShortLiteralExpr()
{
  std::unique_ptr<LiteralExprAST<unsigned short>> result = std::make_unique<LiteralExprAST<unsigned short>>(tokens[this->currTokenIndex].getTokenUShort(), DataType::type_ushort);
  this->currTokenIndex += 1;
  return result;
}
std::unique_ptr<ExprAST> Parser::parseLongLiteralExpr()
{
  std::unique_ptr<LiteralExprAST<long>> result = std::make_unique<LiteralExprAST<long>>(tokens[this->currTokenIndex].getTokenLong(), DataType::type_long);
  this->currTokenIndex += 1;
  return result;
}
std::unique_ptr<ExprAST> Parser::parseULongLiteralExpr()
{
  std::unique_ptr<LiteralExprAST<unsigned long>> result = std::make_unique<LiteralExprAST<unsigned long>>(tokens[this->currTokenIndex].getTokenULong(), DataType::type_ulong);
  this->currTokenIndex += 1;
  return result;
}
std::unique_ptr<ExprAST> Parser::parseLongLongLiteralExpr()
{
  std::unique_ptr<LiteralExprAST<long long>> result = std::make_unique<LiteralExprAST<long long>>(tokens[this->currTokenIndex].getTokenLongLong(), DataType::type_long_long);
  this->currTokenIndex += 1;
  return result;
}
std::unique_ptr<ExprAST> Parser::parseULongLongLiteralExpr()
{
  std::unique_ptr<LiteralExprAST<unsigned long long>> result = std::make_unique<LiteralExprAST<unsigned long long>>(tokens[this->currTokenIndex].getTokenULongLong(), DataType::type_ulong_long);
  this->currTokenIndex += 1;
  return result;
}
std::unique_ptr<ExprAST> Parser::parseFloatLiteralExpr()
{
  std::unique_ptr<LiteralExprAST<float>> result = std::make_unique<LiteralExprAST<float>>(tokens[this->currTokenIndex].getTokenFloat(), DataType::type_float);
  this->currTokenIndex += 1;
  return result;
}
std::unique_ptr<ExprAST> Parser::parseDoubleLiteralExpr()
{
  std::unique_ptr<LiteralExprAST<double>> result = std::make_unique<LiteralExprAST<double>>(tokens[this->currTokenIndex].getTokenDouble(), DataType::type_double);
  this->currTokenIndex += 1;
  return result;
}
std::unique_ptr<ExprAST> Parser::parseLongDoubleLiteralExpr()
{
  std::unique_ptr<LiteralExprAST<long double>> result = std::make_unique<LiteralExprAST<long double>>(tokens[this->currTokenIndex].getTokenLongDouble(), DataType::type_long_double);
  this->currTokenIndex += 1;
  return result;
}

//
// PARSE VARIABLE FUNCTION CALLS/VARIABLE DECLARATIONS/EXPLICIT CASTS
//
std::unique_ptr<ExprAST> Parser::parseParenExpr()
{
  this->currTokenIndex += 1;
  std::unique_ptr<ExprAST> v = parseExpr();
  if (!v)
  {
    return nullptr;
  }

  if (this->tokens[this->currTokenIndex].getTokenString()[0] != ')')
  {
    this->logError("expected ')'");
  }

  this->currTokenIndex += 1;
  return v;
}
std::unique_ptr<ExprAST> Parser::parseVariableExpr() 
{
  std::unique_ptr<VariableExprAST> result;
  DataType dataType;
  std::string name;
  switch (this->tokens[this->currTokenIndex].getType())
  {
    case TokenType::tok_bool:
      dataType = DataType::type_bool;
    case TokenType::tok_byte:
      dataType = DataType::type_byte;
    case TokenType::tok_char:
      dataType = DataType::type_char;
    case TokenType::tok_uchar:
      dataType = DataType::type_uchar;
    case TokenType::tok_char8:
      dataType = DataType::type_char8;
    case TokenType::tok_char16:
      dataType = DataType::type_char16;
    case TokenType::tok_char32:
      dataType = DataType::type_char32;
    case TokenType::tok_string:
      dataType = DataType::type_string;
    case TokenType::tok_string8:
      dataType = DataType::type_string8;
    case TokenType::tok_string16:
      dataType = DataType::type_string16;
    case TokenType::tok_string32:
      dataType = DataType::type_string32;
    case TokenType::tok_int:
      dataType = DataType::type_int;
    case TokenType::tok_uint:
      dataType = DataType::type_uint;
    case TokenType::tok_short:
      dataType = DataType::type_short;
    case TokenType::tok_ushort:
      dataType = DataType::type_ushort;
  // Look ahead in the case of long and ulong
    case TokenType::tok_long:
      if (this->tokens[this->currTokenIndex + 1].getType() == TokenType::tok_long)
      {
        this->currTokenIndex += 1;
        dataType = DataType::type_long_long;
      }
      else if (this->tokens[this->currTokenIndex + 1].getType() == TokenType::tok_double)
      {
        this->currTokenIndex += 1;
        dataType = DataType::type_long_double;
      }
      else
      {
        dataType = DataType::type_long;
      }
    case TokenType::tok_ulong:
      if (this->tokens[this->currTokenIndex + 1].getType() == TokenType::tok_long)
      {
        this->currTokenIndex += 1;
        dataType = DataType::type_ulong_long;
      }
      else
      {
        dataType = DataType::type_ulong;
      }
    case TokenType::tok_float:
      dataType = DataType::type_float;
    case TokenType::tok_double:
      dataType = DataType::type_double;
  }

  this->currTokenIndex += 1;
  std::unique_ptr<ExprAST> v = this->parseIdentifierExpr();
  if (v)
  {
    result = std::make_unique<VariableExprAST>(this->tokens[this->currTokenIndex].getTokenString(), dataType);
  }
  else
  {
    result = std::make_unique<VariableExprAST>(dataType);
  }

  return result;
}
std::unique_ptr<ExprAST> Parser::parseIdentifierExpr()
{
  std::string idName = this->tokens[this->currTokenIndex].getTokenString();
  this->currTokenIndex += 1;
  
  // If its just a variable
  if (this->tokens[this->currTokenIndex].getType() != TokenType::tok_lparen)
  {
    return std::make_unique<VariableExprAST>(idName);
  }

  this->currTokenIndex += 1;
  // If its a function call
  std::vector<std::unique_ptr<ExprAST>> args;
  if (this->tokens[this->currTokenIndex].getType() != TokenType::tok_rparen)
  {
    while (true)
    {
      std::unique_ptr<ExprAST> arg = this->parseExpr();
      if (arg)
      {
        args.push_back(std::move(arg));
      }
      else
      {
        return nullptr;
      }

      if (this->tokens[this->currTokenIndex].getType() == TokenType::tok_rparen)
      {
        break;
      }

      if (this->tokens[this->currTokenIndex].getType() != TokenType::tok_comma)
      {
        this->logError("Expected ')' or ',' in argument list");
      }
      this->currTokenIndex += 1;
    }
  }
  this->currTokenIndex += 1;
  return std::make_unique<FunctionCallExprAST>(idName, std::move(args));
}

//
// PARSE UNARY/BINARY OPERATORS
//
std::unique_ptr<ExprAST> Parser::parseUnaryOp()
{
  return nullptr;
}
std::unique_ptr<ExprAST> Parser::parseBinOpRHS(int _precedence, std::unique_ptr<ExprAST> _LHS)
{
  while (true)
  {
    int tokPrec = this->getOpPrecendence(this->tokens[this->currTokenIndex].getTokenString());
    if (tokPrec < _precedence)
    {
      return _LHS;
    }

    Token token = this->tokens[this->currTokenIndex];
    this->currTokenIndex += 1;

    std::unique_ptr<ExprAST> RHS = parsePrimary();
    if (!RHS)
    {
      return nullptr;
    }

    int nextPrec = this->getOpPrecendence(this->tokens[this->currTokenIndex].getTokenString());
    if (tokPrec < nextPrec)
    {
      RHS = this->parseBinOpRHS(tokPrec + 1, std::move(RHS));
      if (!RHS)
      {
        return nullptr;
      }
    }

    _LHS = std::make_unique<BinaryExprAST>(token.getTokenString(), std::move(_LHS), std::move(RHS));
  }
}

//
// PARSE FUNCTION PROTOTYPES/DEFINITIONS
//
std::unique_ptr<ExprAST> Parser::parseFunctionPrototype()
{
  if (this->tokens[this->currTokenIndex].getType() != TokenType::tok_identifier)
  {
    return this->logError("Expected function name in prototype.");
  }
  std::string name = this->tokens[this->currTokenIndex].getTokenString();
  this->currTokenIndex += 1;

  if (this->tokens[this->currTokenIndex].getType() != TokenType::tok_lparen)
  {
    return this->logError("Expected '(' in prototype.");
  }
  this->currTokenIndex += 1;

  std::vector<std::string> args;
  while (true)
  {
    if (this->tokens[this->currTokenIndex].getType() == TokenType::tok_identifier)
    {
      args.push_back(this->tokens[this->currTokenIndex].getTokenString());
    }  

    if (this->tokens[this->currTokenIndex].getType() == TokenType::tok_rparen)
    {
      break;
    }

    if (this->tokens[this->currTokenIndex].getType() != TokenType::tok_comma)
    {
      this->logError("Expected ')' or ',' in argument list");
    }
    this->currTokenIndex += 1;
  }
  this->currTokenIndex += 1;

  return std::make_unique<FunctionPrototypeExprAST>(name, std::move(args));
}
std::unique_ptr<ExprAST> Parser::parseFunctionDefinition()
{

  return nullptr;
}

//
//
//
std::unique_ptr<ExprAST> Parser::parseClassDefinition()
{

  return nullptr;
}
std::unique_ptr<ExprAST> Parser::parseEnumDefinition()
{

  return nullptr;
}
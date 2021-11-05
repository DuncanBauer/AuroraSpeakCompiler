#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include <map>

#include "Lexer.hpp"

class ExprAST;

class Parser
{
  public:
    Parser();

    void parse();
    std::unique_ptr<ExprAST> parseExpr();
    std::unique_ptr<ExprAST> parsePrimary();

    // Parses literal expressions
    std::unique_ptr<ExprAST> parseByteLiteralExpr();
    std::unique_ptr<ExprAST> parseBoolLiteralExpr();
    std::unique_ptr<ExprAST> parseCharLiteralExpr();
    std::unique_ptr<ExprAST> parseUCharLiteralExpr();
    std::unique_ptr<ExprAST> parseChar8LiteralExpr();
    std::unique_ptr<ExprAST> parseChar16LiteralExpr();
    std::unique_ptr<ExprAST> parseChar32LiteralExpr();
    std::unique_ptr<ExprAST> parseStringLiteralExpr();
    std::unique_ptr<ExprAST> parseString8LiteralExpr();
    std::unique_ptr<ExprAST> parseString16LiteralExpr();
    std::unique_ptr<ExprAST> parseString32LiteralExpr();
    std::unique_ptr<ExprAST> parseIntLiteralExpr();
    std::unique_ptr<ExprAST> parseUIntLiteralExpr();
    std::unique_ptr<ExprAST> parseShortLiteralExpr();
    std::unique_ptr<ExprAST> parseUShortLiteralExpr();
    std::unique_ptr<ExprAST> parseLongLiteralExpr();
    std::unique_ptr<ExprAST> parseULongLiteralExpr();
    std::unique_ptr<ExprAST> parseLongLongLiteralExpr();
    std::unique_ptr<ExprAST> parseULongLongLiteralExpr();
    std::unique_ptr<ExprAST> parseFloatLiteralExpr();
    std::unique_ptr<ExprAST> parseDoubleLiteralExpr();
    std::unique_ptr<ExprAST> parseLongDoubleLiteralExpr();

    // Parses data type keyword expressions
    std::unique_ptr<ExprAST> parseVariableExpr();
    
    std::unique_ptr<ExprAST> parseParenExpr();
    std::unique_ptr<ExprAST> parseIdentifierExpr();
    std::unique_ptr<ExprAST> parseUnaryOp();
    std::unique_ptr<ExprAST> parseBinOpRHS(int _precedence, std::unique_ptr<ExprAST> _LHS);
    std::unique_ptr<ExprAST> parseFunctionPrototype();
    std::unique_ptr<ExprAST> parseFunctionDefinition();
    std::unique_ptr<ExprAST> parseClassDefinition();
    std::unique_ptr<ExprAST> parseEnumDefinition();

    inline std::unique_ptr<ExprAST> logError(const char* _str) 
    { 
      std::cout << _str << '\n';
      return nullptr;
    }
    inline size_t getOpPrecendence(std::string _op)
    {
      int prec = 0;
      prec = Parser::binopPrecedence[_op];
      if (prec <= 0)
      {
        return -1;
      }
      else
      {
        return prec;
      }
    }

  private:
    int currTokenIndex = 0;
    std::vector<Token> tokens;
    std::map<std::string, int> binopPrecedence;
};

#endif
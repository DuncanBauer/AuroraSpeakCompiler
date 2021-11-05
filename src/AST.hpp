#ifndef AST_H
#define AST_H

#include <string>
#include <vector>
#include <memory>

enum class DataType
{
  type_bool,
  type_byte,
  type_char,
  type_uchar,
  type_char8,
  type_char16,
  type_char32,
  type_string,
  type_string8,
  type_string16,
  type_string32,
  type_int,
  type_uint,
  type_short,
  type_ushort,
  type_long,
  type_ulong,
  type_long_long,
  type_ulong_long,
  type_float,
  type_double,
  type_long_double,
  type_void
};

class ExprAST
{
  public:
    virtual ~ExprAST() {}
};

//
// Nodes for literals
//
template<typename T>
class LiteralExprAST : public ExprAST
{
public:
  LiteralExprAST(T _val, DataType _type) : val(_val), type(_type) {}

private:
  T val;
  DataType type;
};

//
// Node for defining/referencing variables
//
class VariableExprAST : public ExprAST
{
  public:
    VariableExprAST(const std::string& _name) : name(_name) { this->type = DataType::type_void; }
    VariableExprAST(DataType _type) : type(_type) { this->name = ""; }
    VariableExprAST(const std::string& _name, DataType _type) : name(_name), type(_type) {}

    std::string getName() { return this->name; }

  private:
     std::string name;
     DataType type;
};

//
// Node for unary operators 
//
class UnaryExprAST : public ExprAST
{
  public:
    UnaryExprAST(const std::string& _op) : op(_op) {}

  private:
    std::string op;
    std::unique_ptr<ExprAST> operand;
};

//
// Node for binary operators
//
class BinaryExprAST : public ExprAST
{
  public:
    BinaryExprAST(const std::string& _op, std::unique_ptr<ExprAST> _LHS, std::unique_ptr<ExprAST> _RHS) : op(_op), LHS(std::move(_LHS)), RHS(std::move(_RHS)) {}

  private:
    std::string op;
    std::unique_ptr<ExprAST> LHS,
                             RHS;
};

//
// Node for function calls
//
class FunctionCallExprAST : public ExprAST
{
  public:
    FunctionCallExprAST(const std::string& _callee, std::vector<std::unique_ptr<ExprAST>> _args) : callee(_callee), args(std::move(_args)) {}

  private:
    std::string callee;
    std::vector<std::unique_ptr<ExprAST>> args;
};

//
// Node for function prototypes
//
class FunctionPrototypeExprAST : public ExprAST
{
  public:
    FunctionPrototypeExprAST(const std::string& _name, std::vector<std::string> _args) : name(_name), args(std::move(_args)) {}
    FunctionPrototypeExprAST(const std::string& _name, DataType _returnType, std::vector<std::string> _args) : name(_name), returnType(_returnType), args(std::move(_args)) {}

  private:
    std::string name;
    DataType returnType;
    std::vector<std::string> args;
};

//
// Node for function definitions
//
class FunctionDefinitionExprAST : public ExprAST
{
  public:
    FunctionDefinitionExprAST(std::unique_ptr<FunctionPrototypeExprAST> _proto, std::unique_ptr<ExprAST> _body) : proto(std::move(_proto)), body(std::move(_body)) {}

  private:
    std::unique_ptr<FunctionPrototypeExprAST> proto;
    std::unique_ptr<ExprAST> body;
};

//
// Node for class definitions
//
class ClassDefinitionAST : public ExprAST
{
  public:
    ClassDefinitionAST(const std::string& _name, const std::string& _parent, std::vector<std::unique_ptr<VariableExprAST>> _variable, std::vector<std::unique_ptr<FunctionDefinitionExprAST>> _functions) : name(_name), parent(_parent), variables(std::move(_variable)), functions(std::move(_functions)) {}

  private:
    std::string name;
    std::string parent;
    std::vector<std::unique_ptr<VariableExprAST>> variables;
    std::vector<std::unique_ptr<FunctionDefinitionExprAST>> functions;
};

//
// Node for enum definitions
//
class EnumDefinitionAST : public ExprAST
{
  public:
    EnumDefinitionAST(const std::string& _name, std::vector<std::unique_ptr<VariableExprAST>> _values) : name(_name), values(std::move(_values)) {}

  private:
    std::string name;
    std::vector<std::unique_ptr<VariableExprAST>> values;
};

#endif
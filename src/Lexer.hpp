#ifndef LEXER_H
#define LEXER_H

#include <vector>
#include <string>

enum class TokenType
{
  // DATA TYPES
  tok_bool,// = 0
  tok_byte,// = 1
  tok_char,// = 2
  tok_uchar,// = 3
  tok_char8,// = 4
  tok_char16,// = 4
  tok_char32,// = 6
  tok_string,// = 8
  tok_string8,// = 8
  tok_string16,// = 8
  tok_string32,// = 8
  tok_int,// = 9
  tok_uint,// = 10
  tok_short,// = 11
  tok_ushort,// = 12
  tok_long,// = 13
  tok_ulong,// = 15
  tok_float,// = 17
  tok_double,// = 18

  // OPERATORS
  // ASSIGNMENT OPERATORS
  tok_assign,
  tok_increment,
  tok_decrement,
  tok_minus_assign,
  tok_plus_assign,
  tok_divide_assign,
  tok_modulo_assign,
  tok_multiply_assign,
  tok_bitwise_xor_assign,
  tok_bitwise_or_assign,
  tok_bitwise_and_assign,
  tok_bitwise_shift_left_assign,
  tok_bitwise_shift_right_assign,

  // ARITHMETIC OPERATORS
  tok_minus,
  tok_plus,
  tok_divide,
  tok_modulo,
  tok_multiply,

  // BITWISE OPERATORS
  tok_bitwise_not,
  tok_bitwise_xor,
  tok_bitwise_or,
  tok_bitwise_and,
  tok_bitwise_shift_left,
  tok_bitwise_shift_right,

  // COMPARISON OPERATORS
  tok_equals,
  tok_not_equals,
  tok_less_than,
  tok_greater_than,
  tok_less_than_equals,
  tok_greater_than_equals,

  // LOGICAL OPERATORS
  tok_logical_not,
  tok_logical_or,
  tok_logical_xor,
  tok_logical_and,

  // FLOW CONTROL TOKENS
  tok_if,
  tok_else,
  tok_switch,
  tok_case,
  tok_default,
  tok_for,
  tok_while,
  tok_do,
  tok_break,
  tok_continue,
  tok_return,

  // SPECIAL OPERATORS
  tok_lparen,
  tok_rparen,
  tok_lbracket,
  tok_rbracket,
  tok_lbrace,
  tok_rbrace,
  tok_period,
  tok_comma,
  tok_colon,
  tok_semi_colon,
  tok_quote,
  tok_single_quote,

// VALUES TOKENS
  tok_null,
  tok_this,

// DEPENDENCY TOKENS
  tok_import,
  tok_export,

// EXCEPTION TOKENS
  tok_try,
  tok_catch,
  tok_finally,
  tok_throw,

// LITERALS
  tok_bool_literal, // true AND false keywords
  tok_byte_literal,
  tok_char_literal,
  tok_uchar_literal,
  tok_char8_literal,
  tok_char16_literal,
  tok_char32_literal,
  tok_string_literal,
  tok_string8_literal,
  tok_string16_literal,
  tok_string32_literal,
  tok_int_literal,
  tok_uint_literal,
  tok_short_literal,
  tok_ushort_literal,
  tok_long_literal,
  tok_ulong_literal,
  tok_long_long_literal,
  tok_ulong_long_literal,
  tok_float_literal,
  tok_double_literal,
  tok_long_double_literal,

// OTHERS
  tok_const,
  tok_static,
  tok_void,
  tok_function,
  tok_class,
  tok_public,
  tok_private,
  tok_enum,
  tok_identifier,
  tok_in,
  tok_eof,
  tok_error,
};

class Token
{
  public:
    Token() = default;

    TokenType getType() { return this->type; }
    void setType(TokenType _type) { this->type = _type; }

    bool getTokenBool() { return this->tokenBool; }
    void setTokenBool(bool _val) { this->tokenBool = _val; }

    unsigned char getTokenByte() { return this->tokenByte; }
    void setTokenByte(unsigned char _val) { this->tokenByte = _val; }

    char getTokenChar() { return this->tokenChar; }
    void setTokenChar(char _val) { this->tokenChar = _val; }

    unsigned char getTokenUChar() { return this->tokenUChar; }
    void setTokenUChar(unsigned char _val) { this->tokenUChar = _val; }

    char16_t getTokenChar8() { return this->tokenChar8; }
    void setTokenChar8(char _val) { this->tokenChar8 = _val; }

    char16_t getTokenChar16() { return this->tokenChar16; }
    void setTokenChar16(char _val) { this->tokenChar16 = _val; }

    char32_t getTokenChar32() { return this->tokenChar32; }
    void setTokenChar32(char _val) { this->tokenChar32 = _val; }

    std::string getTokenString() { return this->tokenString; }
    void setTokenString(std::string _val) { this->tokenString = _val; }

    std::u8string getTokenString8() { return this->tokenString8; }
    void setTokenString8(std::u8string _val) { this->tokenString8 = _val; }

    std::u16string getTokenString16() { return this->tokenString16; }
    void setTokenString16(std::u16string _val) { this->tokenString16 = _val; }

    std::u32string getTokenString32() { return this->tokenString32; }
    void setTokenString32(std::u32string _val) { this->tokenString32 = _val; }
    
    signed int getTokenInt() { return this->tokenInt; }
    void setTokenInt(signed int _val) { this->tokenInt = _val; }
    
    unsigned int getTokenUInt() { return this->tokenUInt; }
    void setTokenUInt(unsigned int _val) { this->tokenUInt = _val; }
    
    signed short getTokenShort() { return this->tokenShort; }
    void setTokenShort(signed short _val) { this->tokenShort = _val; }
    
    unsigned short getTokenUShort() { return this->tokenUShort; }
    void setTokenUShort(unsigned short _val) { this->tokenUShort = _val; }
    
    signed long getTokenLong() { return this->tokenLong; }
    void setTokenLong(signed long _val) { this->tokenLong = _val; }
    
    unsigned long getTokenULong() { return this->tokenULong; }
    void setTokenULong(unsigned long _val) { this->tokenULong = _val; }
    
    signed long long getTokenLongLong() { return this->tokenLongLong; }
    void setTokenLongLong(signed long long _val) { this->tokenLongLong= _val; }
    
    unsigned long long getTokenULongLong() { return this->tokenULongLong; }
    void setTokenULongLong(unsigned long long _val) { this->tokenULongLong = _val; }
    
    float getTokenFloat() { return this->tokenFloat; }
    void setTokenFloat(float _val) { this->tokenFloat = _val; }
    
    double getTokenDouble() { return this->tokenDouble; }
    void setTokenDouble(double _val) { this->tokenDouble = _val; }

    double getTokenLongDouble() { return this->tokenLongDouble; }
    void setTokenLongDouble(double _val) { this->tokenLongDouble = _val; }

  private:
    TokenType type;
    size_t row;
    size_t column;

    bool tokenBool;
    unsigned char tokenByte;
    char tokenChar;
    unsigned char tokenUChar;
    char16_t tokenChar8;  // Unsigned by default
    char16_t tokenChar16; // Unsigned by default
    char32_t tokenChar32; // Unsigned by default
    std::string tokenString;
    std::u8string tokenString8;
    std::u16string tokenString16;
    std::u32string tokenString32;
    signed int tokenInt;
    unsigned int tokenUInt;
    signed short tokenShort;
    unsigned short tokenUShort;
    signed long tokenLong;
    unsigned long tokenULong;
    signed long long tokenLongLong;
    unsigned long long tokenULongLong;
    float tokenFloat;
    double tokenDouble;
    long double tokenLongDouble;
};

class Lexer
{
  public:
    Lexer() = default;
    
    static std::vector<Token> lex(std::string _file);
    static bool isspec(char c);
};

#endif
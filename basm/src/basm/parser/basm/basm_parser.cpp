#include <exception>
#include "basm/parser/basm/basm_parser.hpp"
#include "basm/lexer/lexer.hpp"

#pragma warning (disable: 4996)

#define THROW_ERROR(message, ...)\
    char* buffer = new char[2048];\
    sprintf(buffer, message, __VA_ARGS__);\
    throw std::exception(buffer);

namespace basm {
    namespace details {
        enum BasmTokenType {
            KEYWORD = 1, PREPROCESSOR, COMMENT, LABEL, REGISTER, VARIABLE,
            SYMBOL, MATH_SIGN, BITWISE_SIGN, DATATYPE,
            STRING, NUMBER
        };

        static lexer::Lexer BASM_LEXER = lexer::Lexer({
            {BasmTokenType::LABEL, "\\@([a-zA-Z_\\.][a-zA-Z0-9_]*)"},
            {BasmTokenType::REGISTER, "\\%([a-zA-Z_][a-zA-Z0-9_]*)"},
            {BasmTokenType::VARIABLE, "\\$([a-zA-Z_][a-zA-Z0-9_]*)"},

            {BasmTokenType::KEYWORD, "(macro|section|global|jump)"},

            {BasmTokenType::PREPROCESSOR, "\\#(include|if|elif|else|end)"},
            {BasmTokenType::COMMENT, "//.+"},

            {BasmTokenType::MATH_SIGN, "(\\+|\\-|\\/|\\*|\\%)"},
            {BasmTokenType::BITWISE_SIGN, "(\\~|\\&|\\||\\^|\\~\\&|\\~\\|)"},
            {BasmTokenType::SYMBOL, "(\\:|\\;|\\{|\\}|\\(|\\)|\\<|\\>)"},

            {BasmTokenType::DATATYPE, "(i8|i16|i32|i64|i128|b1|b2|b4|b8|b16|f16|f32|f64|f128|f256|f512)"},

            {BasmTokenType::STRING, "\".*\""},
            {BasmTokenType::NUMBER, "\\-?[0-9]+"},
        });
    }

    BasmParser::BasmParser(const std::string& source) {
        details::BASM_LEXER.begin(source);
        while (true) {
            lexer::Token tkn = details::BASM_LEXER.next();
            this->_tokens.push_back(tkn);
            if (tkn.type == 0)
                break;
        }
        this->_token = this->_tokens.at(this->_pos);
    }

    void BasmParser::require(const std::string& data) {
        if (this->_token.data != data) {
            THROW_ERROR("Expected token data `%s`, got: `%s`", data.c_str(), this->_token.data.c_str())
        }
    }

    void BasmParser::require(unsigned long type) {
        if (this->_token.type != type) {
            THROW_ERROR("Expected token id `%d`, got: `%d`", type, this->_token.type)
        }
    }

    bool BasmParser::expect(const std::string& data) {
        return this->_token.data == data;
    }

    bool BasmParser::expect(unsigned long type) {
        return this->_token.type == type;
    }

    void BasmParser::advance() {
        this->_pos++;
        if (this->_pos >= this->_tokens.size())
            return;
        this->_prevToken = this->_token;
        this->_token = this->_tokens.at(this->_pos);
    }

    bool BasmParser::advance_if(const std::string& data) {
        if (expect(data)) {
            advance();
            return true;
        }
        return false;
    }

    bool BasmParser::advance_if(unsigned long type) {
        if (expect(type)) {
            advance();
            return true;
        }
        return false;
    }

    void BasmParser::skip_aesthetic_if(const std::string& data) {
        advance_if(data);
    }
}

#undef THROW_ERROR
#pragma warning (default: 4996)
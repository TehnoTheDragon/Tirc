#pragma once
#include <string>
#include <vector>
#include "basm/lexer/token.hpp"
#include "basm_ast.hpp"

namespace basm {
    class BasmParser {
        std::vector<lexer::Token> _tokens;
        lexer::Token _token;
        lexer::Token _prevToken;
        size_t _pos = 0;

        BasmAST* _root = nullptr;
    public:
        BasmParser(const std::string& source);
        BasmAST* parse();

    private:
        void require(const std::string& data);
        void require(unsigned long type);
        bool expect(const std::string& data);
        bool expect(unsigned long type);
        void advance();

        BasmAST* parse_keyword();
    };
}
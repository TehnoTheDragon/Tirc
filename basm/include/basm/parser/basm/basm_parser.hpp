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
    public:
        BasmParser(const std::string& source);
        BAST parse();

    private:
        void require(const std::string& data);
        void require(unsigned long type);
        bool expect(const std::string& data);
        bool expect(unsigned long type);
        void advance();

        bool advance_if(const std::string& data);
        bool advance_if(unsigned long type);
        void skip_aesthetic_if(const std::string& data);
    };
}
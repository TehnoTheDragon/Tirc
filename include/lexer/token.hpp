#pragma once
#include <string>

namespace tirc {
    namespace lexer {
        struct Token {
            size_t position = 0;
            unsigned long type = 0;
            std::string data = "";
        };

        const Token EMPTY_TOKEN = Token{};
    }
}
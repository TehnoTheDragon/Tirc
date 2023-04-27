#include <iostream>
#include "lexer/lexer.hpp"

int main() {
    tirc::lexer::Lexer lexer = tirc::lexer::Lexer({
            {1, "(load)"},
            {2, "[0-9]+"},
        }, "load 10");
    auto x = lexer.next();
    auto y = lexer.next();
    lexer.next();
    return 0;
}
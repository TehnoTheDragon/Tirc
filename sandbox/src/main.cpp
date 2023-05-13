#include <iostream>
#include <basm/parser/basm/basm_parser.hpp>

int main() {
    try {
        basm::BasmParser basmParser(R"(
            @begin: {
                jump @begin
            }
        )");
        basm::BasmAST* root = basmParser.parse();
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
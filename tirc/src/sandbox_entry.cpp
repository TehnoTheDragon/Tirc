#include <iostream>
#include "lexer/lexer.hpp"

int main() {
    tirc::lexer::Lexer lexer = tirc::lexer::Lexer({
        {1, "#.*"},
        {2, "(i1|i8|i16|i32|i64|float|double|void|call|ret|and|or|nand|nor|xor|not|jump)"},
        {3, "(\\$|\\%)[a-zA-Z][a-zA-Z0-9_]*"},
        {4, "\\@[a-zA-Z][a-zA-Z0-9_]*:?"},
        {5, "(\\+|-|\\*|/|%|\\^)"},
        {6, "0x[0-9a-f]+|([0-9])+(\\.[0-9]+)?"},
        {7, "(\\(|\\)|\\<|\\>|\\{|\\})"},
        {8, "(\\:|\\=|\\.|\\,)"}
        }, R"(
@sum_them(i32 $x, i32 $y) : i32 {
    $z : i32 = $x + $y
    ret $z
}

$x : i32 = call @sum_them 5 10
)");
    //std::vector<tirc::lexer::Token> tkns{};
    tirc::lexer::Token tkn = lexer.next();
    while (!tkn.data.empty()){
        std::cout << tkn.data << std::endl;
        tkn = lexer.next();
    }
    system("pause");
    return 0;
}
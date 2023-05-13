#pragma once
#include <vector>

namespace basm {
    enum BasmASTType {
        NONE,
        COMPOUND,

        DEF_SECTION,
        DEF_LABEL,
        DEF_REGISTER,
        DEF_VARIABLE,

        PRE_INCLUDE,
        PRE_IF,
        PRE_ELIF,
        PRE_ELSE,

        VAL_STRING,
        VAL_NUMBER,
    };

    struct BasmAST {
        BasmASTType type = BasmASTType::NONE;

        explicit BasmAST(BasmASTType type) : type(type) {}
    };
}
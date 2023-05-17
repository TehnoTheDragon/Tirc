#pragma once
#include <vector>
#include <string>
#include <memory>
#include <variant>

namespace basm {
    enum class BASTType {
        None,
        Compound,
        Operation,
        Name,
        Value,
    };

    enum class BASTNameType {
        Label,
        Register,
        Varialbe,
    };
    
    enum class BASTValueType {
        String,
        Number,
    };

    struct BASTCompound {
        std::vector<struct BAST*> children;
    };

    struct BASTOperation {
        std::string operation;
        BASTCompound arguments;
    };

    struct BASTName {
        BASTNameType type;
        std::string name;
    };

    struct BASTValue {
        BASTValueType type;
        std::string value;
    };

    struct BAST {
        BASTType type;
        union {
            BASTCompound compound;
            BASTOperation operation;
            BASTName name;
            BASTValue value;
        };
    };
}
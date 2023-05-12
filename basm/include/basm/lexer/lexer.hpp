#pragma once
#include <vector>
#include <regex>
#include "token.hpp"

namespace basm {
    namespace lexer {
        struct LexiconSnapshot {
            const std::string buffer;
            const std::regex regex;
            std::sregex_iterator itr;
            std::sregex_iterator end;

            LexiconSnapshot(const std::regex& regex, const std::string& source = "");
        };

        class Lexer final {
        private:
            const std::vector<std::pair<unsigned long, std::string>> _ruleset;
            LexiconSnapshot* _snapshot = nullptr;
        public:
            Lexer(const std::vector<std::pair<unsigned long, std::string>>& ruleset, const std::string& source);
            ~Lexer();

            Token next();
        };
    }
}
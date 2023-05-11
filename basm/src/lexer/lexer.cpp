#include "lexer/lexer.hpp"

namespace tirc {
    namespace lexer {
        LexiconSnapshot::LexiconSnapshot(const std::regex& regex, const std::string& source) :
            buffer(source),
            regex(regex)
        {
            this->itr = std::sregex_iterator(buffer.begin(), buffer.end(), this->regex);    
            this->end = std::sregex_iterator(buffer.end(), buffer.end(), this->regex);    
        }

        Lexer::Lexer(const std::vector<std::pair<unsigned long, std::string>>& ruleset, const std::string& source) :
            _ruleset(ruleset)
        {
            std::string combinedRules;
            size_t index = 0;
            for (const auto& rule : ruleset) {
                combinedRules += "(";
                combinedRules += rule.second;
                combinedRules += ")";
                if (index++ < ruleset.size() - 1)
                    combinedRules += "|";
            }

            _snapshot = new LexiconSnapshot(std::regex(combinedRules), source);
        }

        Lexer::~Lexer() {}

        Token Lexer::next() {
            if (_snapshot->itr == _snapshot->end)
                return EMPTY_TOKEN;
            
            const std::smatch token = *_snapshot->itr++;
            const std::string data = token.str();
            size_t position = token.position();
            unsigned long tokenType = 0;

            for (const auto& rule : _ruleset) {
                if (std::regex_match(data, std::regex(rule.second))) {
                    tokenType = rule.first;
                    break;
                }
            }

            return Token { position, tokenType, data };
        }
    }
}
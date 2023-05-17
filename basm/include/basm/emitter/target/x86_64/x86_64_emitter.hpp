#pragma once
#include "basm/parser/basm/basm_parser.hpp"
#include "../../emitter.hpp"

namespace basm {
    namespace emitter {
        class x86_64Emitter {
            BAST* _root;
            BAST* _current;
            Emitter _emitter;
        public:
            x86_64Emitter(const std::string& source);

            std::string str() const;
        private:
            void emit(const BAST* node, struct Context& context);
        };
    }
}
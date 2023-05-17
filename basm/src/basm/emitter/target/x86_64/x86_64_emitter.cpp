#include "basm/emitter/target/x86_64/x86_64_emitter.hpp"

namespace basm {
    namespace emitter {
        struct Context {
            bool isArg = false;
        };

        x86_64Emitter::x86_64Emitter(const std::string& source) {
            
        }

        std::string x86_64Emitter::str() const {
            return this->_emitter.str();
        }

        void x86_64Emitter::emit(const BAST* astNode, Context& context) {
        }
    }
}
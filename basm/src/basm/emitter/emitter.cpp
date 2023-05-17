#include "basm/emitter/emitter.hpp"
#include <memory>

namespace basm {
    namespace emitter {
        std::string Emitter::str() const {
            return ss.str();
        }
    }
}
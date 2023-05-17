#pragma once
#include <sstream>

namespace basm {
    namespace emitter {
        class Emitter {
            std::stringstream ss;
        public:
            template <typename T>
            Emitter& operator << (T value) {
                ss << value;
                return *this;
            }

            std::string str() const;
        };
    }
}
#include "NullStream.h"

namespace Serving {
    NullStream::NullStream() : std::ostream(nullptr) {}

    NullStream::NullStream(const NullStream &) : std::ostream(nullptr) {}
}
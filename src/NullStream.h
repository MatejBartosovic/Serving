#ifndef SERVING_NULLSTREAM_H
#define SERVING_NULLSTREAM_H

#include <ostream>

namespace Serving{
    class NullStream : public std::ostream {
    public:
        NullStream();
        NullStream(const NullStream &);
    };
}

#endif //SERVING_NULLSTREAM_H

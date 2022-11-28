#include "LogAndStream.h"
#include <Serving/Mode.h>

namespace serving{
    void Mode::log_error(std::ostream& outStream, const std::string& msg){
        LOG_STREAM_ERROR(outStream, msg)
    }

    void Mode::serve(std::istream& inStream, std::ostream& outStream, std::shared_ptr<policy::Policy> p){
        p->execute(std::bind(&Mode::serve_impl, this, std::ref(inStream), std::ref(outStream), p));
    }
}
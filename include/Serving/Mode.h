#ifndef SERVING_MODE_H
#define SERVING_MODE_H

#include <istream>
#include <ostream>
#include <functional>
#include <Serving/ServingPolicy.h>
#include <memory>

namespace serving{
    class Mode {
    public:
        virtual void serve(std::istream& inStream, std::ostream& outStream, std::shared_ptr<policy::Policy> policy);
    protected:
        virtual void serve_impl(std::istream& inStream, std::ostream& outStream, std::shared_ptr<policy::Policy> policy) = 0;

        void log_error(std::ostream& outStream, const std::string& msg);
    };
}
#endif //SERVING_MODE_H

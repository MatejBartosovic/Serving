#ifndef SERVING_SERVECOMMANDSMODE_H
#define SERVING_SERVECOMMANDSMODE_H

#include <Serving/Mode.h>
#include <unordered_map>
#include <string>
#include <memory>
#include <Serving/Command.h>
#include <functional>

namespace serving{
    class ServeCommandsMode : public Mode{
    public:
        ServeCommandsMode(const std::unordered_map<std::string, std::shared_ptr<Command>>& commands);
    protected:
        void serve_impl(std::istream& inStream, std::ostream& outStream, std::shared_ptr<policy::Policy> policy) override;
    private:
        std::unordered_map<std::string, std::shared_ptr<Command>> commands;
    };
}
#endif //SERVING_SERVECOMMANDSMODE_H

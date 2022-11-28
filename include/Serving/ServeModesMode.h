#ifndef SERVING_SERVEMODESMODE_H
#define SERVING_SERVEMODESMODE_H


#include <Serving/Mode.h>
#include <unordered_map>
#include <string>
#include <memory>
#include <Serving/Command.h>
#include <functional>
#include <Serving/ServeCommandsMode.h>

namespace serving{
    class ServeModesMode : public Mode{
    public:
        ServeModesMode(const std::unordered_map<std::string, std::shared_ptr<Mode>>& modes);
    private:
        void serve_impl(std::istream& inStream, std::ostream& outStream, std::shared_ptr<policy::Policy> policy) override;

        std::unordered_map<std::string, std::shared_ptr<Mode>> modes;
        std::unordered_map<std::string, std::shared_ptr<Command>> commands;
    };
}

#endif //SERVING_SERVEMODESMODE_H

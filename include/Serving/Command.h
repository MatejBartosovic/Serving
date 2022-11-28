#ifndef PERSEUS_COMMAND_H
#define PERSEUS_COMMAND_H
#include <vector>
#include <string>
#include <Serving//Exception.h>
#include <memory>

namespace serving {
    class Command {
    public:
        Command() {}

        virtual std::string
        execute(const std::vector<std::string>::iterator begin, const std::vector<std::string>::iterator end) = 0;
    };

    template <typename T, size_t ArgCount>
    class  EnforceArgCountCommand : public T {
    public:
        using T::T;
        std::string execute(const std::vector<std::string>::iterator begin, const std::vector<std::string>::iterator end) override{
            if (std::distance(begin, end) != ArgCount){
                // todo make this generic
                throw serving::Exception("Command require " + std::to_string(ArgCount) + " arguments. " + std::to_string(std::distance(begin, end)) + " given");
            }
            return T::execute(begin, end);
        }
    };

    template <typename T, size_t ArgCount, typename... Args>
    std::shared_ptr<serving::Command> createCommand(Args... args){
        return std::reinterpret_pointer_cast<serving::Command>(std::make_shared<EnforceArgCountCommand<T, ArgCount>>(std::forward<Args>(args)...));
    }
}

#endif //PERSEUS_COMMAND_H

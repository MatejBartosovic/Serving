#ifndef SERVING_COMMONCOMMANDS_H
#define SERVING_COMMONCOMMANDS_H
#include <vector>
#include <string>
#include <Serving/Command.h>

namespace serving {
    class Mode;
    //todo shared pointer
    using ModePtr = Mode*;
    class Exit : public Command {
    public:
        std::string
        execute(const std::vector<std::string>::iterator begin, const std::vector<std::string>::iterator end) override;
    };

    class Sleep : public Command {
    public:
        std::string
        execute(const std::vector<std::string>::iterator begin, const std::vector<std::string>::iterator end) override;
    };

    class RunFile : public serving::Command{
    public:
        RunFile(ModePtr mode);
        std::string
        execute(const std::vector<std::string>::iterator begin, const std::vector<std::string>::iterator end) override;
    private:
        ModePtr mode;
    };
}

#endif //SERVING_COMMONCOMMANDS_H

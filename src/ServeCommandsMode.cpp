#include <Serving/ServeCommandsMode.h>
#include <Serving/Exception.h>
#include <string>
#include "SplitString.h"
#include "LogAndStream.h"
#include <CommonCommands.h>
#include <iostream>

namespace serving {
    ServeCommandsMode::ServeCommandsMode(const std::unordered_map<std::string, std::shared_ptr<Command>> &commands)
            : commands(commands) {
        this->commands.insert({"exit", createCommand<Exit, 0>()});
        this->commands.insert({"sleep", createCommand<Sleep, 1>()});
        this->commands.insert({"run", createCommand<RunFile, 1>(this)});
    }

    void ServeCommandsMode::serve_impl(std::istream& inStream, std::ostream &outStream, std::shared_ptr<policy::Policy> policy) {
        std::string line;
        while ((bool)std::getline(inStream, line)){
            std::vector<std::string> splited = Serving::split(line, " ");
            auto command = splited.begin();
            auto args = std::next(splited.begin(), 1);
            if(command == splited.end()){
                LOG_STREAM(outStream, "Empty command");
                continue;
            }
            LOG_STREAM(outStream, "Executing command: " + line);
            std::shared_ptr<Command> c;
            try{
                c = commands.at(*command);
            } catch (const std::out_of_range& e){
                throw UnknownCommand();
            }
            std::string ret = c->execute(args, splited.end());
            if (!ret.empty()){
                LOG_STREAM(outStream, "Command finishhed with message: " + ret);
            }
            LOG_STREAM(outStream, "Command '" + line + "' finished successfully");
        }
        LOG_STREAM(std::cout, "End of file. Terminating...");
    }
}
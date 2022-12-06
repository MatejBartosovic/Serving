#include <Serving/ServeModesMode.h>
#include <Serving/Exception.h>
#include <string>
#include "SplitString.h"
#include "LogAndStream.h"
#include <Serving/ServingPolicy.h>
#include "CommonCommands.h"
#include <iostream>


namespace serving {

    ServeModesMode::ServeModesMode(const std::unordered_map<std::string, std::shared_ptr<Mode>> &modes)
            : modes(modes) {
        this->commands.insert({"exit", createCommand<Exit, 0>()});
        this->commands.insert({"sleep", createCommand<Sleep, 1>()});
        this->commands.insert({"run", createCommand<RunFile, 1>(this)});
    }

    void ServeModesMode::serve_impl(std::istream& inStream, std::ostream &outStream, std::shared_ptr<policy::Policy> policy) {
        std::string line;
        while ((bool)std::getline(inStream, line)){
            std::vector<std::string> splited = Serving::split(line, " ");
            auto mode = splited.begin();
            try{
                if(mode == splited.end()){
                    LOG_STREAM(outStream, "Empty mode");
                    continue;
                }
                LOG_STREAM(outStream, "Entering mode: " + *mode);
                modes.at(*mode)->serve(inStream, outStream, policy);
            }catch (const StopException& e){
                LOG_STREAM(outStream, "Exiting mode.");
                break;
            }
            catch (const std::out_of_range& e){
                try {
                    //todo what about throws ??
                    this->commands.at(*mode)->execute(std::next(splited.begin()), splited.end());
                }catch (std::out_of_range& e){
                    throw UnknownCommand();
                }
            }
        }
        LOG_STREAM(std::cout, "End of file. Terminating...");
    }
}

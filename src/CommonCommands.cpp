#include "CommonCommands.h"
#include <Serving/Exception.h>
#include <thread>
#include <Serving/Mode.h>
#include <fstream>
#include "NullStream.h"
#include <Serving/ServingPolicy.h>

namespace serving{
    std::string Exit::execute(const std::vector<std::string>::iterator begin, const std::vector<std::string>::iterator end) {
        throw StopException();
        return std::string();
    }
    std::string Sleep::execute(const std::vector<std::string>::iterator begin, const std::vector<std::string>::iterator end) {
        std::this_thread::sleep_for(std::chrono::milliseconds(std::stoi(*begin)));
        return std::string();
    }

    RunFile::RunFile(ModePtr mode) : mode(mode) {}

    std::string
    RunFile::execute(const std::vector<std::string>::iterator begin, const std::vector<std::string>::iterator end) {
        auto fileStream = std::fstream(*begin);
        //todo out stream
        Serving::NullStream nullStream;
        mode->serve(fileStream,nullStream, std::make_shared<policy::Throw>([](std::exception_ptr e){
            try{
                std::rethrow_exception(e);
            } catch (const std::exception& e){
                return std::string(e.what());
            }
        }));
        return std::string();
    }
}

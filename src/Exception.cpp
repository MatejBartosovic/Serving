#include <Serving/Exception.h>

namespace serving {
    Exception::Exception(const std::string &message) : message(message){}

    const char *Exception::what() const noexcept {
        return message.c_str();
    }

    StopException::StopException() : Exception("Exit cmd"){}
    UnknownCommand::UnknownCommand() : Exception("Unknown command"){}
}
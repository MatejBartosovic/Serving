#ifndef PERSEUS_EXCEPTION_H
#define PERSEUS_EXCEPTION_H

#include <string>
namespace serving{
    class Exception : public std::exception {
    public:
        Exception(const std::string &message);
        virtual const char *what() const noexcept override;

    private:
        std::string message;
    };
    class StopException : public Exception{
    public:
        StopException();
    };

    class UnknownCommand : public Exception{
    public:
        UnknownCommand();
    };
}

#endif //PERSEUS_EXCEPTION_H

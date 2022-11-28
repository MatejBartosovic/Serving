#include <Serving/ServeCommandsMode.h>
#include <iostream>
#include <Logger/Logger.h>
#include <Serving/ServingPolicy.h>

class Throw : public serving::Command{
public:
    std::string
    execute(const std::vector<std::string>::iterator begin, const std::vector<std::string>::iterator end) override{
        throw std::runtime_error("Throw");
    }
};

int main(int argc, char * argv[]) {
    Logger::init();
    serving::ServeCommandsMode serveCommandsMode({{"throw", serving::createCommand<Throw, 0>()}});
    serveCommandsMode.serve(std::cin, std::cout, std::make_shared<serving::policy::Continue>([](std::exception_ptr e){
        try{
            std::rethrow_exception(e);
        } catch (const std::exception& e){
            LOG_ERROR(__FILE__, "Exception occurred during execution: " + std::string(e.what()));
        }
    }));

}
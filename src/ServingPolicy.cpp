#include <Serving/ServingPolicy.h>
#include <Serving/Exception.h>
#include <Logger/Logger.h>


namespace serving::policy {
    Policy::Policy(OnException onException) : onException(onException) {}

    void Throw::execute(Callable c) {
        try {
            std::invoke(c);
        } catch (const std::exception &e) {
            try {
                std::invoke(Policy::onException, std::current_exception());
            } catch (const std::exception &e2) {
                LOG_ERROR(__FILE__, "Exception occurred during exception handling: " + std::string(e2.what()));
                LOG_ERROR(__FILE__, "Original exception: " + std::string(e.what()));
            }
            throw;
        }
    }

    Continue::Continue(OnException onException) : Throw(
            [onException](const std::exception_ptr e) { std::invoke(onException, e); }) {}

    void Continue::execute(Callable c) {
        while (true) {
            try {
                Throw::execute(c);
            } catch (StopException &e) {
                break;
            } catch (...) {
                continue;
            }
            break;
        }
    }
}
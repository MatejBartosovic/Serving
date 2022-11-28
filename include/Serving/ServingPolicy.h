#ifndef SERVING_SERVINGPOLICY_H
#define SERVING_SERVINGPOLICY_H
#include <functional>
#include <exception>

namespace serving::policy{

    class Policy {
    public:
        using OnException = std::function<void(std::exception_ptr)>;
        using Callable = std::function<void()>;
        Policy(OnException onException);
        virtual void execute(Callable f) = 0;
    protected:
        OnException onException;
    };

    class  Throw : public Policy{
    public:
        using Policy::Policy;
        void execute(Callable c) override;
    };

    class Continue : public Throw{
    public:
        Continue(OnException onException);
        void execute(Callable c) override;
    };
}
#endif //SERVING_SERVINGPOLICY_H

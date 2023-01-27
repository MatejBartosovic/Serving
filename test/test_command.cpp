#include <gtest/gtest.h>
#include <Serving/Command.h>
//#include <Serving/Serve.h>
//#include <Serving/ServeModesMode.h>
//#include <Serving/ServeCommandsMode.h>
//#include <Serving/ServingPolicy.h>

class CommandOverride : public serving::Command{
public:
    std::string execute(const std::vector<std::string>::iterator begin, const std::vector<std::string>::iterator end) override{
        return std::string();
    }
};

TEST(Command, Override){
    CommandOverride o;
}

class ForwardedArgs : public serving::Command{
public:
    ForwardedArgs(std::string s, double d) : s(s), d(d){

    }
    std::string execute(const std::vector<std::string>::iterator begin, const std::vector<std::string>::iterator end) override{
        return std::string();
    }

    const std::string s;
    const double d;
};

TEST(Command, Create){
    const std::string s = "s";
    const double d = 5.67;
    const auto c = serving::createCommand<ForwardedArgs, 2>(s, d);
    ASSERT_EQ(c->s, s);
    ASSERT_EQ(c->d, d);
}
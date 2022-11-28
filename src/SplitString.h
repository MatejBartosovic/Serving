#ifndef Serving_SPLIT_H
#define Serving_SPLIT_H

#include <vector>
#include <istream>
#include <string>

namespace Serving {
    std::vector<std::string> split(std::istream &stream, std::string delim);

    std::vector<std::string> split(const std::string string, const std::string &delim);
}
#endif //Serving_SPLIT_H

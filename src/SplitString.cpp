#include <Utilities/SplitString.h>
#include <sstream>

namespace Serving {
    std::vector<std::string> split(std::istream &stream, std::string delim) {
        std::vector<std::string> words;
        for (std::string word; stream >> word;) {
            words.push_back(word);
        }
        return words;
    }

    std::vector<std::string> split(const std::string string, const std::string &delim) {
        std::stringstream ss(string);
        return split(ss, delim);
    }
}
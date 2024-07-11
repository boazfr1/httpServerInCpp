#include "routes.h"
#include <regex>


Routes::Routes(const std::string &buffer)
{
    std::regex requestRegex(R"(> (\w+) (/[^ ]*) HTTP/1.1)");
    std::smatch match;

    if (std::regex_search(buffer, match, requestRegex)) {
        if (match.size() >= 3) {
            std::string method = match[1].str();
            std::string path = match[2].str();

            std::cout << "Method: " << method << std::endl;
            std::cout << "Path: " << path << std::endl;
        } else {
            std::cerr << "Invalid match size: " << match.size() << std::endl;
        }
    } else {
        std::cerr << "No match found" << std::endl;
    }
}

Routes::~Routes()
{
}

std::string Routes::getPath() const{
    return path;
};
std::string Routes::getMethod() const {
    return method;
};

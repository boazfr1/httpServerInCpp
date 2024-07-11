#ifndef ROUTES_H
#define ROUTES_H

#include <string>
#include <iostream>

class Routes
{
private:
    std::string path;
    std::string method;
public:
    Routes(const std::string &buffer);
    ~Routes();
    std::string getPath() const;
    std::string getMethod() const;
};

#endif 
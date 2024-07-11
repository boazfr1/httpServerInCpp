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
    Routes(std::string &buffer);
    ~Routes();
    std::string getPath();
    std::string getMethod();
};

#endif 
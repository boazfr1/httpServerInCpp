#include <string>
#include <iostream>


class JSON
{
private:
    std::string buffer;
public:
    JSON(std::string &str);
    ~JSON();
    void stringify();
    void parse();
};


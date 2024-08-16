#pragma once
#include "database.hpp"
#include <iostream>

namespace Model
{
    class HeaderBarMain
    {
    protected:
    std::string addIp(const std::string &ip);
    void removeIp(const std::string &id);

    std::map<std::string, std::vector<std::string>> initData();

public:
    HeaderBarMain(/* args */);
    ~HeaderBarMain();
    };
} // namespace Model

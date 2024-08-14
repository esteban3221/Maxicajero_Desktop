#pragma once
#include "model/login.hpp"
#include "view/login.hpp"
#include "global.hpp"

namespace Controller 
{
    class Login : public View::Login // public Model::Login
    {
    private:
        /* data */
    public:
        Login(/* args */);
        ~Login();
    };
    
} // namespace Controller

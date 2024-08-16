#pragma once
#include "model/login.hpp"
#include "view/login.hpp"
#include "global.hpp"
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

namespace Controller 
{
    class Login : public View::Login // public Model::Login
    {
    private:
        void onPasswdActivate();
        std::string urlBase;
    public:
        Login(/* args */);
        ~Login();
    };
    
} // namespace Controller

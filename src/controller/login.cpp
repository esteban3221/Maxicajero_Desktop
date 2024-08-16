#include "controller/login.hpp"
#include "login.hpp"

namespace Controller
{
    Login::Login(/* args */) : urlBase("http://"+ Global::Var::ipDirection +":44333/sesion/")
    {
        ((Gtk::Entry *)etyPassd)->signal_activate().connect(sigc::mem_fun(*this, &Login::onPasswdActivate));
    }

    Login::~Login()
    {
    }

    void Login::onPasswdActivate()
    {
        
        if (Global::Var::ipDirection.empty())
        {
            Global::Widget::menuShowIP->popup();
            return;
        }
        urlBase.assign("http://"+ Global::Var::ipDirection +":44333/sesion/");

        auto passd = etyPassd->get_text();

        cpr::Response r = cpr::Post(cpr::Url{urlBase + "login"},
                                    cpr::Payload{{"grant_type", "password"},
                                                 {"password", passd}});

        // exitoso
        if (r.status_code == 200)
        {
            auto json_data = nlohmann::json::parse(r.text);
            Global::Var::user = json_data["userName"].get<std::string>();
            Global::Var::token = json_data["access_token"].get<std::string>();
        }
        else if (r.status_code == 401)
        {
            std::cerr << "Error en la solicitud: " << r.status_code << std::endl;
        }
        etyPassd->set_text("");
    }
} // namespace Controller

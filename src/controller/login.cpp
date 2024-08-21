#include "controller/login.hpp"
#include "login.hpp"

namespace Controller
{
    Login::Login(/* args */) : urlBase("http://" + Global::Var::ipDirection + ":44333/sesion/")
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
        urlBase.assign("http://" + Global::Var::ipDirection + ":44333/");

        auto passd = etyPassd->get_text();

        cpr::Response r  = cpr::Post(cpr::Url{urlBase + "sesion/login"},
                                    cpr::Header{
                                        {"Cookie", "session="+ Global::Var::session}},
                                    cpr::Payload{{"grant_type", "password"},
                                                 {"password", passd}});

        
        for (const auto &cookie : r.cookies)
            Global::Var::session = cookie.GetValue();

        r  = cpr::Post(cpr::Url{urlBase + "sesion/login"},
                                    cpr::Header{
                                        {"Cookie", "session="+ Global::Var::session}},
                                    cpr::Payload{{"grant_type", "password"},
                                                 {"password", passd}});

        // exitoso
        if (r.status_code == 200)
        {
            auto json_data = nlohmann::json::parse(r.text);
            Global::Var::user = json_data["userName"].get<std::string>();
            Global::Var::token = json_data["access_token"].get<std::string>();

            etyPassd->add_css_class("entry");

            Global::Widget::lblHeaderBar->set_markup("<b>" + Global::Var::user + "</b>");
            Global::Widget::menuShowIP->set_visible(false);
            Global::Widget::stackMain->set_visible_child("menu");
        }
        else if (r.status_code == 401)
        {
            etyPassd->add_css_class("error");
        }
        std::cout << r.status_code << '\n';
        etyPassd->set_text("");
    }
} // namespace Controller

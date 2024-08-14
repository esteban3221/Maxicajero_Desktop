#include "login.hpp"

namespace View
{
    Login::Login(/* args */)
    {
        auto builder = Gtk::Builder::create_from_string(this->XML);

        this->boxLogin = builder->get_widget<Gtk::Box>("boxLogin");
        this->etyPassd = builder->get_widget<Gtk::PasswordEntry>("etyPassd");
        this->circularPlus = builder->get_widget<Gtk::Button>("circularPlus");

        this->etyPassd->set_show_peek_icon();
        this->etyPassd->property_placeholder_text() = "Escribe la contraseña";
        this->etyPassd->set_size_request(230, -1);

        this->append(*boxLogin);
    }

    Login::~Login()
    {
    }
} // namespace View
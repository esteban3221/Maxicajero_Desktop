#include "login.hpp"


Login::Login(/* args */)
{
    builder->add_from_string(this->XML);

    this->boxLogin = builder->get_widget<Gtk::Box>("boxLogin");

    this->append(*boxLogin);
}

Login::~Login()
{
}
#pragma once
#include <gtkmm.h>

#include "login.hpp"


class main_window : public Gtk::Window
{
private:
    /* data */

    Login login;

public:
    main_window(/* args */);
    ~main_window();
};



#pragma once
#include <gtkmm.h>
#include <memory>

#include "login.hpp"
#include "header_bar.hpp"


class main_window : public Gtk::Window
{
private:
    /* data */
    Login login;
    std::unique_ptr<HeaderBarMain> header = std::make_unique<HeaderBarMain>();

public:
    main_window(/* args */);
    ~main_window();
};



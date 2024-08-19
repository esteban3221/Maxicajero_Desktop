#pragma once
#include <gtkmm.h>
#include <memory>

#include "controller/header_bar.hpp"
#include "controller/login.hpp"
#include "controller/menu/menu.hpp"


class main_window : public Gtk::Window
{
private:
    /* data */
    Gtk::Stack stack;

    Controller::Login login;
    ControllerMenu menu;

    std::unique_ptr<Controller::HeaderBarMain> header = std::make_unique<Controller::HeaderBarMain>();

public:
    main_window(/* args */);
    ~main_window();
};



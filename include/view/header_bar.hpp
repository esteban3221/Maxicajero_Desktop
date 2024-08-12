#pragma once
#include <gtkmm.h>
#include <iostream>
class HeaderBarMain : public Gtk::HeaderBar
{
private:
    Gtk::ToggleButton toggleShowIP;
    Gtk::Popover popOverConfig;

    const char *XML;

    Gtk::Box *boxConfguracionIP;
    
public:
    HeaderBarMain(/* args */);
    ~HeaderBarMain();
};
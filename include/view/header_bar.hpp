#pragma once
#include <gtkmm.h>
#include <iostream>
#include "global.hpp"

namespace View
{
    class HeaderBarMain : public Gtk::HeaderBar
    {
    private:
        Gtk::Popover popOverConfig;
        const char *XML;

    protected:
        Gtk::Box *boxConfguracionIP;
        Gtk::Entry *etyDirectionServidor;
        Gtk::ListBox *listIpSaves;
        Gtk::Label lblHeaderBar;

    public:
        HeaderBarMain(/* args */);
        ~HeaderBarMain();
    };
} // namespace View

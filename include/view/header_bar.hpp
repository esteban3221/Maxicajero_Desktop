#pragma once
#include <gtkmm.h>
#include <iostream>

namespace View
{
    class HeaderBarMain : public Gtk::HeaderBar
    {
    private:
        Gtk::MenuButton menuShowIP;
        Gtk::Popover popOverConfig;

        const char *XML;

    protected:
        Gtk::Box *boxConfguracionIP;
        Gtk::Entry *etyDirectionServidor;
        Gtk::ListBox *listIpSaves;

    public:
        HeaderBarMain(/* args */);
        ~HeaderBarMain();
    };
} // namespace View

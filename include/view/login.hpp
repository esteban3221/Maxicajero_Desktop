#pragma once
#include <gtkmm.h>

namespace View
{
    class Login : public Gtk::Box
    {
    private:
        const char *XML = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                          "<interface>"
                          "<requires lib=\"gtk\" version=\"4.0\"/>"
                          "<object class=\"GtkBox\" id=\"boxLogin\">"
                          "<property name=\"orientation\">1</property>"
                          "<property name=\"margin-bottom\">10</property>"
                          "<property name=\"margin-start\">10</property>"
                          "<property name=\"margin-end\">10</property>"
                          "<property name=\"margin-top\">10</property>"
                          "<child>"
                          "<object class=\"GtkBox\">"
                          "<property name=\"valign\">3</property>"
                          "<property name=\"halign\">3</property>"
                          "<property name=\"orientation\">1</property>"
                          "<property name=\"hexpand\">true</property>"
                          "<property name=\"vexpand\">true</property>"
                          "<child>"
                          "<object class=\"GtkImage\">"
                          "<property name=\"icon-name\">system-users-symbolic</property>"
                          "<property name=\"pixel-size\">150</property>"
                          "</object>"
                          "</child>"
                          "<child>"
                          "<object class=\"GtkBox\">"
                          "<property name=\"spacing\">5</property>"
                          "<property name=\"margin-top\">25</property>"
                          "<child>"
                          "<object class=\"GtkPasswordEntry\" id=\"etyPassd\"></object>"
                          "</child>"
                          "<child>"
                          "<object class=\"GtkButton\" id=\"circularPlus\">"
                          "<property name=\"label\">&gt;</property>"
                          "<property name=\"icon-name\">go-next-symbolic</property>"
                          "<style>"
                          "<class name=\"circular\"/>"
                          "<class name=\"opaque\"/>"
                          "</style>"
                          "</object>"
                          "</child>"
                          "</object>"
                          "</child>"
                          "</object>"
                          "</child>"
                          "<child>"
                          "<object class=\"GtkLabel\">"
                          "<property name=\"label\">MaxiCajero Desktop 1.0</property>"
                          "<property name=\"valign\">2</property>"
                          "<property name=\"halign\">2</property>"
                          "</object>"
                          "</child>"
                          "</object>"
                          "</interface>";

    protected:
        Gtk::Box *boxLogin = nullptr;
        Gtk::PasswordEntry *etyPassd = nullptr;
        Gtk::Button *circularPlus = nullptr;

    public:
        Login(/* args */);
        ~Login();
    };
} // namespace View
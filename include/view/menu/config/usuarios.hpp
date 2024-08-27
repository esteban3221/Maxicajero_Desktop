#pragma once
#include <gtkmm.h>

class ViewUsuarios : public Gtk::Box
{
private:
    const char *XML;
protected:
    Gtk::Box *boxUsuarios;
public:
    ViewUsuarios(/* args */);
    ~ViewUsuarios();
};


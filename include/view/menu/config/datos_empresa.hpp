#pragma once
#include <gtkmm.h>

class ViewDatosEmpresa : public Gtk::Box
{
private:
    const char *XML;
protected:
    Gtk::Box *boxDatosEmpresa;
    Gtk::Entry *data[5];
    Gtk::Button *btnGuardar;
public:
    ViewDatosEmpresa(/* args */);
    ~ViewDatosEmpresa();
};


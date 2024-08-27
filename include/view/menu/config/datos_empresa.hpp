#pragma once
#include <gtkmm.h>

class ViewDatosEmpresa : public Gtk::Box
{
private:
    const char *XML;
protected:
    Gtk::Box *boxDatosEmpresa;
public:
    ViewDatosEmpresa(/* args */);
    ~ViewDatosEmpresa();
};


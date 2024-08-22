#pragma once
#include <gtkmm.h>

class ViewConsultaMovimientos : public Gtk::Box
{
private:
    const char *XML;
    Gtk::Box *boxDetallesOperacion = nullptr;
public:
    ViewConsultaMovimientos(/* args */);
    ~ViewConsultaMovimientos();
};


#pragma once 
#include <gtkmm.h>
#include "global.hpp"
#include "controller/menu/pago.hpp"
#include "controller/menu/consultaEfectivo.hpp"

class ViewMenu : public Gtk::Box
{
private:
    
    const char *XML;
    Gtk::Box *boxMenu = nullptr;

    //=========== Vistas ==========
    ControllerPago pago;
    ControllerConsultaEfectivo efectivo;
protected:
    Gtk::Stack *stackMenu = nullptr;

public:
    ViewMenu();
    ~ViewMenu();
};

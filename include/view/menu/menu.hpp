#pragma once 
#include <gtkmm.h>
#include "global.hpp"
#include "controller/menu/pago.hpp"
#include "controller/menu/venta.hpp"

class ViewMenu : public Gtk::Box
{
private:
    
    const char *XML;
    Gtk::Box *boxMenu = nullptr;

    //=========== Vistas ==========
    ControllerPago pago;
    ControllerVenta venta;
    
protected:
    Gtk::Stack *stackMenu = nullptr;

public:
    ViewMenu();
    ~ViewMenu();
};

#pragma once 
#include <gtkmm.h>
#include "global.hpp"
#include "controller/menu/pago.hpp"
<<<<<<< HEAD
#include "controller/menu/consultaEfectivo.hpp"
=======
#include "controller/menu/venta.hpp"
>>>>>>> 67c5b51daec8c5b4a577e0e3774a39943dd11ee3

class ViewMenu : public Gtk::Box
{
private:
    
    const char *XML;
    Gtk::Box *boxMenu = nullptr;

    //=========== Vistas ==========
    ControllerPago pago;
<<<<<<< HEAD
    ControllerConsultaEfectivo efectivo;
=======
    ControllerVenta venta;
    
>>>>>>> 67c5b51daec8c5b4a577e0e3774a39943dd11ee3
protected:
    Gtk::Stack *stackMenu = nullptr;

public:
    ViewMenu();
    ~ViewMenu();
};

#pragma once 
#include <gtkmm.h>
#include "global.hpp"
#include "controller/menu/pago.hpp"
#include "controller/menu/consultaEfectivo.hpp"
#include "controller/menu/venta.hpp"
#include "controller/menu/consulta_movimientos.hpp"
#include "controller/menu/cambio_manual.hpp"

class ViewMenu : public Gtk::Box
{
private:
    
    const char *XML;
    Gtk::Box *boxMenu = nullptr;

    //=========== Vistas ==========
    ControllerPago pago;
    ControllerConsultaEfectivo efectivo;
    ControllerVenta venta;
    ControllerConsultaMovimientos movimientos;
    ControllerCambioManual cambioM;

protected:
    Gtk::Stack *stackMenu = nullptr;

public:
    ViewMenu();
    ~ViewMenu();
};

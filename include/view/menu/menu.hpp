#pragma once 
#include <gtkmm.h>
#include "global.hpp"
#include "controller/menu/pago.hpp"
#include "controller/menu/consulta_efectivo.hpp"
#include "controller/menu/venta.hpp"
#include "controller/menu/consulta_movimientos.hpp"
#include "controller/menu/cambio_manual.hpp"

#include "view/menu/config/notepadACCESS.hpp"

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

    ViewNotepad configuracion;

protected:
    Gtk::Stack *stackMenu = nullptr;

public:
    ViewMenu();
    ~ViewMenu();
};

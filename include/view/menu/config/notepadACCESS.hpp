#pragma once
#include <gtkmm.h>
#include "controller/menu/config/general.hpp"
#include "controller/menu/config/datos_empresa.hpp"
#include "controller/menu/config/impresoras.hpp"
#include "controller/menu/config/informacion_sistema.hpp"
#include "controller/menu/config/usuarios.hpp"

class ViewNotepad : public Gtk::Notebook
{
private:
    ConrollerGeneral general;
    ControllerInformacionSistema informacionSistema;
    ControllerDatosEmpresa datosEmpresa;
    ControllerImpresoras impresoras;
    ControllerUsuarios usuarios;
public:
    ViewNotepad(/* args */);
    ~ViewNotepad();
};

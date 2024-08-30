#include "view/menu/config/notepadACCESS.hpp"
#include "notepadACCESS.hpp"

ViewNotepad::ViewNotepad(/* args */)
{
    this->append_page(general,"General");
    this->append_page(informacionSistema,"Sistema");
    this->append_page(datosEmpresa,"Datos Empresa");
    this->append_page(impresoras,"Impresora");
    this->append_page(usuarios,"Usuarios");
}

ViewNotepad::~ViewNotepad()
{
}

#include "view/menu/config/usuarios.hpp"

ViewUsuarios::ViewUsuarios(/* args */) : XML("<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                                             "<interface>"
                                             "<requires lib=\"gtk\" version=\"4.0\"/>"
                                             "<object class=\"GtkBox\" id=\"boxUsuarios\">"
                                             "<property name=\"spacing\">10</property>"
                                             "<child>"
                                             "<object class=\"GtkBox\">"
                                             "<property name=\"orientation\">1</property>"
                                             "<child>"
                                             "<object class=\"GtkScrolledWindow\">"
                                             "<property name=\"hexpand\">true</property>"
                                             "<property name=\"vexpand\">true</property>"
                                             "<property name=\"vexpand-set\">true</property>"
                                             "<child>"
                                             "<object class=\"GtkColumnView\" id=\"tree_usuarios\"></object>"
                                             "</child>"
                                             "</object>"
                                             "</child>"
                                             "<child>"
                                             "<object class=\"GtkBox\">"
                                             "<property name=\"margin-top\">5</property>"
                                             "<property name=\"margin-start\">5</property>"
                                             "<property name=\"margin-end\">5</property>"
                                             "<property name=\"margin-bottom\">5</property>"
                                             "<property name=\"spacing\">5</property>"
                                             "<child>"
                                             "<object class=\"GtkButton\" id=\"btnAdd\">"
                                             "<property name=\"icon-name\">list-add-symbolic</property>"
                                             "<style>"
                                             "<class name=\"circular\"/>"
                                             "<class name=\"suggested-action\"/>"
                                             "</style>"
                                             "</object>"
                                             "</child>"
                                             "<child>"
                                             "<object class=\"GtkButton\" id=\"btnEdit\">"
                                             "<property name=\"icon-name\">edit-symbolic</property>"
                                             "<style>"
                                             "<class name=\"circular\"/>"
                                             "<class name=\"warning\"/>"
                                             "</style>"
                                             "</object>"
                                             "</child>"
                                             "<child>"
                                             "<object class=\"GtkButton\" id=\"btnDel\">"
                                             "<property name=\"icon-name\">list-remove-symbolic</property>"
                                             "<style>"
                                             "<class name=\"circular\"/>"
                                             "<class name=\"destructive-action\"/>"
                                             "</style>"
                                             "</object>"
                                             "</child>"
                                             "</object>"
                                             "</child>"
                                             "</object>"
                                             "</child>"
                                             "<child>"
                                             "<object class=\"GtkFrame\">"
                                             "<property name=\"label\">Permisos</property>"
                                             "<child>"
                                             "<object class=\"GtkGrid\">"
                                             "<property name=\"column-homogeneous\">true</property>"
                                             "<child>"
                                             "<object class=\"GtkCheckButton\" id=\"check_rol_1\">"
                                             "<property name=\"label\">Venta</property>"
                                             "<property name=\"halign\">1</property>"
                                             "<property name=\"margin-end\">10</property>"
                                             "<property name=\"margin-start\">10</property>"
                                             "<property name=\"valign\">3</property>"
                                             "<layout>"
                                             "<property name=\"column\">0</property>"
                                             "<property name=\"row\">0</property>"
                                             "</layout>"
                                             "</object>"
                                             "</child>"
                                             "<child>"
                                             "<object class=\"GtkCheckButton\" id=\"check_rol_2\">"
                                             "<property name=\"label\">Pago</property>"
                                             "<property name=\"halign\">1</property>"
                                             "<property name=\"margin-end\">10</property>"
                                             "<property name=\"margin-start\">10</property>"
                                             "<property name=\"valign\">3</property>"
                                             "<layout>"
                                             "<property name=\"column\">0</property>"
                                             "<property name=\"row\">1</property>"
                                             "</layout>"
                                             "</object>"
                                             "</child>"
                                             "<child>"
                                             "<object class=\"GtkCheckButton\" id=\"check_rol_3\">"
                                             "<property name=\"label\">Carga</property>"
                                             "<property name=\"halign\">1</property>"
                                             "<property name=\"margin-end\">10</property>"
                                             "<property name=\"margin-start\">10</property>"
                                             "<property name=\"valign\">3</property>"
                                             "<layout>"
                                             "<property name=\"column\">0</property>"
                                             "<property name=\"row\">2</property>"
                                             "</layout>"
                                             "</object>"
                                             "</child>"
                                             "<child>"
                                             "<object class=\"GtkCheckButton\" id=\"check_rol_4\">"
                                             "<property name=\"label\">Retirada</property>"
                                             "<property name=\"halign\">1</property>"
                                             "<property name=\"margin-end\">10</property>"
                                             "<property name=\"margin-start\">10</property>"
                                             "<property name=\"valign\">3</property>"
                                             "<layout>"
                                             "<property name=\"column\">0</property>"
                                             "<property name=\"row\">3</property>"
                                             "</layout>"
                                             "</object>"
                                             "</child>"
                                             "<child>"
                                             "<object class=\"GtkCheckButton\" id=\"check_rol_5\">"
                                             "<property name=\"label\">Cambio Manual</property>"
                                             "<property name=\"halign\">1</property>"
                                             "<property name=\"margin-end\">10</property>"
                                             "<property name=\"margin-start\">10</property>"
                                             "<property name=\"valign\">3</property>"
                                             "<layout>"
                                             "<property name=\"column\">0</property>"
                                             "<property name=\"row\">4</property>"
                                             "</layout>"
                                             "</object>"
                                             "</child>"
                                             "<child>"
                                             "<object class=\"GtkCheckButton\" id=\"check_rol_6\">"
                                             "<property name=\"label\">Cambio Automatico</property>"
                                             "<property name=\"halign\">1</property>"
                                             "<property name=\"margin-end\">10</property>"
                                             "<property name=\"margin-start\">10</property>"
                                             "<property name=\"valign\">3</property>"
                                             "<layout>"
                                             "<property name=\"column\">0</property>"
                                             "<property name=\"row\">5</property>"
                                             "</layout>"
                                             "</object>"
                                             "</child>"
                                             "<child>"
                                             "<object class=\"GtkCheckButton\" id=\"check_rol_7\">"
                                             "<property name=\"label\">Ingresos</property>"
                                             "<property name=\"halign\">1</property>"
                                             "<property name=\"margin-end\">10</property>"
                                             "<property name=\"margin-start\">10</property>"
                                             "<property name=\"valign\">3</property>"
                                             "<layout>"
                                             "<property name=\"column\">0</property>"
                                             "<property name=\"row\">6</property>"
                                             "</layout>"
                                             "</object>"
                                             "</child>"
                                             "<child>"
                                             "<object class=\"GtkCheckButton\" id=\"check_rol_8\">"
                                             "<property name=\"label\">Enviar a casette</property>"
                                             "<property name=\"halign\">1</property>"
                                             "<property name=\"margin-end\">10</property>"
                                             "<property name=\"margin-start\">10</property>"
                                             "<property name=\"valign\">3</property>"
                                             "<layout>"
                                             "<property name=\"column\">1</property>"
                                             "<property name=\"row\">0</property>"
                                             "</layout>"
                                             "</object>"
                                             "</child>"
                                             "<child>"
                                             "<object class=\"GtkCheckButton\" id=\"check_rol_9\">"
                                             "<property name=\"label\">Retirada Casette</property>"
                                             "<property name=\"halign\">1</property>"
                                             "<property name=\"margin-end\">10</property>"
                                             "<property name=\"margin-start\">10</property>"
                                             "<property name=\"valign\">3</property>"
                                             "<layout>"
                                             "<property name=\"column\">1</property>"
                                             "<property name=\"row\">1</property>"
                                             "</layout>"
                                             "</object>"
                                             "</child>"
                                             "<child>"
                                             "<object class=\"GtkCheckButton\" id=\"check_rol_10\">"
                                             "<property name=\"label\">Consulta de Efectivo</property>"
                                             "<property name=\"halign\">1</property>"
                                             "<property name=\"margin-end\">10</property>"
                                             "<property name=\"margin-start\">10</property>"
                                             "<property name=\"valign\">3</property>"
                                             "<layout>"
                                             "<property name=\"column\">1</property>"
                                             "<property name=\"row\">2</property>"
                                             "</layout>"
                                             "</object>"
                                             "</child>"
                                             "<child>"
                                             "<object class=\"GtkCheckButton\" id=\"check_rol_11\">"
                                             "<property name=\"label\">Mov. Pendientes</property>"
                                             "<property name=\"halign\">1</property>"
                                             "<property name=\"margin-end\">10</property>"
                                             "<property name=\"margin-start\">10</property>"
                                             "<property name=\"valign\">3</property>"
                                             "<layout>"
                                             "<property name=\"column\">1</property>"
                                             "<property name=\"row\">3</property>"
                                             "</layout>"
                                             "</object>"
                                             "</child>"
                                             "<child>"
                                             "<object class=\"GtkCheckButton\" id=\"check_rol_12\">"
                                             "<property name=\"label\">Consulta Movimiento</property>"
                                             "<property name=\"halign\">1</property>"
                                             "<property name=\"margin-end\">10</property>"
                                             "<property name=\"margin-start\">10</property>"
                                             "<property name=\"valign\">3</property>"
                                             "<layout>"
                                             "<property name=\"column\">1</property>"
                                             "<property name=\"row\">4</property>"
                                             "</layout>"
                                             "</object>"
                                             "</child>"
                                             "<child>"
                                             "<object class=\"GtkCheckButton\" id=\"check_rol_13\">"
                                             "<property name=\"label\">Cierre con Faltantes</property>"
                                             "<property name=\"halign\">1</property>"
                                             "<property name=\"margin-end\">10</property>"
                                             "<property name=\"margin-start\">10</property>"
                                             "<property name=\"valign\">3</property>"
                                             "<layout>"
                                             "<property name=\"column\">1</property>"
                                             "<property name=\"row\">5</property>"
                                             "</layout>"
                                             "</object>"
                                             "</child>"
                                             "<child>"
                                             "<object class=\"GtkSeparator\">"
                                             "<layout>"
                                             "<property name=\"column\">0</property>"
                                             "<property name=\"row\">8</property>"
                                             "<property name=\"column-span\">2</property>"
                                             "</layout>"
                                             "</object>"
                                             "</child>"
                                             "<child>"
                                             "<object class=\"GtkCheckButton\" id=\"check_rol_14\">"
                                             "<property name=\"label\">Estadisticas</property>"
                                             "<property name=\"halign\">1</property>"
                                             "<property name=\"margin-end\">10</property>"
                                             "<property name=\"margin-start\">10</property>"
                                             "<property name=\"valign\">3</property>"
                                             "<layout>"
                                             "<property name=\"column\">0</property>"
                                             "<property name=\"row\">9</property>"
                                             "</layout>"
                                             "</object>"
                                             "</child>"
                                             "<child>"
                                             "<object class=\"GtkCheckButton\" id=\"check_rol_15\">"
                                             "<property name=\"label\">Fianza</property>"
                                             "<property name=\"halign\">1</property>"
                                             "<property name=\"margin-end\">10</property>"
                                             "<property name=\"margin-start\">10</property>"
                                             "<property name=\"valign\">3</property>"
                                             "<layout>"
                                             "<property name=\"column\">0</property>"
                                             "<property name=\"row\">10</property>"
                                             "</layout>"
                                             "</object>"
                                             "</child>"
                                             "<child>"
                                             "<object class=\"GtkCheckButton\" id=\"check_rol_16\">"
                                             "<property name=\"label\">Mostrar Reportes</property>"
                                             "<property name=\"halign\">1</property>"
                                             "<property name=\"margin-end\">10</property>"
                                             "<property name=\"margin-start\">10</property>"
                                             "<property name=\"valign\">3</property>"
                                             "<layout>"
                                             "<property name=\"column\">0</property>"
                                             "<property name=\"row\">11</property>"
                                             "</layout>"
                                             "</object>"
                                             "</child>"
                                             "<child>"
                                             "<object class=\"GtkCheckButton\" id=\"check_rol_17\">"
                                             "<property name=\"label\">Configuracion</property>"
                                             "<property name=\"halign\">1</property>"
                                             "<property name=\"margin-end\">10</property>"
                                             "<property name=\"margin-start\">10</property>"
                                             "<property name=\"valign\">3</property>"
                                             "<layout>"
                                             "<property name=\"column\">1</property>"
                                             "<property name=\"row\">9</property>"
                                             "</layout>"
                                             "</object>"
                                             "</child>"
                                             "<child>"
                                             "<object class=\"GtkCheckButton\" id=\"check_rol_18\">"
                                             "<property name=\"label\">Salir a Windows</property>"
                                             "<property name=\"halign\">1</property>"
                                             "<property name=\"margin-end\">10</property>"
                                             "<property name=\"margin-start\">10</property>"
                                             "<property name=\"valign\">3</property>"
                                             "<layout>"
                                             "<property name=\"column\">1</property>"
                                             "<property name=\"row\">10</property>"
                                             "</layout>"
                                             "</object>"
                                             "</child>"
                                             "<child>"
                                             "<object class=\"GtkCheckButton\" id=\"check_rol_19\">"
                                             "<property name=\"label\">Apagar el equipo</property>"
                                             "<property name=\"halign\">1</property>"
                                             "<property name=\"margin-end\">10</property>"
                                             "<property name=\"margin-start\">10</property>"
                                             "<property name=\"valign\">3</property>"
                                             "<layout>"
                                             "<property name=\"column\">1</property>"
                                             "<property name=\"row\">11</property>"
                                             "</layout>"
                                             "</object>"
                                             "</child>"
                                             "<child>"
                                             "<object class=\"GtkButton\" id=\"btnGuardarPermisos\">"
                                             "<property name=\"label\">Guardar</property>"
                                             "<property name=\"margin-top\">50</property>"
                                             "<property name=\"valign\">3</property>"
                                             "<property name=\"halign\">3</property>"
                                             "<layout>"
                                             "<property name=\"column\">0</property>"
                                             "<property name=\"row\">15</property>"
                                             "<property name=\"column-span\">2</property>"
                                             "</layout>"
                                             "<style>"
                                             "<class name=\"suggested-action\"/>"
                                             "</style>"
                                             "</object>"
                                             "</child>"
                                             "</object>"
                                             "</child>"
                                             "</object>"
                                             "</child>"
                                             "</object>"
                                             "</interface>")
{
    auto builder = Gtk::Builder::create_from_string(XML);
    this->boxUsuarios = builder->get_widget<Gtk::Box>("boxUsuarios");
    set_margin(10);
    set_homogeneous();
    append(*boxUsuarios);
}

ViewUsuarios::~ViewUsuarios()
{
}

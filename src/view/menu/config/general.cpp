#include "view/menu/config/general.hpp"
#include "general.hpp"

ViewGeneral::ViewGeneral() : XML("<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                                 "<interface>"
                                 "<requires lib=\"gtk\" version=\"4.0\"/>"
                                 "<object class=\"GtkBox\" id=\"boxConfGeneral\">"
                                 "<property name=\"orientation\">1</property>"
                                 //"<property name=\"halign\">3</property>"
                                 //"<property name=\"valign\">3</property>"
                                 "<property name=\"spacing\">10</property>"
                                 "<child>"
                                 "<object class=\"GtkLabel\">"
                                 "<property name=\"label\" translatable=\"true\">Configuración general</property>"
                                 "<property name=\"halign\">1</property>"
                                 "<style>"
                                 "<class name=\"title-3\"/>"
                                 "</style>"
                                 "</object>"
                                 "</child>"
                                 "<child>"
                                 "<object class=\"GtkLabel\">"
                                 "<property name=\"label\" translatable=\"true\">Visualización</property>"
                                 "<property name=\"halign\">1</property>"
                                 "<style>"
                                 "<class name=\"title-4\"/>"
                                 "</style>"
                                 "</object>"
                                 "</child>"
                                 "<child>"
                                 "<object class=\"GtkSeparator\"></object>"
                                 "</child>"
                                 "<child>"
                                 "<object class=\"GtkCheckButton\" id=\"checkbox1\">"
                                 "<property name=\"active\">true</property>"
                                 "<property name=\"label\" translatable=\"true\">Mostrar notificaciones</property>"
                                 "</object>"
                                 "</child>"
                                 "<child>"
                                 "<object class=\"GtkLabel\">"
                                 "<property name=\"label\" translatable=\"true\">Operaciones en efectivo</property>"
                                 "<property name=\"halign\">1</property>"
                                 "<style>"
                                 "<class name=\"title-4\"/>"
                                 "</style>"
                                 "</object>"
                                 "</child>"
                                 "<child>"
                                 "<object class=\"GtkSeparator\"></object>"
                                 "</child>"
                                 "<child>"
                                 "<object class=\"GtkCheckButton\" id=\"checkbox5\">"
                                 "<property name=\"active\">true</property>"
                                 "<property name=\"label\" translatable=\"true\">Redondear cambio a favor del cliente</property>"
                                 "</object>"
                                 "</child>"
                                 "<child>"
                                 "<object class=\"GtkCheckButton\" id=\"checkbox6\">"
                                 "<property name=\"active\">true</property>"
                                 "<property name=\"label\" translatable=\"true\">Al introducir un billete controlar su posible devolución</property>"
                                 "</object>"
                                 "</child>"
                                 "<child>"
                                 "<object class=\"GtkCheckButton\" id=\"checkbox7\">"
                                 "<property name=\"active\">true</property>"
                                 "<property name=\"label\" translatable=\"true\">Poder finalizar cualquier operación</property>"
                                 "</object>"
                                 "</child>"
                                 "<child>"
                                 "<object class=\"GtkGrid\">"
                                 "<property name=\"margin-start\">10</property>"
                                 "<property name=\"margin-end\">10</property>"
                                 "<property name=\"margin-top\">10</property>"
                                 "<property name=\"margin-bottom\">10</property>"
                                 "<property name=\"row-spacing\">15</property>"
                                 "<property name=\"column-spacing\">10</property>"
                                 "<child>"
                                 "<object class=\"GtkLabel\">"
                                 "<property name=\"label\" translatable=\"true\">No permitir pagos superiores a       \" </property>"
                                 "<layout>"
                                 "<property name=\"row\">0</property>"
                                 "<property name=\"column\">0</property>"
                                 "</layout>"
                                 "</object>"
                                 "</child>"
                                 "<child>"
                                 "<object class=\"GtkSpinButton\" id=\"etyLimitePago\">"
                                 "<property name=\"editable\">false</property>"
                                 "<layout>"
                                 "<property name=\"row\">0</property>"
                                 "<property name=\"column\">1</property>"
                                 "</layout>"
                                 "</object>"
                                 "</child>"
                                 "<child>"
                                 "<object class=\"GtkLabel\">"
                                 "<property name=\"label\">Gestión de niveles y enrutamientos</property>"
                                 "<layout>"
                                 "<property name=\"row\">1</property>"
                                 "<property name=\"column\">0</property>"
                                 "</layout>"
                                 "</object>"
                                 "</child>"
                                 "<child>"
                                 "<object class=\"GtkCheckButton\" id=\"checkbox8\">"
                                 "<property name=\"active\">true</property>"
                                 "<property name=\"label\" translatable=\"true\">Manual</property>"
                                 "<layout>"
                                 "<property name=\"row\">1</property>"
                                 "<property name=\"column\">1</property>"
                                 "</layout>"
                                 "</object>"
                                 "</child>"
                                 "<child>"
                                 "<object class=\"GtkCheckButton\" id=\"checkbox9\">"
                                 "<property name=\"active\">true</property>"
                                 "<property name=\"label\" translatable=\"true\">Automático</property>"
                                 "<layout>"
                                 "<property name=\"row\">1</property>"
                                 "<property name=\"column\">2</property>"
                                 "</layout>"
                                 "</object>"
                                 "</child>"
                                 "</object>"
                                 "</child>"
                                 "<child>"
                                 "<object class=\"GtkCheckButton\" id=\"checkbox10\">"
                                 "<property name=\"active\">true</property>"
                                 "<property name=\"label\" translatable=\"true\">Mostrar barra de alertas de efectivo</property>"
                                 "<layout>"
                                 "<property name=\"row\">2</property>"
                                 "<property name=\"column\">0</property>"
                                 "</layout>"
                                 "</object>"
                                 "</child>"
                                 "</object>"
                                 "</interface>")
{
    auto builder = Gtk::Builder::create_from_string(XML);
    boxConfGeneral = builder->get_widget<Gtk::Box>("boxConfGeneral");
    set_margin(10);

    append(*boxConfGeneral);
}
ViewGeneral::~ViewGeneral()
{
}
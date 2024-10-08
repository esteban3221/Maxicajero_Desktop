#include "view/menu/config/informacion_sistema.hpp"
ViewInformacionSistema::ViewInformacionSistema(/* args */) : XML("<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                                                                 "<interface>"
                                                                 "<requires lib=\"gtk\" version=\"4.0\"/>"
                                                                 "<object class=\"GtkBox\" id=\"infSistemas\">"
                                                                 "<property name=\"orientation\">1</property>"
                                                                 "<property name=\"spacing\">20</property>"
                                                                 "<child>"
                                                                 "<object class=\"GtkListBox\" id=\"list_info_systema\">"
                                                                 "<child>"
                                                                 "<object class=\"GtkListBoxRow\">"
                                                                 "<property name=\"activatable\">false</property>"
                                                                 "<child>"
                                                                 "<object class=\"GtkBox\">"
                                                                 "<child>"
                                                                 "<object class=\"GtkLabel\">"
                                                                 "<property name=\"halign\">1</property>"
                                                                 "<property name=\"label\">Nombre del Dispositivo</property>"
                                                                 "</object>"
                                                                 "</child>"
                                                                 "<child>"
                                                                 "<object class=\"GtkEditableLabel\" id=\"ety_info_host\">"
                                                                 "<property name=\"text\">Type here…</property>"
                                                                 "<property name=\"editable\">true</property>"
                                                                 "<property name=\"hexpand\">true</property>"
                                                                 "<property name=\"halign\">2</property>"
                                                                 "<style>"
                                                                 "<class name=\"dim-label\"/>"
                                                                 "</style>"
                                                                 "</object>"
                                                                 "</child>"
                                                                 "</object>"
                                                                 "</child>"
                                                                 "</object>"
                                                                 "</child>"
                                                                 "<child>"
                                                                 "<object class=\"GtkListBoxRow\">"
                                                                 "<property name=\"activatable\">false</property>"
                                                                 "<child>"
                                                                 "<object class=\"GtkBox\">"
                                                                 "<child>"
                                                                 "<object class=\"GtkLabel\" id=\"entry_\">"
                                                                 "<property name=\"halign\">1</property>"
                                                                 "<property name=\"label\">Modelo de Hardware</property>"
                                                                 "</object>"
                                                                 "</child>"
                                                                 "<child>"
                                                                 "<object class=\"GtkEditableLabel\" id=\"ety_info_modelo\">"
                                                                 "<property name=\"text\">Type here…</property>"
                                                                 "<property name=\"editable\">false</property>"
                                                                 "<property name=\"hexpand\">true</property>"
                                                                 "<property name=\"halign\">2</property>"
                                                                 "<style>"
                                                                 "<class name=\"dim-label\"/>"
                                                                 "</style>"
                                                                 "</object>"
                                                                 "</child>"
                                                                 "</object>"
                                                                 "</child>"
                                                                 "</object>"
                                                                 "</child>"
                                                                 "<child>"
                                                                 "<object class=\"GtkListBoxRow\">"
                                                                 "<property name=\"activatable\">false</property>"
                                                                 "<child>"
                                                                 "<object class=\"GtkBox\">"
                                                                 "<child>"
                                                                 "<object class=\"GtkLabel\">"
                                                                 "<property name=\"halign\">1</property>"
                                                                 "<property name=\"label\">Procesador</property>"
                                                                 "</object>"
                                                                 "</child>"
                                                                 "<child>"
                                                                 "<object class=\"GtkEditableLabel\" id=\"ety_info_procesador\">"
                                                                 "<property name=\"text\">Type here…</property>"
                                                                 "<property name=\"editable\">false</property>"
                                                                 "<property name=\"hexpand\">true</property>"
                                                                 "<property name=\"halign\">2</property>"
                                                                 "<style>"
                                                                 "<class name=\"dim-label\"/>"
                                                                 "</style>"
                                                                 "</object>"
                                                                 "</child>"
                                                                 "</object>"
                                                                 "</child>"
                                                                 "</object>"
                                                                 "</child>"
                                                                 "<child>"
                                                                 "<object class=\"GtkListBoxRow\">"
                                                                 "<property name=\"activatable\">false</property>"
                                                                 "<child>"
                                                                 "<object class=\"GtkBox\">"
                                                                 "<child>"
                                                                 "<object class=\"GtkLabel\">"
                                                                 "<property name=\"halign\">1</property>"
                                                                 "<property name=\"label\">Memoria</property>"
                                                                 "</object>"
                                                                 "</child>"
                                                                 "<child>"
                                                                 "<object class=\"GtkEditableLabel\" id=\"ety_info_memoria\">"
                                                                 "<property name=\"text\">Type here…</property>"
                                                                 "<property name=\"editable\">false</property>"
                                                                 "<property name=\"hexpand\">true</property>"
                                                                 "<property name=\"halign\">2</property>"
                                                                 "<style>"
                                                                 "<class name=\"dim-label\"/>"
                                                                 "</style>"
                                                                 "</object>"
                                                                 "</child>"
                                                                 "</object>"
                                                                 "</child>"
                                                                 "</object>"
                                                                 "</child>"
                                                                 "<child>"
                                                                 "<object class=\"GtkListBoxRow\">"
                                                                 "<property name=\"activatable\">false</property>"
                                                                 "<child>"
                                                                 "<object class=\"GtkBox\">"
                                                                 "<child>"
                                                                 "<object class=\"GtkLabel\">"
                                                                 "<property name=\"halign\">1</property>"
                                                                 "<property name=\"label\">Disco</property>"
                                                                 "</object>"
                                                                 "</child>"
                                                                 "<child>"
                                                                 "<object class=\"GtkEditableLabel\" id=\"ety_info_disco\">"
                                                                 "<property name=\"text\">Type here…</property>"
                                                                 "<property name=\"editable\">false</property>"
                                                                 "<property name=\"hexpand\">true</property>"
                                                                 "<property name=\"halign\">2</property>"
                                                                 "<style>"
                                                                 "<class name=\"dim-label\"/>"
                                                                 "</style>"
                                                                 "</object>"
                                                                 "</child>"
                                                                 "</object>"
                                                                 "</child>"
                                                                 "</object>"
                                                                 "</child>"
                                                                 "<style>"
                                                                 "<class name=\"rich-list\"/>"
                                                                 "<class name=\"boxed-list\"/>"
                                                                 "</style>"
                                                                 "</object>"
                                                                 "</child>"
                                                                 "<child>"
                                                                 "<object class=\"GtkListBox\" id=\"listAcciones\">"
                                                                 "<child>"
                                                                 "<object class=\"GtkListBoxRow\">"
                                                                 "<child>"
                                                                 "<object class=\"GtkBox\">"
                                                                 "<child>"
                                                                 "<object class=\"GtkLabel\">"
                                                                 "<property name=\"halign\">1</property>"
                                                                 "<property name=\"hexpand\">true</property>"
                                                                 "<property name=\"label\">Reiniciar</property>"
                                                                 "<property name=\"valign\">3</property>"
                                                                 "<property name=\"xalign\">0</property>"
                                                                 "</object>"
                                                                 "</child>"
                                                                 "<child>"
                                                                 "<object class=\"GtkImage\">"
                                                                 "<property name=\"halign\">2</property>"
                                                                 "<property name=\"icon-name\">system-reboot-symbolic</property>"
                                                                 "<property name=\"margin-end\">10</property>"
                                                                 "</object>"
                                                                 "</child>"
                                                                 "</object>"
                                                                 "</child>"
                                                                 "</object>"
                                                                 "</child>"
                                                                 "<child>"
                                                                 "<object class=\"GtkListBoxRow\">"
                                                                 "<child>"
                                                                 "<object class=\"GtkBox\">"
                                                                 "<child>"
                                                                 "<object class=\"GtkLabel\">"
                                                                 "<property name=\"halign\">1</property>"
                                                                 "<property name=\"hexpand\">true</property>"
                                                                 "<property name=\"label\">Apagar</property>"
                                                                 "<property name=\"valign\">3</property>"
                                                                 "<property name=\"xalign\">0</property>"
                                                                 "</object>"
                                                                 "</child>"
                                                                 "<child>"
                                                                 "<object class=\"GtkImage\">"
                                                                 "<property name=\"halign\">2</property>"
                                                                 "<property name=\"icon-name\">system-shutdown-symbolic</property>"
                                                                 "<property name=\"margin-end\">10</property>"
                                                                 "</object>"
                                                                 "</child>"
                                                                 "</object>"
                                                                 "</child>"
                                                                 "</object>"
                                                                 "</child>"
                                                                 "<style>"
                                                                 "<class name=\"rich-list\"/>"
                                                                 "<class name=\"boxed-list\"/>"
                                                                 "</style>"
                                                                 "</object>"
                                                                 "</child>"
                                                                 "</object>"
                                                                 "</interface>")
{
    auto builder = Gtk::Builder::create_from_string(XML);
    this->boxinfSistemas = builder->get_widget<Gtk::Box>("infSistemas");
    labels[0] = builder->get_widget<Gtk::EditableLabel>("ety_info_host");
    labels[1] = builder->get_widget<Gtk::EditableLabel>("ety_info_modelo");
    labels[2] = builder->get_widget<Gtk::EditableLabel>("ety_info_procesador");
    labels[3] = builder->get_widget<Gtk::EditableLabel>("ety_info_memoria");
    labels[4] = builder->get_widget<Gtk::EditableLabel>("ety_info_disco");

    listAcciones = builder->get_widget<Gtk::ListBox>("listAcciones");

    set_margin(10);
    set_homogeneous();
    append(*boxinfSistemas);
}

ViewInformacionSistema::~ViewInformacionSistema()
{
}

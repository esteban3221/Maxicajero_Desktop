#include "view/menu/config/datos_empresa.hpp"

ViewDatosEmpresa::ViewDatosEmpresa(/* args */) : XML("<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                                                     "<interface>"
                                                     "<requires lib=\"gtk\" version=\"4.0\"/>"
                                                     "<object class=\"GtkBox\" id=\"boxDatosEmpresa\">"
                                                     "<property name=\"orientation\">1</property>"
                                                     "<child>"
                                                     "<object class=\"GtkListBox\" id=\"list_config_datos\">"
                                                     "<property name=\"selection-mode\">0</property>"
                                                     "<child>"
                                                     "<object class=\"GtkListBoxRow\">"
                                                     "<property name=\"activatable\">false</property>"
                                                     "<child>"
                                                     "<object class=\"GtkBox\">"
                                                     "<child>"
                                                     "<object class=\"GtkLabel\" id=\"entry_label_7\">"
                                                     "<property name=\"xalign\">0</property>"
                                                     "<property name=\"width-request\">110</property>"
                                                     "<property name=\"label\">Razón social</property>"
                                                     "</object>"
                                                     "</child>"
                                                     "<child>"
                                                     "<object class=\"GtkEntry\" id=\"ety_conf_razon\">"
                                                     "<property name=\"placeholder-text\">Type here…</property>"
                                                     "<property name=\"hexpand\">true</property>"
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
                                                     "<object class=\"GtkLabel\" id=\"entry_label_3\">"
                                                     "<property name=\"xalign\">0</property>"
                                                     "<property name=\"width-request\">110</property>"
                                                     "<property name=\"label\">Direccion</property>"
                                                     "</object>"
                                                     "</child>"
                                                     "<child>"
                                                     "<object class=\"GtkEntry\" id=\"ety_conf_direccion\">"
                                                     "<property name=\"placeholder-text\">Type here…</property>"
                                                     "<property name=\"hexpand\">true</property>"
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
                                                     "<object class=\"GtkLabel\" id=\"entry_label\">"
                                                     "<property name=\"xalign\">0</property>"
                                                     "<property name=\"width-request\">110</property>"
                                                     "<property name=\"label\">RFC</property>"
                                                     "</object>"
                                                     "</child>"
                                                     "<child>"
                                                     "<object class=\"GtkEntry\" id=\"ety_conf_rfc\">"
                                                     "<property name=\"placeholder-text\">Type here…</property>"
                                                     "<property name=\"hexpand\">true</property>"
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
                                                     "<object class=\"GtkLabel\" id=\"entry_label_4\">"
                                                     "<property name=\"xalign\">0</property>"
                                                     "<property name=\"width-request\">110</property>"
                                                     "<property name=\"label\">Contacto</property>"
                                                     "</object>"
                                                     "</child>"
                                                     "<child>"
                                                     "<object class=\"GtkEntry\" id=\"ety_conf_contacto\">"
                                                     "<property name=\"placeholder-text\">Type here…</property>"
                                                     "<property name=\"hexpand\">true</property>"
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
                                                     "<object class=\"GtkLabel\" id=\"entry_label_5\">"
                                                     "<property name=\"xalign\">0</property>"
                                                     "<property name=\"width-request\">110</property>"
                                                     "<property name=\"label\">Agradecimiento</property>"
                                                     "</object>"
                                                     "</child>"
                                                     "<child>"
                                                     "<object class=\"GtkEntry\" id=\"ety_conf_thanks\">"
                                                     "<property name=\"placeholder-text\">Type here…</property>"
                                                     "<property name=\"hexpand\">true</property>"
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
                                                     "<object class=\"GtkButton\" id=\"btnGuardar\">"
                                                     "<property name=\"label\">Guardar</property>"
                                                     "<property name=\"margin-top\">10</property>"
                                                     "<property name=\"halign\">2</property>"
                                                     "<style>"
                                                     "<class name=\"suggested-action\"/>"
                                                     "</style>"
                                                     "</object>"
                                                     "</child>"
                                                     "</object>"
                                                     "</interface>")
{
    auto builder = Gtk::Builder::create_from_string(XML);

    boxDatosEmpresa = builder->get_widget<Gtk::Box>("boxDatosEmpresa");

    data[0] = builder->get_widget<Gtk::Entry>("ety_conf_razon");
    data[1] = builder->get_widget<Gtk::Entry>("ety_conf_direccion");
    data[2] = builder->get_widget<Gtk::Entry>("ety_conf_rfc");
    data[3] = builder->get_widget<Gtk::Entry>("ety_conf_contacto");
    data[4] = builder->get_widget<Gtk::Entry>("ety_conf_thanks");

    btnGuardar = builder->get_widget<Gtk::Button>("btnGuardar");

    set_margin(10);
    set_homogeneous();
    this->append(*boxDatosEmpresa);
}

ViewDatosEmpresa::~ViewDatosEmpresa()
{
}

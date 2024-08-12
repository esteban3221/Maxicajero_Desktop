#include "header_bar.hpp"

HeaderBarMain::HeaderBarMain(/* args */) : XML("<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                                               "<interface>"
                                               "<requires lib=\"gtk\" version=\"4.0\"/>"
                                               "<object class=\"GtkBox\" id=\"boxConfguracionIP\">"
                                               "<property name=\"orientation\">1</property>"
                                               "<property name=\"spacing\">10</property>"
                                               "<property name=\"margin-top\">10</property>"
                                               "<property name=\"margin-bottom\">10</property>"
                                               "<property name=\"margin-start\">10</property>"
                                               "<property name=\"margin-end\">10</property>"
                                               "<child>"
                                               "<object class=\"GtkEntry\" id=\"etyDirectionServidor\">"
                                               "<property name=\"placeholder-text\">Introduzca la dirección de servidor...</property>"
                                               "<property name=\"primary-icon-name\">network-transmit-receive-symbolic</property>"
                                               "</object>"
                                               "</child>"
                                               "<child>"
                                               "<object class=\"GtkLabel\">"
                                               "<property name=\"label\">Direcciónes Guardadas</property>"
                                               "<property name=\"margin-top\">10</property>"
                                               "<property name=\"halign\">1</property>"
                                               "<style>"
                                               "<class name=\"title-3\"/>"
                                               "</style>"
                                               "</object>"
                                               "</child>"
                                               "<child>"
                                               "<object class=\"GtkScrolledWindow\">"
                                               "<property name=\"propagate-natural-width\">true</property>"
                                               "<property name=\"vexpand\">true</property>"
                                               "<child>"
                                               "<object class=\"GtkListBox\" id=\"listIpSaves\">"
                                               "<style>"
                                               "<class name=\"boxed-list\"/>"
                                               "</style>"
                                               "</object>"
                                               "</child>"
                                               "</object>"
                                               "</child>"
                                               "</object>"
                                               "</interface>")
{
    auto builder = Gtk::Builder::create_from_string(XML);
    this->boxConfguracionIP = builder->get_widget<Gtk::Box>("boxConfguracionIP");

    this->popOverConfig.set_child(*boxConfguracionIP);
    this->pack_start(toggleShowIP);
    popOverConfig.set_parent(toggleShowIP);
    toggleShowIP.set_icon_name("applications-system-symbolic");
    toggleShowIP.set_css_classes({"flat"});
    toggleShowIP.signal_toggled().connect([this]()
                                          {
        if(toggleShowIP.activate())
            popOverConfig.popup();
        else
            popOverConfig.hide(); 
        });
}

HeaderBarMain::~HeaderBarMain()
{
    popOverConfig.unparent();
}
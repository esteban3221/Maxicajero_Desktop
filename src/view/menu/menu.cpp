#include "menu.hpp"
ViewMenu::ViewMenu() : XML(
    
)
                                     
{
    auto builder = Gtk::Builder::create_from_string(XML);
    Global::Widget::lblinfobar = new Gtk::Label;

    this->boxMenu = builder->get_widget<Gtk::Box>("boxMenu");
    this->stackMenu = builder->get_widget<Gtk::Stack>("stackMenu");

    Global::Widget::btnCerrarSesion = builder->get_widget<Gtk::Button>("btnCerrarSesion");
    Global::Widget::progress = builder->get_widget<Gtk::ProgressBar>("progress");
    Global::Widget::infobar = builder->get_widget<Gtk::InfoBar>("infobar");
    Global::Widget::listBoxMenu = builder->get_widget<Gtk::ListBox>("listBoxMenu");
    Global::Widget::infobar->add_child(*Global::Widget::lblinfobar);

    Global::Widget::btnCerrarSesion->set_size_request(200,-1);

    this->stackMenu->set_transition_type(Gtk::StackTransitionType::SLIDE_UP_DOWN);
    this->boxMenu->set_margin(10);

    stackMenu->add(pago, "0"); // se invirtieron por que hacen lo opuesto
    stackMenu->add(venta, "1");
    stackMenu->add(efectivo, "2");

    stackMenu->add(movimientos, "5");
    stackMenu->add(cambioM, "10");

    stackMenu->add(configuracion, "14");

    this->append(*boxMenu);
}

ViewMenu::~ViewMenu()
{
}

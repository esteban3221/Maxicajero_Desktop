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

    this->stackMenu->set_transition_type(Gtk::StackTransitionType::SLIDE_UP_DOWN);
    this->boxMenu->set_margin(10);

    stackMenu->add(venta,"0");
    stackMenu->add(pago,"1");
    //stackMenu->add(efectivo,"2");

    this->append(*boxMenu);
}

ViewMenu::~ViewMenu()
{
    
}

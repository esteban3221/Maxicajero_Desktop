#include "controller/menu/menu.hpp"
#include "menu.hpp"

ControllerMenu::ControllerMenu()
{
    Global::Widget::btnCerrarSesion->signal_clicked().connect(sigc::mem_fun(*this, &ControllerMenu::onBtnSessionClicked));
    Global::Widget::listBoxMenu->signal_row_activated().connect(sigc::mem_fun(*this, &ControllerMenu::onlistBoxActivade));

    //test
    for (size_t i = 0; i < 15; i++)
    {
        Gtk::Label lbltest(std::to_string(i)); 
        stackMenu->add(lbltest,std::to_string(i));
    }
    
}

ControllerMenu::~ControllerMenu()
{
}

void ControllerMenu::onBtnSessionClicked()
{
    Global::Var::token.assign("");
    Global::Var::user.assign("");
    Global::Widget::stackMain->set_visible_child("login");
    Global::Widget::lblHeaderBar->set_markup("<b>Maxicajero</b>");
    Global::Widget::menuShowIP->set_visible();
}

void ControllerMenu::onlistBoxActivade(Gtk::ListBoxRow *row)
{
    stackMenu->set_visible_child(std::to_string(row->get_index()));
    std::cout << row->get_index() << '\n';
}

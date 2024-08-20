#pragma once 
#include <gtkmm.h>
#include "global.hpp"
#include "view/menu/pago.hpp"

class ViewMenu : public Gtk::Box
{
private:
    
    const char *XML;
    Gtk::Box *boxMenu = nullptr;

    //=========== Vistas ==========
    Pago pago;
protected:
    Gtk::Stack *stackMenu = nullptr;

public:
    ViewMenu();
    ~ViewMenu();
};

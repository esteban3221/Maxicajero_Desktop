#pragma once
#include "view/menu/menu.hpp"

class ControllerMenu : public ViewMenu
{
private:
    void onBtnSessionClicked();
    void onlistBoxActivade(Gtk::ListBoxRow *);
public:
    ControllerMenu();
    ~ControllerMenu();
};


#pragma once
#include <gtkmm.h>
#include "controller/menu/config/general.hpp"
class ViewNotepad : public Gtk::Notebook
{
private:
    ConrollerGeneral general;
public:
    ViewNotepad(/* args */);
    ~ViewNotepad();
};

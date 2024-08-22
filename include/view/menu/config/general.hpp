#pragma once
#include <gtkmm.h>

class ViewGeneral : public Gtk::Box
{
private:
    const char *XML;
protected:
    Gtk::Box *boxConfGeneral;
public:
    ViewGeneral(/* args */);
    ~ViewGeneral();
};

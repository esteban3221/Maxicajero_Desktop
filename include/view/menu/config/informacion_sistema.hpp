#pragma once
#include <gtkmm.h>

class ViewInformacionSistema : public Gtk::Box
{
private:
    const char *XML;
protected:
    Gtk::Box *boxinfSistemas;
    Gtk::EditableLabel *labels[5];
    Gtk::ListBox *listAcciones;
public:
    ViewInformacionSistema(/* args */);
    ~ViewInformacionSistema();
};


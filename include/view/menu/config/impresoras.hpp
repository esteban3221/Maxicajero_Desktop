#pragma once
#include <gtkmm.h>

class ViewImpresoras : public Gtk::Box
{
private:
    const char *XML;
protected:
    Gtk::Box *boxConfigImpresora;
public:
    ViewImpresoras(/* args */);
    ~ViewImpresoras();
};


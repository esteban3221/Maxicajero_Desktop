#pragma once
#include <gtkmm.h>

class TresFilas : public Gtk::Box
{
private:
    const char *XML;

protected:
    Gtk::Label *lblColum1, *lblColum2, *lblColum3;
    Gtk::Entry *etyColum1, *etyColum2, *etyColum3;

public:
    TresFilas(/* args */);
    ~TresFilas();
};

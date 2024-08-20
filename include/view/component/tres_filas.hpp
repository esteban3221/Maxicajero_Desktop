#pragma once
#include <gtkmm.h>

class TresFilas : public Gtk::Box
{
private:
    const char *XML;

protected:
    

public:
    Gtk::Box *boxCompSuperior = nullptr;
    Gtk::Label *lblColum1, *lblColum2, *lblColum3;
    Gtk::Entry *etyColum1, *etyColum2, *etyColum3;
    TresFilas(/* args */);
    ~TresFilas();
};

#pragma once 
#include <gtkmm.h>
#include "global.hpp"

class ViewEfectivo : public Gtk::Box
{
private:
    
    const char *XML;
    Gtk::Box *boxVistaEfectivo = nullptr;
    Gtk::Frame *frmRecicladorMonedas = nullptr;
    Gtk::Frame *frmRecicladorBilletes = nullptr;
    Gtk::TreeView *treeRecicladorBilletes = nullptr;
    Gtk::Frame *frmTotal = nullptr;
    Gtk::Frame *frmTotal2 = nullptr;
    Gtk::Frame *frmTotal3 = nullptr;
    Gtk::Frame *frmCasetteBilletes = nullptr;

protected:
    Gtk::Stack *stackMenu = nullptr;

public:
    ViewEfectivo();
    ~ViewEfectivo();
};

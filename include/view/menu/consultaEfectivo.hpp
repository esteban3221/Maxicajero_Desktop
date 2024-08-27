#pragma once 
#include <gtkmm.h>
#include "global.hpp"

class ViewEfectivo : public Gtk::Box
{
private:
    
    const char *XML;
    Gtk::Box *boxVistaEfectivo = nullptr;
    // Gtk::ColumnView *colViewRecicladorBilletes = nullptr;
    // Gtk::ColumnView *colViewRecicladorMonedas = nullptr;
    //Hace referencia a los digitos en decimal MXN
    // Gtk::Label *lblTotalMXN1 = nullptr;
    // Gtk::Label *lblTotalMXN2 = nullptr;
    // Gtk::Label *lblTotalMXN3 = nullptr;
    // Gtk::Label *lblTotalMXN4 = nullptr;
    // Gtk::Label *lblTotalMXN5 = nullptr;
    // //HAce referencia a los digitos finales de los recicladores
    // Gtk::Label *lblTotalNum1 = nullptr;
    // Gtk::Label *lblTotalNum2 = nullptr; 
    // //Hace referencia a la cantidad de l casette
    // Gtk::Label *lblTotalCasette = nullptr;

    // Gtk::Stack *stackMenu = nullptr;

public:
    ViewEfectivo();
    ~ViewEfectivo();
};

#include "pago.hpp"

Pago::Pago(/* args */)
{
    this->set_orientation(Gtk::Orientation::VERTICAL);
    this->set_spacing(5);
    tresfilas.set_halign(Gtk::Align::CENTER);
    tresfilas.lblColum1->set_text("Total");
    tresfilas.lblColum2->set_text("Ingresado");
    tresfilas.lblColum3->set_text("Cambio");
    this->append(tresfilas);
    this->append(nip);
    nip.entry->set_editable(false);
}

Pago::~Pago()
{
}

#include "pago.hpp"

Pago::Pago(/* args */)
{
    this->set_orientation(Gtk::Orientation::VERTICAL);
    this->set_spacing(5);
    tresfilas.set_halign(Gtk::Align::CENTER);
    this->append(tresfilas);
    this->append(nip);
    nip.entry->set_editable(false);
}

Pago::~Pago()
{
}

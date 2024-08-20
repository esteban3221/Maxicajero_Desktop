#include "pago.hpp"

Pago::Pago(/* args */)
{
    this->set_orientation(Gtk::Orientation::VERTICAL);
    
    this->append(tresfilas);
    this->append(nip);
}

Pago::~Pago()
{
}

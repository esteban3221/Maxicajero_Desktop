#pragma once
#include "tres_filas.hpp"
#include "nip.hpp"


class Pago : public Gtk::Box
{
protected:
    TresFilas tresfilas;
    Nip nip;
public:
    Pago(/* args */);
    ~Pago();
};
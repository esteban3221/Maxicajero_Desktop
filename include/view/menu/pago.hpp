#pragma once
#include "tres_filas.hpp"
#include "nip.hpp"


class Pago : public Gtk::Box
{
private:
    TresFilas tresfilas;
    Nip nip;
public:
    Pago(/* args */);
    ~Pago();
};
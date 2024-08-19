#pragma once
#include "tres_filas.hpp"
#include "nip.hpp"


class Pago : public Nip , public TresFilas final
{
private:

public:
    Pago(/* args */);
    ~Pago();
};
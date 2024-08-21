#pragma once
#include "pago.hpp"

class ControllerVenta : public ControllerPago
{
private:
    void onBtnEnterActivated() override;
public:
    ControllerVenta(/* args */);
    ~ControllerVenta();
};


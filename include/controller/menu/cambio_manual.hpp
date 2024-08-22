#pragma once
#include "controller/menu/pago.hpp"

class ControllerCambioManual : public ControllerPago
{
private:
    void onBtnEnterActivated() override;
public:
    ControllerCambioManual(/* args */);
    ~ControllerCambioManual();
};


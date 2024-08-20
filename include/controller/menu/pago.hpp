#pragma once 
#include "view/menu/pago.hpp"
#include <cpr/cpr.h>
#include "global.hpp"
#include <nlohmann/json.hpp>

class ControllerPago : public Pago
{
private:
    virtual void onBtnEnterActivated();
public:
    ControllerPago(/* args */);
    ~ControllerPago();
};
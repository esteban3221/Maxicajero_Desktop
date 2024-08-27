#pragma once
#include "view/menu/config/datos_empresa.hpp"
#include <cpr/cpr.h>
#include "global.hpp"
#include <nlohmann/json.hpp>

class ControllerDatosEmpresa : public ViewDatosEmpresa
{
private:
    void onShowWidget();
    void onBtnGuardarClicked();
public:
    ControllerDatosEmpresa(/* args */);
    ~ControllerDatosEmpresa();
};
#pragma once
#include "view/menu/config/informacion_sistema.hpp"
#include <cpr/cpr.h>
#include "global.hpp"
#include <nlohmann/json.hpp>

class ControllerInformacionSistema : public ViewInformacionSistema
{
private:
    void onShowWidget();
public:
    ControllerInformacionSistema(/* args */);
    ~ControllerInformacionSistema();
};
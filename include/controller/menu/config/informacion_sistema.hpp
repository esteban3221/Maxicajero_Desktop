#pragma once
#include "view/menu/config/informacion_sistema.hpp"
#include <cpr/cpr.h>
#include "global.hpp"
#include <nlohmann/json.hpp>
#include <chrono>

class ControllerInformacionSistema : public ViewInformacionSistema
{
private:
    void onShowWidget();
    void onListRowActivate(Gtk::ListBoxRow *row);
public:
    ControllerInformacionSistema(/* args */);
    ~ControllerInformacionSistema();
};
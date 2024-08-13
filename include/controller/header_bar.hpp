#pragma once
#include <iostream>
#include <cpr/cpr.h>
#include "model/header_bar.hpp"
#include "view/header_bar.hpp"
#include "helper.hpp"
#include <atomic>

namespace Controller
{
    class HeaderBarMain : public View::HeaderBarMain, public Model::HeaderBarMain
    {
    private:
        void onActiveEntry();
        void updateProgressIndicator(int remaining, int total);
        void finalizeConeccion(bool success);
        bool checkConeccion();

        Helper::Async asyncGui;
        std::atomic<bool> isCheckConeccion;

        Gtk::ListBoxRow *rowListIp(const std::string &label);

    public:
        HeaderBarMain(/* args */);
        ~HeaderBarMain();
    };
} // namespace Controller

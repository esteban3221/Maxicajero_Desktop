#pragma once

#include "model/header_bar.hpp"
#include "view/header_bar.hpp"

#include "helper.hpp"
#include <atomic>
#include <cpr/cpr.h>
#include <chrono>

namespace Controller
{
    class HeaderBarMain : public View::HeaderBarMain, public Model::HeaderBarMain
    {
    private:
        void onActiveEntry();
        void onIpRowActivated(Gtk::ListBoxRow *row);
        void updateProgressIndicator(int remaining, int total);
        void finalizeConeccion(bool success);
        bool checkConeccion();
        void initList();

        Helper::Async asyncGui;
        std::atomic<bool> isCheckConeccion;
        std::atomic<bool> isinConeccion;

        Gtk::ListBoxRow *rowListIp(const std::string &id ,const std::string &label);

    public:
        HeaderBarMain(/* args */);
        ~HeaderBarMain();
    };
} // namespace Controller

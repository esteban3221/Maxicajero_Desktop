#pragma once
#include <iostream>
#include <memory>
#include <gtkmm.h>

namespace Global
{
    namespace Var
    {
        extern std::string ipDirection;
        extern std::string user;
        extern std::string token;
        extern std::string session;
    } // namespace Var
    namespace Widget
    {
        // header
        extern Gtk::MenuButton *menuShowIP;
        extern Gtk::Label *lblHeaderBar;

        // menu
        extern Gtk::Button *btnCerrarSesion;
        extern Gtk::ProgressBar *progress;
        extern Gtk::InfoBar *infobar;
        extern Gtk::Label *lblinfobar;
        extern Gtk::ListBox *listBoxMenu;

        // navigation
        extern Gtk::Stack *stackMain;
    } // namespace Widget

    namespace User
    {
        enum class Rol
        {
            Venta = 1,
            Pago,
            Carga,
            Retirada,
            Cambio_M,
            Cambio_A,
            Ingresos,
            Enviar_Casette,
            Retirar_Casette,
            Consulta_Efectivo,
            Mov_Pendientes,
            Consulta_Movimientos,
            Cierre_Faltantes,
            Estadisticas,
            Fianza,
            Mostrar_Reportes,
            Configuracion,
            Salir_Escritorio,
            Apagar_Equipo
        };

        static const std::vector<Global::User::Rol> allRoles = 
        {
            Rol::Venta,
            Rol::Pago,
            Rol::Carga,
            Rol::Retirada,
            Rol::Cambio_M,
            Rol::Cambio_A,
            Rol::Ingresos,
            Rol::Enviar_Casette,
            Rol::Retirar_Casette,
            Rol::Consulta_Efectivo,
            Rol::Mov_Pendientes,
            Rol::Consulta_Movimientos,
            Rol::Cierre_Faltantes,
            Rol::Estadisticas,
            Rol::Fianza,
            Rol::Mostrar_Reportes,
            Rol::Configuracion,
            Rol::Salir_Escritorio,
            Rol::Apagar_Equipo
        };
    }

} // namespace Global

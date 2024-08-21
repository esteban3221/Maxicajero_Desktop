#include "global.hpp"

namespace Global
{
    namespace Var
    {
        std::string ipDirection;
        std::string user;
        std::string token;
        std::string session;
    } // namespace Var
    namespace Widget
    {
        // header
        Gtk::MenuButton *menuShowIP;
        Gtk::Label *lblHeaderBar;

        // menu
        Gtk::Button *btnCerrarSesion;
        Gtk::ProgressBar *progress;
        Gtk::InfoBar *infobar;
        Gtk::Label *lblinfobar;
        Gtk::ListBox *listBoxMenu;

        // navigation
        Gtk::Stack *stackMain;
    } // namespace Widget

} // namespace Global

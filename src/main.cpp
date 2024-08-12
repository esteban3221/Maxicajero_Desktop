#include "main_window.hpp"

int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create("MaxiCajero.desk");
    return app->make_window_and_run<main_window>(argc, argv);
}
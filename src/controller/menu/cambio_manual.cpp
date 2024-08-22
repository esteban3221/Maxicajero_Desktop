#include "controller/menu/cambio_manual.hpp"

ControllerCambioManual::ControllerCambioManual(/* args */)
{
}

ControllerCambioManual::~ControllerCambioManual()
{
}

inline void ControllerCambioManual::onBtnEnterActivated()
{
    if (nip.entry->get_text().empty() || std::stoll(nip.entry->get_text()) < 1)
    {
        Global::Widget::infobar->set_revealed();
        Global::Widget::lblinfobar->set_text("Ingrese el monto.");
        Global::Widget::infobar->set_message_type(Gtk::MessageType::WARNING);
        return;
    }

    nlohmann::json jsonData;
    jsonData["value"] = std::stoll(nip.entry->get_text()) * 100;
    std::string jsonString = jsonData.dump();

    auto fr = cpr::PostAsync(cpr::Url{"http://" + Global::Var::ipDirection + ":44333/accion/cambioM"},
                             cpr::Header{
                                 {"Authorization", "Bearer " + Global::Var::token},
                                 {"Cookie", "session=" + Global::Var::session}},
                             cpr::Body{jsonString});

    auto cpy = fr.share();

    nip.btnNipEnter->set_sensitive(false);

    Glib::signal_timeout().connect([this,cpy]() mutable -> bool
                                   {
                                       Global::Widget::progress->pulse(); 
                                       Global::Widget::listBoxMenu->set_sensitive(false);
                                       if (cpy.wait_for(std::chrono::milliseconds(0)) == std::future_status::ready)
                                       {
                                           auto r = cpy.get(); 

                                           Global::Widget::lblinfobar->set_text(r.text);
                                           Global::Widget::infobar->set_revealed();

                                           if (r.status_code == 200)
                                               Global::Widget::infobar->set_message_type(Gtk::MessageType::INFO);
                                           else
                                               Global::Widget::infobar->set_message_type(Gtk::MessageType::ERROR);
                                           
                                           Global::Widget::progress->set_fraction(1.0); 
                                           //Global::Widget::btnCerrarSesion->activate();
                                           return false;
                                       }
                                       return true;
                                   }, 100);
}
#include "controller/menu/pago.hpp"

ControllerPago::ControllerPago(/* args */)
{
    nip.btnNipEnter->signal_clicked().connect(sigc::mem_fun(*this, &ControllerPago::onBtnEnterActivated));
}

ControllerPago::~ControllerPago()
{
}

void ControllerPago::onBtnEnterActivated()
{
    if (nip.entry->get_text().empty())
    {
        Global::Widget::infobar->set_revealed();
        Global::Widget::lblinfobar->set_text("Ingrese el monto.");
        Global::Widget::infobar->set_message_type(Gtk::MessageType::WARNING);
        return;
    }

    nlohmann::json jsonData;
    jsonData["value"] = std::stoll(nip.entry->get_text());
    std::string jsonString = jsonData.dump();

    auto fr = cpr::PostAsync(cpr::Url{"http://" + Global::Var::ipDirection + ":44333/accion/venta"},
                             cpr::Header{
                                 {"Authorization", "Bearer " + Global::Var::token},
                                 {"Cookie", "session=" + Global::Var::session}},
                             cpr::Body{jsonString});

    auto cpy = fr.share();

    Glib::signal_timeout().connect([cpy]() mutable -> bool
                                   {
                                       Global::Widget::progress->pulse(); 

                                       if (cpy.wait_for(std::chrono::milliseconds(0)) == std::future_status::ready)
                                       {
                                           auto r = cpy.get(); // Obtener la respuesta

                                           if (r.status_code == 200)
                                           {
                                               std::cout << "Respuesta: " << r.text << std::endl;
                                               Global::Widget::progress->set_fraction(1.0); 
                                           }
                                           else
                                           {
                                               std::cout << "Error: " << r.status_code << std::endl;
                                               std::cout << "Respuesta: " << r.text << std::endl;
                                               Global::Widget::progress->set_fraction(0); 
                                           }
                                           return false;
                                       }
                                       return true;
                                   }, 100);
}

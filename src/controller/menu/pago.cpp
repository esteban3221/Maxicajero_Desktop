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

    std::thread([jsonString](){
        cpr::Response r = cpr::Post(cpr::Url{"http://" + Global::Var::ipDirection + ":44333/accion/venta"},
                                cpr::Header{
                                    {"Authorization", "Bearer "+ Global::Var::token},
                                    {"Cookie", "session="+Global::Var::session}},
                                cpr::Body{jsonString});
    Glib::signal_timeout().connect([r]() -> bool
                                   {
                                       Global::Widget::progress->pulse();
                                       if (r.status_code == 200)
                                       {
                                           std::cout << "Respuesta: " << r.text << std::endl;
                                       }
                                       else
                                       {
                                           std::cout << "Error: " << r.status_code << std::endl;
                                           std::cout << "Respuesta: " << r.text << std::endl;
                                       }
                                       return r.text.empty();
                                   },
                                   50);
    }).detach();
    
}

#include "controller/header_bar.hpp"
#include "header_bar.hpp"

namespace Controller
{
    Gtk::ListBoxRow *HeaderBarMain::rowListIp(const std::string &label)
    {
        auto row = new Gtk::ListBoxRow;
        auto box = new Gtk::Box;
        Gtk::Label labelPrincipal(label);
        auto btnDel = new Gtk::Button;

        box->append(labelPrincipal);
        box->append(*btnDel);

        btnDel->set_image_from_icon_name("list-remove-symbolic");
        btnDel->set_css_classes({"destructive-action"});
        labelPrincipal.set_halign(Gtk::Align::START);
        labelPrincipal.set_hexpand();
        btnDel->set_halign(Gtk::Align::END);

        btnDel->signal_clicked().connect([this,row](){
            listIpSaves->remove(*row);
        });

        row->set_child(*box);

        return row;
    }

    HeaderBarMain::HeaderBarMain(/* args */) : isCheckConeccion(false)
    {
        // async
        asyncGui.dispatcher.connect(sigc::mem_fun(asyncGui, &Helper::Async::on_dispatcher_emit));

        // señales
        this->etyDirectionServidor->signal_activate().connect(sigc::mem_fun(*this, &HeaderBarMain::onActiveEntry));
    }

    HeaderBarMain::~HeaderBarMain()
    {
    }

    void HeaderBarMain::onActiveEntry()
    {
        if (isCheckConeccion.load())
            return;

        const auto timeout = std::chrono::seconds(10);
        auto start = std::chrono::steady_clock::now();
        auto end = start + timeout;

        isCheckConeccion.store(true);

        Glib::signal_timeout().connect([this, start, end, timeout]() -> bool
                                       {
                                           auto now = std::chrono::steady_clock::now();
                                           auto remaining = std::chrono::duration_cast<std::chrono::seconds>(end - now).count();
                                           updateProgressIndicator(remaining, timeout.count());

                                           bool status = checkConeccion();

                                           if (status || remaining <= 0)
                                           {
                                               finalizeConeccion(status);
                                               etyDirectionServidor->set_editable();
                                               return false; // Detiene el timeout si la conexión es exitosa o el tiempo se agota
                                           }
                                           return true; // Sigue intentando mientras queden segundos disponibles
                                       },
                                       100);
    }

    void HeaderBarMain::updateProgressIndicator(int remaining, int total)
    {
        
        etyDirectionServidor->set_editable(false);
        asyncGui.dispatch_to_gui([this,remaining,total]
        
                                 { 
                                    static double fraction = 0.0;
                                    fraction = 1.0 - static_cast<double>(remaining) / total;
                                    etyDirectionServidor->set_css_classes({"entry"});
                                    etyDirectionServidor->set_progress_fraction(fraction); });
    }

    void HeaderBarMain::finalizeConeccion(bool success)
    {
        asyncGui.dispatch_to_gui([this, success]
                                 {
        if (!success) {
            etyDirectionServidor->set_placeholder_text("No se puede llegar al servidor.");
            etyDirectionServidor->set_text("");
            etyDirectionServidor->set_css_classes({"error"});
            etyDirectionServidor->set_progress_fraction( 1.0 );
        }
        else
        {
            etyDirectionServidor->set_progress_fraction( 0.0 );
            etyDirectionServidor->set_css_classes({"success"});
            listIpSaves->prepend(*rowListIp(etyDirectionServidor->get_text()));
        }
        
        isCheckConeccion.store(false); });
    }

    bool HeaderBarMain::checkConeccion()
    {
        auto url = "http://" + etyDirectionServidor->get_text() + ":44333/testConexion";
        cpr::Response r = cpr::Get(cpr::Url{url});
        return r.status_code == 200;
    }
} // namespaces View

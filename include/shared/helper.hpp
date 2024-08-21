#pragma once
#include <gtkmm.h>
#include <queue>

namespace Helper
{
    class Async
    {
    private:
        std::queue<std::function<void()>> dispatch_queue;
        std::mutex dispatch_queue_mutex;

    public:
        Async(/* args */){};
        ~Async(){};

        Glib::Dispatcher dispatcher;
        void on_dispatcher_emit();
        void dispatch_to_gui(std::function<void()> func);
    };

    inline void Async::on_dispatcher_emit()
    {
        std::function<void()> func;
        {
            std::lock_guard<std::mutex> lock(dispatch_queue_mutex);
            if (!dispatch_queue.empty())
            {
                func = dispatch_queue.front();
                dispatch_queue.pop();
            }
        }
        if (func)
        {
            func();
        }
    }

    inline void Async::dispatch_to_gui(std::function<void()> func)
    {
        {
            std::lock_guard<std::mutex> lock(dispatch_queue_mutex);
            dispatch_queue.push(func);
        }
        dispatcher.emit();
    }

} // namespace Helper

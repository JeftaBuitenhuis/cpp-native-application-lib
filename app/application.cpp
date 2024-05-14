#ifndef STD_THREAD_H
#define STD_THREAD_H
#include <thread>
#endif

#ifndef CHRONO_H
#define CHRONO_H
#include <chrono>
#endif

#ifndef STD_IOSTREAM_H
#define STD_IOSTREAM_H
#include <iostream>
#endif

#ifndef PUF_EVENT
#define PUF_EVENT
#include "../event/PUF_event.cpp"
#endif

class App {
    public:
        App() {
            x = 0;
        }

        int init();
        int destroy();
        int x;

    private:
        std::thread app_thread;
        bool terminate = false;
        int main();
};

int App::init() {
    app_thread = std::thread([this]() {
        this->main(); 
    });
    return 0;
}

int App::main() {
    auto next = std::chrono::steady_clock::now();
    


    while (!terminate) {
        
        /* do logical loopy bits here */
        PUF_EventHandler* event_handler 
        = PUF_EventHandler ::getInstance(); 
        PUF_event event;
        event.type = 0xFFFF;
        event.x = x;
        event_handler->push(event);

        x++;

        next += std::chrono::milliseconds(1000/240);
        std::this_thread::sleep_until(next);
    }

    return 0;
}

int App::destroy() {
    terminate = true;
    app_thread.join();
    return 0;
}

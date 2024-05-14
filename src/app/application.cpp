#include <thread>
#include <chrono>
#include <iostream>
#include "puffin/PUF_event.h"


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

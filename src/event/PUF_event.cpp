#include "event/PUF_event.h"

PUF_EventHandler* PUF_EventHandler::instance = nullptr;

void PUF_EventHandler::push(PUF_event event) {
    event_queue.push(event);
}

PUF_EventHandler* PUF_EventHandler::getInstance() {
            if (instance == nullptr) {
                instance = new PUF_EventHandler();
            }
            return instance;
        }

PUF_event PUF_EventHandler::pop() {
    if (!event_queue.empty()) {
        PUF_event event = event_queue.front();
        event_queue.pop();
        return event;
    } else {
        return PUF_event();
    }
}

bool PUF_EventHandler::empty() {
    return event_queue.empty();
}
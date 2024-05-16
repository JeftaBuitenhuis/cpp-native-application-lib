//! popfind() unstable -> segfault

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
        PUF_event event = event_queue.pop();
        return event;
    } else {
        PUF_event event;
        event.type = PUF_NOTFOUND;
        return event;
    }
}

bool PUF_EventHandler::empty() {
    return event_queue.empty();
}

void PUF_EventHandler::scanfind(PUF_event* event) {
    PUF_sll_node<PUF_event>* node = event_queue.getHeadNode();

    while (node != nullptr) {
        if (node->data.type == event->type) {
            event = &(node->data);
            return;
        }

        node = node->next;  
    }
    event->type = PUF_NOTFOUND;
}

void PUF_EventHandler::popfind(PUF_event* event) {
    if (event == nullptr) {
        // Handle invalid input pointer
        return;
    }

    PUF_sll_node<PUF_event>* node = event_queue.getHeadNode();
    PUF_sll_node<PUF_event>* prev = nullptr;
    while (node != nullptr) {
        if (node->data.type == event->type) {
            if (prev != nullptr) {
                prev->next = node->next;
            } else {
                event_queue.setHeadNode(node->next);
            }

            *event = node->data;
            delete node;
            return;
        }
        prev = node;
        node = node->next;  
    }

    event->type = PUF_NOTFOUND;
}
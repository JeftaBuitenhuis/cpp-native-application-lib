/* Puffin events */

#ifndef PUF_EVENT_H
#define PUF_EVENT_H

#include <event/PUF_queue.h>
#include <cstdint>

typedef enum {
    /* Library events */
    PUF_START           = 0,
    PUF_QUIT            = 0x100,
    
    /* Keyboard events */
    PUF_KEYDOWN         = 0x300,
    PUF_KEYUP,

    /* Mouse events*/
    PUF_MOUSEMOTION     = 0x400,

    /* Clipboard events */
    PUF_CLIPBOARDUPDATE = 0x1000,

    PUF_NOTFOUND        = 0xFFFF, // This is returned if the PUF_EventHandler doesnt find a event.
} PUF_EventType;

struct PUF_event{
    uint32_t type;
    int x;
};

class PUF_EventHandler {
    private:
        static PUF_EventHandler* instance;

        PUF_EventHandler() {}

    public:
        PUF_EventHandler(const PUF_EventHandler& obj) = delete;

        void push(PUF_event);
        PUF_event pop();
        bool empty();
        void scanfind(PUF_event* event);
        void popfind(PUF_event* event);

        static PUF_EventHandler* getInstance();

    private:
        PUF_queue<PUF_event> event_queue;
};

#endif
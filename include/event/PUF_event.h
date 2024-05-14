#ifndef PUF_EVENT_H
#define PUF_EVENT_H

#include <queue>
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

        static PUF_EventHandler* getInstance();

    private:
        std::queue<PUF_event> event_queue;
};

#endif
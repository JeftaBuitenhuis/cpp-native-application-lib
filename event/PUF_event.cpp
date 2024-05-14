#include <queue>

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

        static PUF_EventHandler* getInstance() {
            if (instance == nullptr) {
                instance = new PUF_EventHandler();
            }
            return instance;
        }

    private:
        std::queue<PUF_event> event_queue;
};

PUF_EventHandler* PUF_EventHandler::instance = NULL;

void PUF_EventHandler::push(PUF_event event) {
    event_queue.push(event);
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
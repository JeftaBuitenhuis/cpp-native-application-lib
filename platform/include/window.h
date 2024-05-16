#ifndef WINDOW_H
#define WINDOW_H

#include <cstdint>
#include <thread>

#include "gui/GUI_screen.h"

typedef enum {
    GUI_DEFAULT             = 0b0000000000000000000000000000000000000000000000000000000000000000, // * default properties
    GUI_WINDOW_RESIZABLE    = 0b0000000000000000000000000000000000000000000000000000000000000001, // * window becomes resizeable
    GUI_MANUAL_UPDATE       = 0b0000000000000000000000000000000000000000000000000000000000000010, // * window only updates on update()
} Window_flags;

class Window {
    protected:
        uint32_t hex_bg;
        std::thread window_thread;
        int width;
        int height;
        uint32_t flags;
        virtual void main() = 0;
        bool terminate = false;
    
    public:
        Window(int width, int height, uint32_t hex_bg, uint32_t flags)
        : width(width), height(height), hex_bg(hex_bg), flags(flags) {}

        virtual void setPixel(int, int, uint32_t) = 0;
        virtual uint32_t getPixel(int x, int y) = 0;
        virtual void setScreen(GUI_screen* screen) = 0;
        virtual void update() = 0;
        virtual void join() = 0;
        virtual void clearBuffer() = 0;

        bool getTerminate() {
            return terminate;
        }

        ~Window() {
            //delete screen;
        }
};

#endif
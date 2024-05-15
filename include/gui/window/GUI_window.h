#ifndef GUI_WINDOW_H
#define GUI_WINDOW_H

#include <SDL2/SDL.h>
#include <chrono>
#include <thread>
#include <cstdint>
#include <vector>

#include "gui/section/GUI_section.h"

typedef enum {
    GUI_WINDOW_RESIZABLE = 0x00000020,  // * window becomes resizeable
} GUI_window_flags;

class GUI_window {
    private:
        std::vector<GUI_section*> sections;
        int width;
        int height;
        uint32_t flags;
        std::thread window_thread;
        bool terminate = false;
        int main();
    public:
        GUI_window(int width, int height, int flags);
        ~GUI_window();
        void init();
        void addSection(GUI_section*);
        void join();
};

#endif
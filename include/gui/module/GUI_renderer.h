#ifndef GUI_RENDERER_H
#define GUI_RENDERER_H

#include "gui/common/GUI_screen.h"

class GUI_renderer {
    private:
        GUI_screen* screen;

    public:
        GUI_screen* getScreen();
        GUI_renderer(int width, int height);
        GUI_renderer(int width, int height, uint32_t hex);
        ~GUI_renderer();
        void setPixel(int x, int y, uint32_t hex) {
            screen->setPixel(x, y, hex);
        }

};

#endif

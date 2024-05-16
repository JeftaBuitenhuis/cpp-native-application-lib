#ifndef GUI_RENDERER_H
#define GUI_RENDERER_H

#include <cstdint>
#include "window.h"

class GUI_renderer {
    protected:
        uint32_t* pixels;
        int width;
        int height;
        uint32_t hex_bg;
        Window* win;
    public:
        uint32_t* getPixels();
        GUI_renderer(Window* win, int width, int height);
        GUI_renderer(Window* win, int width, int height, uint32_t hex);
        ~GUI_renderer();
        void update(int pos_x, int pos_y);
        void clear();
        void setPixel(int x, int y, uint32_t hex) {
            if (y < height && x < width)
            pixels[x + (y * width)] = hex;
        }
        void setPixels(int pos_x, int pos_y);

};

#endif

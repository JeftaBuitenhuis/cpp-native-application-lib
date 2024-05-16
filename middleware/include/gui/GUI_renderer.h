#ifndef GUI_RENDERER_H
#define GUI_RENDERER_H

#include <cstdint>

class GUI_renderer {
    private:
        uint32_t* pixels;
        int width;

    public:
        uint32_t* getPixels();
        GUI_renderer(int width, int height);
        GUI_renderer(int width, int height, uint32_t hex);
        ~GUI_renderer();
        void setPixel(int x, int y, uint32_t hex) {
            pixels[x + (y * width)] = hex;
        }

};

#endif

#ifndef GUI_SCREEN_H
#define GUI_SCREEN_H

#include <cstdint>
#include "gui/GUI_pixel.h"

class GUI_screen {
    private:
        GUI_pixel** screen;
        int width;
        int heigth;
        uint32_t hex_bg = 0x00000000;
        int z_index = 0;

    public:
        GUI_screen(int width, int height);
        GUI_screen(int width, int height, uint32_t hex_bg);
        ~GUI_screen();
        void GUI_getScreen();

        void setZ(int z);
        void setBackgroundHex(uint32_t hex);
        void setPixel(int x, int y, uint32_t hex);
        void clear();
        void clear(uint32_t hex_bg);

        int getWidth();
        int getHeight();
        GUI_pixel* getPixel(int x, int y);
};

#endif
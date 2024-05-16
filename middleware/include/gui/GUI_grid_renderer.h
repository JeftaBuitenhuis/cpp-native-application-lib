#ifndef GUI_GRID_RENDERER_H
#define GUI_GRID_RENDERER_H

#include "gui/GUI_renderer.h"
#include <iostream>

class GUI_grid_renderer : public GUI_renderer {
    private:
    protected:
        int scale = 25;
    public:
        GUI_grid_renderer(Window* win, int width, int height, uint32_t hex, int scale) : GUI_renderer(win, width, height, hex) {
            this->scale = scale;
        }
        GUI_grid_renderer(Window* win, int width, int height, int scale) : GUI_renderer(win, width, height) {
            this->scale = scale;
        }
        void setPixel(int x, int y, uint32_t hex) {
            if (y < height/scale && x < width/scale) {
                std::cout << "passed if" << (x / scale) * scale;
                for (int i_x = (x * scale); i_x < ((x * scale) + scale); i_x++) {
                    for (int i_y = (y * scale); i_y < ((y * scale) + scale); i_y++) {
                        pixels[i_x + (i_y * width)] = hex;
                    }
                }
            }
        }

};

#endif

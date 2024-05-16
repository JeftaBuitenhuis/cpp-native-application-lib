#include "gui/GUI_renderer.h"

GUI_renderer::GUI_renderer(int width, int height) {
    this->width = width;
     pixels = new uint32_t[height*width];
}

GUI_renderer::GUI_renderer(int width, int height, uint32_t hex) {
     pixels = new uint32_t[height*width];
     for (int i = 0; i < height * width; i++) {
        pixels[i] = hex;
     }
}


GUI_renderer::~GUI_renderer() {
    delete pixels;
}

uint32_t* GUI_renderer::getPixels() {
    return pixels;
}
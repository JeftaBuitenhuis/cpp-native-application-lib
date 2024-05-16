#include "gui/GUI_renderer.h"

GUI_renderer::GUI_renderer(Window* win, int width, int height) {
    this->win = win;
    this->width = width;
    this->height = height;
    this->hex_bg = 0x00000000;
    pixels = new uint32_t[height*width];
}

GUI_renderer::GUI_renderer(Window* win, int width, int height, uint32_t hex) {
    this->width = width;
    this->height = height;
    this->win = win;
    this->hex_bg = hex;
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

void GUI_renderer::update(int pos_x, int pos_y) {
    win->setPixels(pixels, width, height, pos_x, pos_y);
    win->update();
}

void GUI_renderer::clear() {
    for (int i = 0; i < width * height; i++) {
        pixels[i] = hex_bg;
    }
}
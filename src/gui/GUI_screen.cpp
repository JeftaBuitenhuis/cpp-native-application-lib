#include "gui/common/GUI_screen.h"

GUI_screen::GUI_screen(int width, int height) {
    this->width = width;
    this->heigth = height;
    screen = new GUI_pixel*[width];
    
    for (int i = 0; i < width; ++i) {
        screen[i] = new GUI_pixel[height];
    }
}

GUI_screen::GUI_screen(int width, int height, uint32_t hex) {
    this->width = width;
    this->heigth = height;
    screen = new GUI_pixel*[width];
    
    for (int i = 0; i < width; ++i) {
        screen[i] = new GUI_pixel[height];
        for (int j = 0; j < height; ++j) {
            screen[i][j].setHex(hex);
        }
    }
}

GUI_screen::~GUI_screen() {
    for (int i = 0; i < width; ++i) {
        delete[] screen[i];
    }
    delete[] screen;
}

void GUI_screen::setBackgroundHex(uint32_t hex) {
    this->hex_bg = hex;
}

void GUI_screen::setZ(int z) {
    this->z_index = z;
}

void GUI_screen::setPixel(int x, int y, uint32_t hex) {
    if (x >= width || y >= heigth) {
        return;
    }
    screen[x][y].setHex(hex);
}

void GUI_screen::clear() {
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < heigth; y++) {
            screen[x][y].setHex(hex_bg);
        }
    }
}

void GUI_screen::clear(uint32_t hex) {
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < heigth; y++) {
            screen[x][y].setHex(hex);
        }
    }
}

int GUI_screen::getWidth() {
    return width;
}

int GUI_screen::getHeight() {
    return heigth;
}

GUI_pixel* GUI_screen::getPixel(int x, int y) {
    return &screen[x][y];
}

#include "gui/GUI_section.h"

GUI_section::GUI_section(GUI_renderer* renderer, int pos_x, int pos_y) {
    this->renderer = renderer;
    this->pos_x = pos_x;
    this->pos_y = pos_y;
}

GUI_section::~GUI_section() {
    delete renderer;
}

uint32_t* GUI_section::getPixels() {
    return renderer->getPixels();
}

int GUI_section::getPosX() {
    return pos_x;
}

int GUI_section::getPosY() {
    return pos_y;
}
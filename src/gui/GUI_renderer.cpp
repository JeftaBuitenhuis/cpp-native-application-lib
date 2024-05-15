#include "gui/module/GUI_renderer.h"

GUI_renderer::GUI_renderer(int width, int height) {
    screen = new GUI_screen(width, height);
}

GUI_renderer::GUI_renderer(int width, int height, uint32_t hex) {
    screen = new GUI_screen(width, height, hex);
}


GUI_renderer::~GUI_renderer() {
    delete screen;
}

GUI_screen* GUI_renderer::getScreen() {
    return screen;
}
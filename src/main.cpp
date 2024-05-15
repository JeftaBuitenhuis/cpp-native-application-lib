#include "app/application.cpp"
#include "render/renderer.cpp"
#include "gui/window/GUI_window.h"

//! multiple windows not supported currently

//! currently has a massive memory leak :/

int main(void) {
    App app;
    app.init();

    //Renderer renderer;
    //renderer.init();

    GUI_window* win = new GUI_window(1000, 1000, GUI_WINDOW_RESIZABLE);
    GUI_renderer* renderer = new GUI_renderer(500, 500);
    for (int x = 0; x < 1000; x++) {
        renderer->setPixel(x, 250, 0xFFFFFFFF);
    }
    GUI_section* section = new GUI_section(renderer, 250, 0);
    win->addSection(section);
    GUI_section* section2 = new GUI_section(renderer, 500, 250);
    win->addSection(section2);
    win->init();
    

    win->join();

    //renderer.destroy();
    app.destroy();

    return 0;
}
#include "app/application.cpp"
#include "render/renderer.cpp"
#include "gui/window/GUI_window.h"

//! multiple windows not supported currently

int main(void) {
    App app;
    app.init();

    //Renderer renderer;
    //renderer.init();

    GUI_window* win = new GUI_window(1000, 1000, GUI_WINDOW_RESIZABLE);
    GUI_renderer* renderer = new GUI_renderer(500, 500);
    for (int x = 0; x < 500; x++) {
        renderer->setPixel(x, 250, 0xFFFFFFFF);
    }
    GUI_section* section = new GUI_section(renderer, 0, 0);
    win->addSection(section);
    win->init();
    

    win->join();

    //renderer.destroy();
    app.destroy();

    return 0;
}
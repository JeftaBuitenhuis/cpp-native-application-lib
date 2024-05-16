#include <iostream>

#include "sdl/sdl_window.h"
#include <chrono>

#include "gui/GUI_section.h"
#include "gui/GUI_grid_renderer.h"
//#include "app/application.cpp"

//! multiple windows not supported currently

//! currently has a massive memory leak :/

int main() {
    Window* win = new SDL_IWindow(1000, 1000, 0x00000000, GUI_MANUAL_UPDATE);

    GUI_grid_renderer* renderer = new GUI_grid_renderer(win, 1000, 1000, 0xFFFFFFFF, 50);
    //GUI_renderer* renderer2 = new GUI_renderer(win, 500, 500, 0xFFFFFFFF);
    GUI_section* section = new GUI_section(renderer, 0, 0);

    bool up = true;
    bool left = true;

    int x = 0;

    auto next = std::chrono::steady_clock::now();
    while (!win->getTerminate()) {

        renderer->setPixel(x, 5, 0xFF0000FF);

        section->setPixels();
        section->update();
        section->clear();

        x++; 

        next += std::chrono::milliseconds(1000);
        std::this_thread::sleep_until(next);
    }

    win->join();
    // App app;
    // app.init();

    // //Renderer renderer;
    // //renderer.init();

    // GUI_window* win = new GUI_window(1000, 1000, GUI_WINDOW_RESIZABLE);
    // GUI_renderer* renderer = new GUI_renderer(500, 500);
    // for (int x = 0; x < 1000; x++) {
    //     renderer->setPixel(x, 250, 0xFFFFFFFF);
    // }
    // GUI_section* section = new GUI_section(renderer, 250, 0);
    // win->addSection(section);
    // GUI_section* section2 = new GUI_section(renderer, 500, 250);
    // win->addSection(section2);
    // win->init();
    

    // win->join();

    // //renderer.destroy();
    //app.destroy();

    return 0;
}
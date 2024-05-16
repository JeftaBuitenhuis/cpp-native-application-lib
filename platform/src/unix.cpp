#include <iostream>

#include "sdl/sdl_window.h"
#include <chrono>

#include "gui/GUI_section.h"
#include "gui/GUI_renderer.h"
//#include "app/application.cpp"

//! multiple windows not supported currently

//! currently has a massive memory leak :/

int main() {
    Window* win = new SDL_IWindow(1000, 1000, 0x00000000, GUI_MANUAL_UPDATE);

    GUI_renderer* renderer = new GUI_renderer(win, 500, 500, 0xFFFFFFFF);
    //GUI_renderer* renderer2 = new GUI_renderer(win, 500, 500, 0xFFFFFFFF);
    GUI_section* section = new GUI_section(renderer, 0, 0);
    GUI_section* section1 = new GUI_section(renderer, 0, 500);
    GUI_section* section2 = new GUI_section(renderer, 500, 0);
    GUI_section* section3 = new GUI_section(renderer, 500, 500);

    bool up = true;
    bool left = true;

    auto next = std::chrono::steady_clock::now();
    while (!win->getTerminate()) {
        if (up && left) {
            for (int x = 0; x < 250; x++) {
                renderer->setPixel(x, x, 0x00000000);
            }
            left = !left;
        }

        else if (up && !left) {
            for (int x = 0; x < 250; x++) {
                renderer->setPixel(500-x, x, 0x00000000);
            }
            up = !up;
        }

        else if (!up && !left) {
            for (int x = 0; x < 250; x++) {
                renderer->setPixel(500-x, 500-x, 0x00000000);
            }
            left = !left;
        }

        else if (!up && left) {
            for (int x = 0; x < 250; x++) {
                renderer->setPixel(x, 500-x, 0x00000000);
            }
            up = !up;
        }

        section->update();
        section1->update();
        section2->update();
        section3->update();
        section3->clear();
        next += std::chrono::milliseconds(0);
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
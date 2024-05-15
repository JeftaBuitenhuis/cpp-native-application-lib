#include "gui/window/GUI_window.h"
#include <iostream>

GUI_window::GUI_window(int width, int height, int flags) {
    this->width = width;
    this->height = height;
    this->flags = flags;
}

void GUI_window::addSection(GUI_section* section) {
    sections.push_back(section);
}

void GUI_window::init() {
    window_thread = std::thread([this]() {
        this->main(); 
    });
}

int GUI_window::main() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        throw "Error initializing SDL";
    }

    SDL_Window* win = SDL_CreateWindow("Application", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
    SDL_Renderer *renderer = SDL_CreateRenderer(win, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Event event;

    bool close = 0;

    int width = SDL_GetWindowSurface(win)->w;
    int height = SDL_GetWindowSurface(win)->h;

    auto next = std::chrono::steady_clock::now();
    while (!close) {

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                close = 1;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.scancode) {
                case SDL_SCANCODE_ESCAPE:
                    close = 1;
                    break;
                default:
                    break;
                }
            case SDL_WINDOWEVENT:
                switch (event.window.event) {
                case SDL_WINDOWEVENT_RESIZED:
                    width = SDL_GetWindowSurface(win)->w;
                    height = SDL_GetWindowSurface(win)->h;
                    break;
                
                default:
                    break;
                }
            default:
                break;
            }
        }

        SDL_RenderClear(renderer);

        for (int s = 0; s < sections.size(); s++) {
            GUI_section* section = sections.at(s);
            int s_x = section->getPosX();
            int s_y = section->getPosY();
            GUI_screen* screen = section->getScreen();
            int s_width = screen->getWidth();
            int s_height = screen->getHeight();
            for (int y = s_y; y < s_height + s_y; y++) {
                for (int x = s_x; x < s_width + s_x; x++) {
                    GUI_pixel* p = screen->getPixel(x-s_x, y-s_y);
                    SDL_SetRenderDrawColor(renderer, p->getR(), p->getG(), p->getB(), p->getA());
                    SDL_RenderDrawPoint(renderer, x, y);
                }
            }
        }

        SDL_RenderPresent(renderer);

        next += std::chrono::milliseconds(10);
        std::this_thread::sleep_until(next);
    }

    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;
}

void GUI_window::join() {
    terminate = true;
    window_thread.join();
}

GUI_window::~GUI_window() {
    
}
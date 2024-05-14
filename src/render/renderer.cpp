#include <thread>
#include <chrono>
#include <iostream>
#include <SDL2/SDL.h>
#include "pixel.cpp"
#include <vector>
#include "puffin/PUF_event.h"

class Renderer {
    public:
        Renderer() {
            
        }

        int init();
        int destroy();

    private:
        std::thread renderer_thread;
        bool terminate = false;
        int main();

    public:
        std::vector<char> buffer;
};

int Renderer::init() {
    renderer_thread = std::thread([this]() {
        this->main(); 
    });
    return 0;
}

int Renderer::main() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        throw "Error initializing SDL";
    }

    SDL_Window* win = SDL_CreateWindow("Application", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, SDL_WINDOW_RESIZABLE);
    SDL_Renderer *renderer = SDL_CreateRenderer(win, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Event event;

    bool close = 0;

    int width = SDL_GetWindowSurface(win)->w;
    int height = SDL_GetWindowSurface(win)->h;

    buffer.reserve(width*height);

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    int x = 0;

    auto next = std::chrono::steady_clock::now();
    while (!close) {
        PUF_EventHandler* event_handler = PUF_EventHandler ::getInstance();

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
                    buffer.reserve(width*height);
                    break;
                
                default:
                    break;
                }
            default:
                break;
            }
        }

        while (!event_handler->empty()) {
            int count = 0;
            count++;
            PUF_event event = event_handler->pop();
            switch (event.type) {
            case 0xFFFF: {

                x = event.x;
                break;
            }
            default:
                break;
            }
        }

        SDL_RenderClear(renderer);

        rgba_pixel p = rgba_pixel(0xFF, 0xFF, 0xFF, 0xFF);

        SDL_SetRenderDrawColor(renderer, p.r, p.g, p.b, p.a);

        for (int my = 0; my < x/width; ++my) {
            SDL_RenderDrawLine(renderer, 0, my, width, my);
        }
        SDL_RenderDrawLine(renderer, 0, (x/width) + 1, x % width, (x/width) + 1);

        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);

        SDL_RenderPresent(renderer);

        next += std::chrono::milliseconds(10);
        std::this_thread::sleep_until(next);
    }

    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;
}

int Renderer::destroy() {
    terminate = true;
    renderer_thread.join();
    return 0;
}

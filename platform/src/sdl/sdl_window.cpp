#include "sdl/sdl_window.h"
#include <iostream>
#include <cstdint>

SDL_IWindow::SDL_IWindow(int width, int height, uint32_t hex_bg, int flags) : Window(width, height, hex_bg, flags){
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        throw "Error initializing SDL";
    }

    win = SDL_CreateWindow("Application", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
    renderer = SDL_CreateRenderer(win, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    buffer = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, width, height);

    window_thread = std::thread([this]() {
        this->main(); 
    });
}

void SDL_IWindow::main() {
    auto next = std::chrono::steady_clock::now();
    while (!terminate) {

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                terminate = 1;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.scancode) {
                case SDL_SCANCODE_ESCAPE:
                    terminate = 1;
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
        
        if ((flags & 0b0000000000000000000000000000000000000000000000000000000000000010) == 0) {
            std::cout << "auto-update" << '\n';
            this->update();
        }

        next += std::chrono::milliseconds(10);
        std::this_thread::sleep_until(next);
    }
}

void SDL_IWindow::join() {
    terminate = true;
    window_thread.join();
}

// TODO: have to impl all of these underneath

SDL_IWindow::~SDL_IWindow() {
    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void SDL_IWindow::setPixel(int x, int y, uint32_t hex) {
    pixel 
}

void SDL_IWindow::update() {
    SDL_RenderClear(renderer);
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            GUI_pixel* p = buffer
            SDL_SetRenderDrawColor(renderer, p->getR(), p->getG(), p->getB(), p->getA());
            SDL_RenderDrawPoint(renderer, x, y);
        }
    }   
    SDL_RenderPresent(renderer);
    clearScreen();    clearScreen();
}

void SDL_IWindow::setScreen(GUI_screen* screen) {

}   

uint32_t SDL_IWindow::getPixel(int x, int y) {
    return 0xFFFFFFFF;
}

void SDL_IWindow::clearBuffer() {
    
}
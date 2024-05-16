#include "sdl/sdl_window.h"
#include <iostream>
#include <cstdint>

SDL_IWindow::SDL_IWindow(int width, int height, uint32_t hex_bg, int flags) : Window(width, height, hex_bg, flags){
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        throw "Error initializing SDL";
    }

    win = SDL_CreateWindow("Application", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
    renderer = SDL_CreateRenderer(win, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);//SDL_RENDERER_PRESENTVSYNC
    buffer = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, width, height);

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
    this->pixels[x+(y*width)] = hex;
}

void SDL_IWindow::update() {
    int pitch = width * height * sizeof(uint32_t); // Declare a variable to store the pitch
    if (SDL_LockTexture(buffer, nullptr, (void **)&pixels, &pitch) != 0) {
        std::cerr << "Failed to lock texture: " << SDL_GetError() << std::endl;
        return;
    }

    // Modify pixel data (if needed)

    // Unlock the texture when done
    SDL_UnlockTexture(buffer);

    // Clear the renderer
    //SDL_RenderClear(renderer);

    // Copy the texture to the renderer
    SDL_RenderCopy(renderer, buffer, nullptr, nullptr);

    // Present the renderer
    SDL_RenderPresent(renderer);

    // Optionally, clear the buffer or perform other cleanup
    //clearBuffer();
    // Capture the current time after running the code
    auto end = std::chrono::steady_clock::now();

    // Calculate the duration between the two time points
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // Output the duration in nanoseconds
    std::cout << "FPS: " << 1 / ((double) duration.count()/1000) << "\n";
    start = std::chrono::steady_clock::now();
}

void SDL_IWindow::setPixels(uint32_t* pixels, int width, int height, int x, int y) {
    for (int i_y = y; i_y - y < height; i_y++) {
        for (int i_x = x; i_x - x < width; i_x++) {
            int pos = i_x + (i_y * this->width);
            if (pos < this->width * this->height) {
                this->pixels[pos] = pixels[(i_x-x) + ((i_y - y) * width)];
            }
        }
    }
    
}   

uint32_t SDL_IWindow::getPixel(int x, int y) {
    return 0xFFFFFFFF;
}

void SDL_IWindow::clearBuffer() {
    for (int x = 0; x < width*height; x++) {
        pixels[x] = hex_bg;
    }
}
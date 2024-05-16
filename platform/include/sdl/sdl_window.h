#ifndef SDL_WINDOW_H
#define SDL_WINDOW_H

#include <SDL2/SDL.h>
#include <chrono>
#include <cstdint>
#include <vector>

#include "gui/GUI_section.h"
#include "window.h"

class SDL_IWindow : public Window {
    private:
        SDL_Texture* buffer;
        SDL_Window* win;
        SDL_Renderer *renderer;
        SDL_Event event;
        std::chrono::_V2::steady_clock::time_point start = std::chrono::steady_clock::now();
        
    protected:
        virtual void main() override;

    public:
        SDL_IWindow(int width, int height, uint32_t hex_bg, int flags);
        virtual void setPixel(int, int, uint32_t) override;
        virtual uint32_t getPixel(int x, int y) override;
        virtual void setPixels(uint32_t* pixels) override;
        virtual void update() override;
        virtual void join() override;
        virtual void clearBuffer() override;
        ~SDL_IWindow();
};

#endif
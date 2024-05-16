#ifndef GUI_PIXEL_H
#define GUI_PIXEL_H

#include <cstdint>

class GUI_pixel {
    private:
        uint32_t hex;
    
    public:
        GUI_pixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
            this->hex = (r << 24) + (g << 16) + (b << 8) + a;
        }

        GUI_pixel() {
            this->hex = 0x00000000;
        }

        GUI_pixel(uint8_t r, uint8_t g, uint8_t b) {
            this->hex = (r << 24) + (g << 16) + (b << 8) + 0xFF;
        }

        uint32_t getHex();
        uint8_t getR();
        uint8_t getG();
        uint8_t getB();
        uint8_t getA();

        void setHex(uint32_t hex);
        void setR(uint8_t r);
        void setG(uint8_t g);
        void setB(uint8_t b);
        void setA(uint8_t a);
};

#endif


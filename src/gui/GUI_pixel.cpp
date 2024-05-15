#include "gui/common/GUI_pixel.h"

uint32_t GUI_pixel::getHex() {
    return this->hex;
}

uint8_t GUI_pixel::getR() {
    return (hex >> 24) & 0xFF;
}

uint8_t GUI_pixel::getG() {
    return (hex >> 16) & 0xFF;
}

uint8_t GUI_pixel::getB() {
    return (hex >> 8) & 0xFF;
}

uint8_t GUI_pixel::getA() {
    return hex & 0xFF;
}

void GUI_pixel::setHex(uint32_t hex) {
    this->hex = hex;
}

void GUI_pixel::setR(uint8_t r) {
    this->hex = (0x00FFFFFF & hex) + (r << 24);
}

void GUI_pixel::setG(uint8_t g) {
    this->hex = (0xFF00FFFF & hex) + (g << 16);
}

void GUI_pixel::setB(uint8_t b) {
    this->hex = (0xFFFF00FF & hex) + (b << 8);
}

void GUI_pixel::setA(uint8_t a) {
    this->hex = (0xFFFFFF00 & hex) + a;
}

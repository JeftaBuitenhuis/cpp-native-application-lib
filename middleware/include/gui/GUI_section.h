#ifndef GUI_SECTION_H
#define GUI_SECTION_H

#include "gui/GUI_renderer.h"

class GUI_section {
    private:
        int pos_x = 0;
        int pos_y = 0;

        GUI_renderer* renderer;

    public:
        uint32_t* getPixels();
        GUI_section(GUI_renderer* renderer, int pos_y, int pos_x);
        ~GUI_section();
        int getPosX();
        int getPosY();
        void update();
        void clear();
};

#endif
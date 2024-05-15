#ifndef GUI_SECTION_H
#define GUI_SECTION_H

#include "gui/module/GUI_renderer.h"
#include "gui/common/GUI_screen.h"

class GUI_section {
    private:
        int pos_x = 0;
        int pos_y = 0;

        GUI_renderer* renderer;

    public:
        GUI_screen* getScreen();
        GUI_section(GUI_renderer* renderer, int pos_y, int pos_x);
        ~GUI_section();
        int getPosX();
        int getPosY();

};

#endif
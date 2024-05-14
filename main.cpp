#include "app/application.cpp"
#include "render/renderer.cpp"

int main(void) {
    App app;
    app.init();

    Renderer renderer;
    renderer.init();

    renderer.destroy();
    app.destroy();

    return 0;
}
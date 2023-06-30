#include "Data.hpp"

#include "Drawing.hpp"

#include "Window.hpp"

#include "Text.hpp"

int main(){
    Engine::Data data;
    data.loadResources();

    Engine::Window window;

    Engine::Drawing drawing_2(data.getTexture("spritesheet.png"), window.getWindowPtr());
    drawing_2.setSpriteSheet({60, 64});
    drawing_2.setPosition({100, 0});

    Engine::Text text(window.getWindowPtr(), data.getFont("arial.ttf"));

    for(;;){
        window.drawEverything();

        text.drawTo();

        drawing_2.nextSpriteSheetAnimation();
        drawing_2.drawTo();

        window.finishDrawing();

        Sleep(50);
    }
    return 0;
}

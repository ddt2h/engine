#include "Data.hpp"

#include "Drawing.hpp"

#include "Window.hpp"

int main(){
    Engine::Data data;
    data.loadResources();

    Engine::Window window;

    Engine::Drawing drawing(data.getTexture("123.jpg"), window.getWindowPtr());
    drawing.setPosition({50, 50});
    drawing.resizeTo({100, 100});

    for(;;){
        window.drawEverything();
        drawing.drawTo();
        window.finishDrawing();
    }
    return 0;
}

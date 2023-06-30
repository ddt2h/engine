#include "Data.hpp"

#include "Drawing.hpp"

#include "Window.hpp"

#include "Text.hpp"

int main(){
    Engine::Data data;
    data.loadResources();

    Engine::Window window;

    Engine::Drawing drawing(data.getTexture("123.jpg"), window.getWindowPtr());
    drawing.setPosition({50, 50});
    drawing.resizeTo({100, 100});
    drawing.setOutline(3, sf::Color::White);

    Engine::Drawing drawing_2(data.getTexture("124.jpg"), window.getWindowPtr());
    drawing_2.setAlign(drawing, 1);

    Engine::Text text(window.getWindowPtr(), data.getFont("arial.ttf"));

    for(;;){
        window.drawEverything();
        drawing.drawTo();
        drawing_2.drawTo(data.getShader("flow.frag"));
        text.drawTo();
        window.finishDrawing();
    }
    return 0;
}

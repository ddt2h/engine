#include "Data.hpp"

#include "Drawing.hpp"

#include "Window.hpp"

#include "Text.hpp"

#include "DummyObject.hpp"

int main(){
    Engine::Data data;
    data.loadResources();

    Engine::Window window;

    DummyObject o;
    o.create(window.getWindowPtr(), &data, window.getLatestEvent());

    for(;;){
        window.drawEverything();

        o.update();
        o.draw();

        window.finishDrawing();

      //  Sleep(50);
    }
    return 0;
}

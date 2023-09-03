
#include "src/Data.hpp"
#include "src/Drawing.hpp"
#include "src/Window.hpp"
#include "src/Text.hpp"
#include "src/Timer.hpp"
#include "src/Random.hpp"

#include "Chances/Hub.hpp"

#include "src/Emulation.hpp"
#include "Replicator/Replicator.hpp"
#include "Replicator/Binder.hpp"

int main(){
    Engine::Data data;
    data.loadResources();

    Engine::Window window;
    window.setWindowSize({200, 200});  

    Hub hub;
    hub.init(&window, &data);


   Replication replica;
   // replica.addReplicationScanKey(sf::Keyboard::Key::V, DIKEYBOARD_V);
  //  replica.addReplicationScanKey(sf::Keyboard::Key::B, DIKEYBOARD_B);
    replica.initReplication(false);

  
   
    for(;;){
        window.drawEverything();
      
        replica.updateRecording(sf::Keyboard::Key::Num5, sf::Keyboard::Key::Num6);

       // hub.drawTo();

        window.finishDrawing();

        Sleep(5);
    }
    return 0;
}

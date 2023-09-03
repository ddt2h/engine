cmake_minimum_required(VERSION 3.22)
project(EngineExe)

add_executable(EngineExe WIN32
        src/Data.cpp main.cpp src/Drawing.cpp src/Window.cpp src/Text.cpp src/Entity.cpp src/AbstractEngineObject.cpp src/AbstractEngineObject.hpp src/DummyObject.cpp src/DummyObject.hpp  Game/Arena.cpp Game/Arena.hpp Game/ControlledEntity.cpp Game/ControlledEntity.hpp src/CollisionHandler.cpp src/CollisionHandler.hpp Game/HUD.cpp Game/HUD.hpp Game/HUDBar.cpp Game/HUDBar.hpp src/Timer.cpp src/Timer.hpp src/Random.cpp src/Random.hpp Chances/Hub.cpp "GUI/AbstractGui.cpp" "GUI/Button.cpp" "src/WindowsSelect.cpp" "src/Emulation.cpp" "src/SingleInput.cpp" "Replicator/Replicator.cpp" "Replicator/Binder.cpp")


target_link_libraries(EngineExe PRIVATE ${CONAN_LIBS})


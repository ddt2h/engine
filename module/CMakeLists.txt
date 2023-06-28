cmake_minimum_required(VERSION 3.22)
project(EngineExe)

add_executable(EngineExe WIN32
        src/Data.cpp src/main.cpp src/Drawing.cpp src/Window.cpp)


target_link_libraries(EngineExe PRIVATE ${CONAN_LIBS})


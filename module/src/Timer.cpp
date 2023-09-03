#include "Timer.hpp"

bool Engine::Timer::timeStamp(double seconds) {
    if (clock.getElapsedTime().asSeconds() >= seconds){
        clock.restart();
        return true;
    }
    return false;
}



Engine::Timer::Timer() {
    clock.restart();
}

float Engine::Timer::secondsPassed() {
    return clock.getElapsedTime().asSeconds();
}

#ifndef NFFSMODULE_TIMER_HPP
#define NFFSMODULE_TIMER_HPP

#include "SFML/System.hpp"

namespace Engine{
    class Timer{
    public:
        Timer();

        bool timeStamp(double seconds);

        float secondsPassed();

    private:
        sf::Clock clock;
    };
}

#endif //NFFSMODULE_TIMER_HPP

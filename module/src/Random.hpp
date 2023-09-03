#ifndef NFFSMODULE_RANDOM_HPP
#define NFFSMODULE_RANDOM_HPP

#include <random>

namespace Engine{
    class Random{
    public:
        Random() = default;

        static int getValue(int min, int max);

        static bool getChance(unsigned short percents);
    };
}


#endif //NFFSMODULE_RANDOM_HPP

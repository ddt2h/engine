#include "Random.hpp"

int Engine::Random::getValue(int min, int max) {
    std::random_device dev;
    std::mt19937 rng;
    rng.seed(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(min,max);

    return dist6(rng);
}

bool Engine::Random::getChance(unsigned short percents)
{
    return (100 - getValue(0, 100) < percents);
}

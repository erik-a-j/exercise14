#include "numberguess.hpp"
#include <random>

int NumberGuess::get_random_number(NumberGuess::Settings& settings)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, settings.maxnum);
    return dist(gen);
}
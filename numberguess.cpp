#include "numberguess.hpp"
#include <random>
#include <iostream>

int NumberGuess::get_random_number(NumberGuess::Settings& settings)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, settings.maxnum);
    return dist(gen);
}

int NumberGuess::guess(NumberGuess::Settings& settings, int randNumb)
{
    int guessNumber;

    do
    {
        std::cout << "Number: ";
        std::cin >> guessNumber;

        if(std::cin.good() && guessNumber > 0 && guessNumber <= settings.maxnum)
        {
            std::cout << "Make sure the number is valid" << std::endl;
        }

    }while(std::cin.good() && guessNumber > 0 && guessNumber <= settings.maxnum);

    if(!(guessNumber == randNumb))
    {
        settings.life = settings.life - 1;
    }

    return randNumb - guessNumber; 
    
}
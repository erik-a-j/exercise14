#include <iostream>
#include "numberguess.hpp"
#define QUITED std::cout << "\x1b[38;5;124m\nGame quited\x1b[m\n\n"

bool win_game() {
    char play = 'n';
    std::cout << "\x1b[38;5;46m\n================================\n";
    std::cout << "=========== CONGRATS ===========\n";
    std::cout << "================================\x1b[m\n\n";

    std::cout << "Do you want to play again (y/n): ";
    std::cin >> play;
    if (play == 'n')
    {
        QUITED;
        return false;
    }
    return true;
}

bool lose_game() {
    char play = 'n';
    std::cout << "\x1b[38;5;124m\n================================\n";
    std::cout << "=========== YOU LOSE ===========\n";
    std::cout << "================================\x1b[m\n\n";

    std::cout << "Do you want to play again (y/n): ";
    std::cin >> play;
    if (play == 'n')
    {
        QUITED;
        return false;
    }
    return true;
}

static void game_start() {
    std::cout << "\x1b[38;5;129m\n================================\n";
    std::cout << "========== GAME START ==========\n";
    std::cout << "================================\x1b[m\n";
}

static void game_difficulty() {
    int level = { 0 };
    std::cout << "\x1b[38;5;129m\n====== SELECT DIFFICULTY ====== \x1b[m\n";
    std::cout << "\x1b[38;5;46m1)\x1b[m Easy: \n";
    std::cout << "\x1b[38;5;46m2)\x1b[m Medium: \n";
    std::cout << "\x1b[38;5;46m3)\x1b[m Hard: \n";
    std::cout << "\x1b[38;5;46m4)\x1b[m Customized: \n";
    std::cout << "Choice: ";

    std::cin >> level;
}

int main(void) {
    NumberGuess::Game game(NumberGuess::Settings::Preset::Easy);
    while (1)
    {
        int meny = { 0 };
        std::cout << "\x1b[38;5;129m\n===============================\n";
        std::cout << "========== GAME MENY ==========\n";
        ;
        std::cout << "===============================\x1b[m\n";
        std::cout << "\x1b[38;5;46m1)\x1b[m Start game: \n";
        std::cout << "\x1b[38;5;46m2)\x1b[m Set difficuly: \n";
        std::cout << "\x1b[38;5;46m3)\x1b[m Quit game: \n";
        std::cout << "Choice: ";

        std::cin >> meny;

        switch (meny)
        {
        case 1:
            game_start();
            if (win_game() == false)
            {
                return 0;
            }
            break;

        case 2: game_difficulty();
            break;

        case 3: QUITED; return 0;
        default: break;
        }
    }
    return 0;
}
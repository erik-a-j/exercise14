#include <iostream>

int main(void)
{
    int meny = { 0 };
    std::cout << "\x1b[38;5;46m\n===============================\n";
    std::cout << "========== GAME MENY ==========\n";;
    std::cout << "===============================\x1b[m\n";
    std::cout << "\x1b[38;5;46m1)\x1b[m Start game: \n";
    std::cout << "\x1b[38;5;46m2)\x1b[m Set difficuly: \n";
    std::cout << "\x1b[38;5;46m3)\x1b[m Quit game: \n";
    std::cout << "Choice: ";

    std::cin >> meny;

    switch (meny)
    {
    case 1:
        std::cout << "\x1b[38;5;198m\n================================\n";
        std::cout << "========== GAME START ==========\n";
        std::cout << "================================\x1b[m\n";
        break;
    case 2:
        //int level = { 0 };
        std::cout << "\x1b[38;5;46m\nSelect difficulty: \x1b[m\n";
        std::cout << "1) Easy: \n";
        std::cout << "2) Medium: \n";
        std::cout << "3) Hard: \n";
        std::cout << "4) Customized: \n";
        std::cout << "Choice: ";

        //std::cin >> level;
        break;
    case 3:
        std::cout << "\nGame quited\n\n";
    default:
        break;
    }


}

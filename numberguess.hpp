#ifndef NUMBERGUESS_H
#define NUMBERGUESS_H

namespace NumberGuess {

struct Settings {
    enum class Preset {
        Easy,
        Medium,
        Hard,
    };
    int life;
    int maxnum;

    Settings(Preset preset)
    {
        set(preset);
    }
    Settings(int _life, int _maxnum) : life(_life), maxnum(_maxnum) {}
    void set(Preset preset)
    {
        if (preset == Preset::Easy)
        {
            life = 10;
            maxnum = 99;
        }
        else if (preset == Preset::Medium)
        {
            life = 5;
            maxnum = 99;
        }
        else if (preset == Preset::Hard)
        {
            life = 5;
            maxnum = 250;
        }
    }
    void set(int _life, int _maxnum)
    {
        life = _life;
        maxnum = _maxnum;
    }
};

/**
 * @brief Get the random number
 * 
 * @param settings 
 * @return int 
 */
int get_random_number(Settings& settings);

/**
 * @brief 
 * if it returns a negativ value, the guess is lower then the answer 
 * if it returns a positiv value, the guess is higher then the answer
 * if it returns 0 they guessed correctly
 * @param settings 
 * @param randNumb 
 * @return int 
 */
int guess(Settings& settings, int randNumb);

} // namespace NumberGuess

#endif /*NUMBERGUESS_H*/
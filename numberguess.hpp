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
        use_preset(preset);
    }
    void use_preset(Preset preset)
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
};

int get_random_number(Settings& settings);

/**
 * @brief 
 * 
 * @param settings 
 * @param randNumb 
 * @return int 
 */
int guess(Settings& settings, int randNumb);


} // namespace NumberGuess

#endif /*NUMBERGUESS_H*/
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

    Settings(Preset preset) { set(preset); }
    Settings(int _life, int _maxnum) : life(_life), maxnum(_maxnum) {}
    void set(Preset preset) {
        if (preset == Preset::Easy) {
            life = 10;
            maxnum = 99;
        } else if (preset == Preset::Medium) {
            life = 5;
            maxnum = 99;
        } else if (preset == Preset::Hard) {
            life = 5;
            maxnum = 250;
        }
    }
    void set(int _life, int _maxnum) {
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
bool playGame(Settings& settings, int randNumb);

class Game
{
  public:
    Game(Settings settings) : m_settings(settings) { m_secret = get_random_number(m_settings); }
    Game(Settings::Preset preset) : Game(Settings(preset)) {}
    Game(int life, int maxnum) : Game(Settings(life, maxnum)) {}

    int guess() { return NumberGuess::guess(m_settings, m_secret); }

    int life() const { return m_settings.life; }
    const Settings& settings() const { return m_settings; }
    int cheat() const { return m_secret; }

    bool playGame() { return NumberGuess::playGame(m_settings, m_secret); }

  private:
    Settings m_settings;
    int m_secret;
};

} // namespace NumberGuess

#endif /*NUMBERGUESS_H*/
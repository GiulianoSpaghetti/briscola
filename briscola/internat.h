#ifndef _INTERNAT_H_
#define _INTERNAT_H_

#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

class internat {
private:
    size_t language;
    vector<wstring> english_translations;
    vector<wstring> italian_translations;

public:
    enum LANGUAGES{INGLESE=0, ITALIANO};
    enum STRINGS { TESTING_ARM64=0, IN_DECK, CARDS, GAMED_CARD, ENDED_GAME, GAME_DROWN, YOU_WIN, YOU_LOOSE, POINTS, PLAY_SECOND_MATCH, PLAY_NEW_MATCH, OF, STICKS, CUPS, MONEY, SWORDS, PROMPT, POINTS_OF, PROMPT_CARDS, TRUMP_CARD_IS };
    internat(size_t lang);
    wstring get_translated_string(const size_t key);

};

#endif
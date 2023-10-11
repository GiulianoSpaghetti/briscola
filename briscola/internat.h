#ifndef _INTERNAT_H_
#define _INTERNAT_H_

#include <stdexcept>
#include <map>
#include <string>

class internat {
private:
    size_t language;
    std::map<size_t, std::string> english_translations =
    {
        {STRINGS::PARAMETERS_ERROR, "Must be putted two parameters: name of user and name of cpu"},
        {STRINGS::TESTING_ARM64, "for testing ARM64 c++"},
        {STRINGS::IN_DECK, "In deck are"},
        {STRINGS::CARDS, "cards"},
        {STRINGS::GAMED_CARD, "Played card"},
        {STRINGS::ENDED_GAME, "The game is over"},
        {STRINGS::GAME_DROWN, "The game was drown"},
        {STRINGS::YOU_WIN, "You win for"},
        {STRINGS::YOU_LOOSE, "Yo loosy for"},
        {STRINGS::POINTS, "points"},
        {STRINGS::PLAY_SECOND_MATCH, "Do you want to play the second match? 1: yes 0: no"},
        {STRINGS::PLAY_NEW_MATCH, "Do you want to play a new match? 1: yes 0: no"},
        {STRINGS::OF, "of"},
        {STRINGS::STICKS, "sticks"},
        {STRINGS::CUPS, "cups"},
        {STRINGS::MONEY, "money"},
        {STRINGS::SWORDS, "swords"},
        {STRINGS::POINTS_OF, "Points of"},
        {STRINGS::PROMPT_CARDS, "Cards of"},
        {STRINGS::PROMPT, "Insert the index of the card to be played"},

    };

    std::map<size_t, std::string> italian_translations =
    {
        {STRINGS::PARAMETERS_ERROR, "Bisogna passare due parametri: il nome utente ed il nome della cpu"},
        {STRINGS::TESTING_ARM64, "per testare il c++ ARM64"},
        {STRINGS::IN_DECK, "Nel mazzo rimangono"},
        {STRINGS::CARDS, "carte"},
        {STRINGS::GAMED_CARD, "Carta giocata"},
        {STRINGS::ENDED_GAME, "Partita finita"},
        {STRINGS::GAME_DROWN, "La partita é patta"},
        {STRINGS::YOU_WIN, "Hai vinto per"},
        {STRINGS::YOU_LOOSE, "Hai perso per"},
        {STRINGS::POINTS, "punti"},
        {STRINGS::PLAY_SECOND_MATCH, "Vuoi effettuare la seconda partita? 1: si 0: no"},
        {STRINGS::PLAY_NEW_MATCH, "Vuoi effettuare una nuova partita? 1: si 0: no"},
        {STRINGS::OF, "di"},
        {STRINGS::STICKS, "bastoni"},
        {STRINGS::CUPS, "coppe"},
        {STRINGS::MONEY, "denari"},
        {STRINGS::SWORDS, "spade"},
        {STRINGS::PROMPT, "Inserisci l'indice della carta da giocare"},
        {STRINGS::POINTS_OF, "Punti di"},
        {STRINGS::PROMPT_CARDS, "Carte in possesso di"},
        {STRINGS::PROMPT, "Insert the index of the card to be played"},
    };

public:
    enum LANGUAGES{INGLESE=0, ITALIANO};
    enum STRINGS { PARAMETERS_ERROR = 0, TESTING_ARM64, IN_DECK, CARDS, GAMED_CARD, ENDED_GAME, GAME_DROWN, YOU_WIN, YOU_LOOSE, POINTS, PLAY_SECOND_MATCH, PLAY_NEW_MATCH, OF, STICKS, CUPS, MONEY, SWORDS, PROMPT, POINTS_OF, PROMPT_CARDS };
    internat(size_t lang) : language(lang) { ; }
    std::string get_translated_string(const size_t key);

};

#endif
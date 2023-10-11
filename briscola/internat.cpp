#include "internat.h"

internat::internat(size_t lang) {
    language = lang;
    italian_translations = vector<wstring>();
    std::wstring s = L"per testare il c++ ARM64";
    italian_translations.push_back(s);
    s = L"Nel mazzo rimangono";

    s = L"carte";
    italian_translations.push_back(s);

    s = L"Carta giocata";
    italian_translations.push_back(s);

    s = L"Partita finita";
    italian_translations.push_back(s);

    s = L"La partita é patta";
    italian_translations.push_back(s);

    s = L"Hai vinto per";
    italian_translations.push_back(s);

    s = L"Hai perso per";
    italian_translations.push_back(s);

    s = L"punti";
    italian_translations.push_back(s);

    s = L"Vuoi effettuare la seconda partita? 1: si 0: no";
    italian_translations.push_back(s);

    s = L"Vuoi effettuare una nuova partita? 1: si 0: no";
    italian_translations.push_back(s);

    s = L"di";
    italian_translations.push_back(s);

    s = L"bastoni";
    italian_translations.push_back(s);

    s = L"coppe";
    italian_translations.push_back(s);

    s = L"denari";
    italian_translations.push_back(s);

    s = L"spade";
    italian_translations.push_back(s);

    s = L"Inserisci l'indice della carta da giocare";
    italian_translations.push_back(s);

    s = L"Punti di";
    italian_translations.push_back(s);

    s = L"Carte in possesso di";
    italian_translations.push_back(s);

    s = L"Inserisci l'indice della carta da giocare";
    italian_translations.push_back(s);

    s = L"La carta che designa il seme di briscola é";
    italian_translations.push_back(s);

    english_translations=vector<wstring>();

    s = L"for testing ARM64 c++";
    english_translations.push_back(s);
    s = L"In deck are";
    english_translations.push_back(s);
    s = L"cards";
    english_translations.push_back(s);
    s = L"Played card";
    english_translations.push_back(s);
    s = L"The game is over";
    english_translations.push_back(s);
    s = L"The game was drown";
    english_translations.push_back(s);
    s = L"You win for";
    english_translations.push_back(s);
    s = L"Yo loosy for";
    english_translations.push_back(s);
    s = L"points";
    english_translations.push_back(s);
    s = L"Do you want to play the second match? 1: yes 0: no";
    english_translations.push_back(s);
    s = L"Do you want to play a new match? 1: yes 0: no";
    english_translations.push_back(s);
    s = L"of";
    english_translations.push_back(s);
    s = L"sticks";
    english_translations.push_back(s);
    s = L"cups";
    english_translations.push_back(s);
    s = L"money";
    english_translations.push_back(s);
    s = L"swords";
    english_translations.push_back(s);
    s = L"Points of";
    english_translations.push_back(s);
    s = L"Cards of";
    english_translations.push_back(s);
    s = L"Insert the index of the card to be played";
    english_translations.push_back(s);
    s = L"The card designating trump seed is";
    english_translations.push_back(s);
}


std::wstring internat::get_translated_string(const size_t key)
{
    switch (language)
    {
    case LANGUAGES::ITALIANO:
        return italian_translations[key];

    case LANGUAGES::INGLESE:
        return english_translations[key];

    default:
        throw std::runtime_error("Unsupported language: " + std::string("unsupported language"));
    }
}
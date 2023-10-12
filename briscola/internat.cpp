#include "internat.h"

internat::internat(size_t lang) {
    language = lang;
    italian_translations = new vector<wstring>();
    std::wstring s = L"per testare il c++ ARM64";
    italian_translations->push_back(s);
    s = L"Nel mazzo rimangono";
    italian_translations->push_back(s);
    s = L"carte";
    italian_translations->push_back(s);
    s = L"Carta giocata";
    italian_translations->push_back(s);
    s = L"Partita finita";
    italian_translations->push_back(s);
    s = L"La partita é patta";
    italian_translations->push_back(s);
    s = L"Hai vinto per";
    italian_translations->push_back(s);
    s = L"Hai perso per";
    italian_translations->push_back(s);
    s = L"punti";
    italian_translations->push_back(s);
    s = L"Vuoi effettuare la seconda partita? 1: si 0: no";
    italian_translations->push_back(s);
    s = L"Vuoi effettuare una nuova partita? 1: si 0: no";
    italian_translations->push_back(s);
    s = L"di";
    italian_translations->push_back(s);
    s = L"bastoni";
    italian_translations->push_back(s);
    s = L"coppe";
    italian_translations->push_back(s);
    s = L"denari";
    italian_translations->push_back(s);
    s = L"spade";
    italian_translations->push_back(s);
    s = L"Inserisci l'indice della carta da giocare";
    italian_translations->push_back(s);
    s = L"Punti di";
    italian_translations->push_back(s);
    s = L"Carte in possesso di";
    italian_translations->push_back(s);
    s = L"La carta che designa il seme di briscola é";
    italian_translations->push_back(s);

    english_translations=new vector<wstring>();

    s = L"for testing ARM64 c++";
    english_translations->push_back(s);
    s = L"In deck are";
    english_translations->push_back(s);
    s = L"cards";
    english_translations->push_back(s);
    s = L"Played card";
    english_translations->push_back(s);
    s = L"The game is over";
    english_translations->push_back(s);
    s = L"The game was drown";
    english_translations->push_back(s);
    s = L"You win for";
    english_translations->push_back(s);
    s = L"Yo loosy for";
    english_translations->push_back(s);
    s = L"points";
    english_translations->push_back(s);
    s = L"Do you want to play the second match? 1: yes 0: no";
    english_translations->push_back(s);
    s = L"Do you want to play a new match? 1: yes 0: no";
    english_translations->push_back(s);
    s = L"of";
    english_translations->push_back(s);
    s = L"sticks";
    english_translations->push_back(s);
    s = L"cups";
    english_translations->push_back(s);
    s = L"money";
    english_translations->push_back(s);
    s = L"swords";
    english_translations->push_back(s);
    s = L"Insert the index of the card that must be played";
    english_translations->push_back(s);
    s = L"Points of";
    english_translations->push_back(s);
    s = L"Cards of";
    english_translations->push_back(s);
    s = L"The card designating trump seed is";
    english_translations->push_back(s);

   
    spanish_translations = new vector<wstring>();
    s = L"para probar c++ ARM64";
    spanish_translations->push_back(s);
    s = L"Se quedan en la baraja";
    spanish_translations->push_back(s);
    s = L"tarjetas";
    spanish_translations->push_back(s);
    s = L"Tarjeta jugada";
    spanish_translations->push_back(s);
    s = L"Juego terminado";
    spanish_translations->push_back(s);
    s = L"El juego está empatado";
    spanish_translations->push_back(s);
    s = L"Ganaste por";
    spanish_translations->push_back(s);
    s = L"Perdiste por";
    spanish_translations->push_back(s);
    s = L"puntos";
    spanish_translations->push_back(s);
    s = L"¿Quieres jugar el segundo juego? 1: sí 0: no";
    spanish_translations->push_back(s);
    s = L"¿Quieres crear un juego nuevo? 1: sí 0: no";
    spanish_translations->push_back(s);
    s = L"De";
    spanish_translations->push_back(s);
    s = L"palos";
    spanish_translations->push_back(s);
    s = L"tazas";
    spanish_translations->push_back(s);
    s = L"dinero";
    spanish_translations->push_back(s);
    s = L"espadas";
    spanish_translations->push_back(s);
    s = L"Ingresa el índice de la carta a jugar";
    spanish_translations->push_back(s);
    s = L"Puntos de";
    spanish_translations->push_back(s);
    s = L"Tarjetas en posesión de";
    spanish_translations->push_back(s);
    s = L"La carta que designa el palo de triunfo es";
    spanish_translations->push_back(s);

    french_translations = new vector<wstring>();
    s = L"pour tester c++ ARM64";
    french_translations->push_back(s);
    s = L"Ils restent dans le deck";
    french_translations->push_back(s);
    s = L"cartes";
    french_translations->push_back(s);
    s = L"Carte jouée";
    french_translations->push_back(s);
    s = L"Jeu terminé";
    french_translations->push_back(s);
    s = L"Le jeu est à égalité";
    french_translations->push_back(s);
    s = L"Vous avez gagné par";
    french_translations->push_back(s);
    s = L"Tu as perdu par";
    french_translations->push_back(s);
    s = L"points";
    french_translations->push_back(s);
    s = L"Voulez-vous jouer au deuxième jeu ? 1 : oui 0 : non";
    french_translations->push_back(s);
    s = L"Voulez-vous créer un nouveau jeu ? 1 : oui 0 : non";
    french_translations->push_back(s);
    s = L"De";
    french_translations->push_back(s);
    s = L"bâtons";
    french_translations->push_back(s);
    s = L"tasses";
    french_translations->push_back(s);
    s = L"argent";
    french_translations->push_back(s);
    s = L"épées";
    french_translations->push_back(s);
    s = L"Entrez l'index de la carte à jouer";
    french_translations->push_back(s);
    s = L"Points";
    french_translations->push_back(s);
    s = L"Cartes en possession de";
    french_translations->push_back(s);
    s = L"La carte qui désigne la couleur d'atout est";
    french_translations->push_back(s);

}


std::wstring internat::get_translated_string(const size_t key)
{
    switch (language)
    {
    case LANGUAGES::ITALIANO:
        return italian_translations->at(key);
    case LANGUAGES::SPAGNOLO:
        return spanish_translations->at(key);
    case LANGUAGES::FRANCESE:
        return french_translations->at(key);
    default:
        return english_translations->at(key);
    }
}
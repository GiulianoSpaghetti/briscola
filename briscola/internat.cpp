#include "internat.h"

std::string internat::get_translated_string(const size_t key)
{
    switch (language)
    {
    case LANGUAGES::ITALIANO:
        return italian_translations.at(key);

    case LANGUAGES::INGLESE:
        return english_translations.at(key);

    default:
        throw std::runtime_error("Unsupported language: " + std::string("unsupported language"));
    }
}
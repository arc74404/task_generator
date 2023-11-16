#include "vocabulary.hpp"

Vocabulary::Vocabulary()
{
    word_list = {"VODOVOROT", "GRAMM", "BARABAN", "MILY", "LILIPUD"};
}

std::string
Vocabulary::operator[](int index)
{
    return word_list[index];
}

int
Vocabulary::getSize()
{
    return word_list.size();
}

Vocabulary&
SingletonVocabulary::GetInstance()
{
    static Vocabulary instance;
    return instance;
}
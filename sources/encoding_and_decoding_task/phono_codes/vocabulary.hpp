#ifndef VOCABULARY_HPP
#define VOCABULARY_HPP

#include <string>
#include <vector>

class Vocabulary
{
private:
    std::vector<std::string> word_list;

public:
    Vocabulary();

    int getSize();

    std::string operator[](int index);
};

class SingletonVocabulary
{
public:
    static Vocabulary& GetInstance();

    SingletonVocabulary() = delete;

    SingletonVocabulary(const SingletonVocabulary&) = delete;

    const SingletonVocabulary& operator=(const Vocabulary&) = delete;
};

#endif // VOCABULARY_HPP
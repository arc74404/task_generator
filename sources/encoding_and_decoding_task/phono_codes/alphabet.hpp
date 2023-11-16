#ifndef ALPHABET_HPP
#define ALPHABET_HPP

#include <algorithm>
#include <iostream>
#include <numeric>
#include <shared_mutex>
#include <vector>

#include "letter.hpp"

struct Node
{
    char symbol;
    double probability;

    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

    Node(char s, double p);
};

class Alphabet
{
public:
    enum class GenerationType
    {
        SELECTIVE = 0,
        UNIFORM   = 1
    };

private:
    std::vector<char> important_letter_symbol_list;

    std::vector<Letter> letter_list;

    std::shared_ptr<Node> root;

    std::vector<std::string> available_codes;

    void randomChancesDistribute(int count, int index_start, int range_size,
                                 std::vector<float>& chance_list);

    void generateLetterList(const std::string& word, GenerationType type);

    std::shared_ptr<Node> generateTree(std::vector<Letter>& symbols, int start,
                                       int end);

    void generateCodes(std::shared_ptr<Node> node, std::string code);

    void minimizeSizeImportantLetters();

public:
    Alphabet();

    int getEncryptedWordSize(const std::string& word);

    void print();

    void generate(const std::string& word, GenerationType type);

    std::vector<Letter> getLetterList();

    std::vector<std::string> getSortAvailableCodes();
};

#endif // ALPHABET_HPP
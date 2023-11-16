#include "alphabet.hpp"

#define RAND_CHANCE float(rand() % 80 + 10) / 100

Node::Node(char s, double p)
{
    symbol      = s;
    probability = p;
    left        = nullptr;
    right       = nullptr;
}

Alphabet::Alphabet()
{
}

std::shared_ptr<Node>
Alphabet::generateTree(std::vector<Letter>& symbols, int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }

    if (start == end)
    {
        std::shared_ptr<Node> leaf = std::make_shared<Node>(
            symbols[start].getSymbol(), symbols[start].getChance());
        return leaf;
    }

    double sum = 0;
    for (int i = start; i <= end; i++)
    {
        sum += symbols[i].getChance();
    }

    double leftSum = 0;
    int splitIndex = -1;
    double minDiff = sum;
    for (int i = start; i <= end; i++)
    {
        leftSum += symbols[i].getChance();
        double rightSum = sum - leftSum;
        double diff     = abs(leftSum - rightSum);
        if (diff < minDiff)
        {
            minDiff    = diff;
            splitIndex = i;
        }
    }

    std::shared_ptr<Node> node = std::make_shared<Node>(' ', sum);

    node->left  = generateTree(symbols, start, splitIndex);
    node->right = generateTree(symbols, splitIndex + 1, end);
    return node;
}

void
Alphabet::generateCodes(std::shared_ptr<Node> node, std::string code)
{
    if (node == nullptr)
    {
        return;
    }

    if (node->left == nullptr && node->right == nullptr)
    {
        Letter a;
        a.setSymbol(node->symbol);
        a.setCode(code);
        letter_list.push_back(a);
        return;
    }

    bool b = rand() % 2;

    std::string str = {
        {char(b + '0'), char(!b + '0')}
    };

    generateCodes(node->left, code + std::string({str[0]}));
    generateCodes(node->right, code + std::string({str[1]}));
}

std::vector<char>
uniqueLetters(const std::string& word)
{
    std::vector<char> letters;

    for (char letter : word)
    {
        if (std::find(letters.begin(), letters.end(), letter) == letters.end())
        {
            letters.push_back(letter);
        }
    }

    return letters;
}

std::string
sortStringByCharacterFrequency(const std::string& str);

void
Alphabet::randomChancesDistribute(int count, int index_start, int range_size,
                                  std::vector<float>& chance_list)
{
    int r = 0;

    bool skip;

    std::vector<int> already_changed_index_list;
    while (r < count)
    {
        int index = rand() % range_size + index_start;

        skip = false;

        for (int i = 0; i < already_changed_index_list.size(); ++i)
        {
            if (index == already_changed_index_list[i])
            {
                skip = true;
                break;
            }
        }
        if (!skip)
        {
            chance_list[index] = RAND_CHANCE;

            letter_list[index].setVisibility(true);

            already_changed_index_list.emplace_back(index);
            ++r;
        }
    }
}

void
Alphabet::minimizeSizeImportantLetters()
{
    int s_i, s_j;
    for (int i = 0; i < important_letter_symbol_list.size(); ++i)
    {
        for (int j = i + 1; j < letter_list.size(); ++j)
        {
            s_i = letter_list[i].getCode().size();
            s_j = letter_list[j].getCode().size();
            if (s_i > s_j && !letter_list[j].IsVisible())
            {
                std::string c = letter_list[i].getCode();
                letter_list[i].setCode(letter_list[j].getCode());
                letter_list[j].setCode(c);
            }
        }
    }
}

void
Alphabet::generateLetterList(const std::string& word, GenerationType type)
{

    int n;

    std::vector<float> chance_list;

    if (type == GenerationType::SELECTIVE)
    {
        n = 7;

        chance_list.resize(n);

        letter_list.resize(n);

        important_letter_symbol_list =
            uniqueLetters(sortStringByCharacterFrequency(word));

        randomChancesDistribute(2, 0, important_letter_symbol_list.size(),
                                chance_list);

        int index_unimportant = rand() % (letter_list.size() -
                                          important_letter_symbol_list.size()) +
                                important_letter_symbol_list.size();

        chance_list[index_unimportant] = 2;

        letter_list[index_unimportant].setVisibility(true);

        float open_chance_sum = (rand() % 30 + 20) * 0.01;

        float multiplier =
            open_chance_sum /
            std::accumulate(chance_list.begin(), chance_list.end(), 0.f);

        for (int i = 0; i < n; ++i)
        {
            chance_list[i] = chance_list[i] * multiplier;
            if (i < important_letter_symbol_list.size())
            {
                letter_list[i].setSymbol(important_letter_symbol_list[i]);
            }
            else
            {
                char ch = rand() % ('A' - 'Z') + 'A';

                for (int j = 0; j < i; ++j)
                {
                    if (letter_list[j].getSymbol() == ch)
                    {
                        --i;
                        break;
                    }
                    if (j == i - 1)
                    {
                        letter_list[i].setSymbol(ch);
                        if (i != index_unimportant)
                        {
                            chance_list[i] = 0.00001;
                        }
                    }
                }
            }
        }

        float remaining_chance =
            1 - std::accumulate(chance_list.begin(), chance_list.end(), 0.f);

        std::string sort_word = sortStringByCharacterFrequency(word);

        int sk = 1;

        for (int i = 0; i < sort_word.size(); i += sk)
        {
            char symbol = sort_word[i];

            int count_s =
                std::count(sort_word.begin(), sort_word.end(), symbol);

            sk = count_s;

            for (int j = 0; j < letter_list.size(); ++j)
            {
                if (letter_list[j].getSymbol() == symbol &&
                    chance_list[j] == 0.f)
                {
                    chance_list[j] =
                        float(count_s) / sort_word.size() * remaining_chance;
                }
            }
        }

        int o = 0;
        o++;

        for (int i = 0; i < n; ++i)
        {
            letter_list[i].setChance(chance_list[i]);
        }
    }
    else
    {
        n = 8;

        chance_list.resize(n);

        letter_list.resize(n);

        randomChancesDistribute(n, 0, n, chance_list);

        float multiplier =
            1 / std::accumulate(chance_list.begin(), chance_list.end(), 0.f);

        for (int i = 0; i < n; ++i)
        {
            chance_list[i] = chance_list[i] * multiplier;

            letter_list[i].setSymbol('A' + i);
            letter_list[i].setChance(chance_list[i]);
            letter_list[i].setVisibility(true);
        }
    }
}

void
Alphabet::generate(const std::string& word, GenerationType type)
{
    generateLetterList(word, type);

    root = generateTree(letter_list, 0, letter_list.size() - 1);

    generateCodes(root, "");

    int count_invis = 0;

    for (int i = 0; i < letter_list.size() / 2; ++i)
    {
        std::swap(letter_list[letter_list.size() / 2 - i - 1],
                  letter_list[letter_list.size() - 1 - i]);
    }

    letter_list.resize(letter_list.size() / 2);

    if (type == GenerationType::SELECTIVE)
    {
        minimizeSizeImportantLetters();
    }
}

std::vector<Letter>
Alphabet::getLetterList()
{
    return letter_list;
}

std::vector<std::string>
Alphabet::getSortAvailableCodes()
{
    std::sort(available_codes.begin(), available_codes.end());
    return available_codes;
}

void
Alphabet::print()
{
    for (int i = 0; i < letter_list.size(); ++i)
    {
        std::cout << letter_list[i].getSymbol() << ": "
                  << letter_list[i].getCode() << '\n';
    }
}

int
Alphabet::getEncryptedWordSize(const std::string& word)
{
    int size = 0;

    for (int i = 0; i < word.size(); ++i)
    {
        for (int j = 0; j < letter_list.size(); ++j)
        {
            if (word[i] == letter_list[j].getSymbol())
            {
                size += letter_list[j].getCode().size();
            }
        }
    }
    return size;
}

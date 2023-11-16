#ifndef CONDITION_HPP
#define CONDITION_HPP

#include <iostream>
#include <string>
#include <vector>

class Condition
{
public:
    struct Variable
    {
        std::string var;

        int index;
    };

private:
    std::vector<std::string> m_text;

    std::vector<Variable> varible_list;

public:
    Condition();

    Condition(const std::string& str);

    Condition& operator=(const std::string& text);

    std::vector<std::string> getText() const;

    void print();

    void setVarible(const std::string& var, const int& index);
};

#endif // CONDITION_HPP
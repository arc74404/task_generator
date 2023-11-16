#include "condition.hpp"

Condition::Condition() : m_text(0)
{
}

Condition::Condition(const std::string& str)
{
    operator=(str);
}

std::vector<std::string>
Condition::getText() const
{
    return m_text;
}

Condition&
Condition::operator=(const std::string& text)
{
    m_text.resize(0);
    m_text.reserve(40);

    int begin = 0;

    std::string word;

    bool is_push = false;

    Variable var;

    for (int i = 0; i < text.size(); ++i)
    {
        is_push = false;

        if (text[i] == ' ')
        {
            is_push = true;
        }

        if (i == text.size() - 1)
        {
            word = text.substr(begin, i - begin + 1);

            if (word == "<<>>")
            {
                var.index = m_text.size();
                varible_list.emplace_back(var);
            }
            m_text.emplace_back(word);
        }
        else if (is_push)
        {
            word = text.substr(begin, i - begin);

            if (word != "")
            {
                if (word == "<<>>")
                {
                    var.index = m_text.size();
                    varible_list.emplace_back(var);
                }
                m_text.emplace_back(word);
            }
            begin = i + 1;
        }
    }
    return *this;
}

void
Condition::print()
{
    for (int i = 0; i < m_text.size(); ++i)
    {
        if (m_text[i] == "<<>>")
        {
            for (int j = 0; j < varible_list.size(); ++j)
            {
                if (varible_list[j].index == i)
                {
                    std::cout << varible_list[j].var << " ";
                    break;
                }
            }
        }
        else
        {
            std::cout << m_text[i] << " ";
        }
    }

    std::cout << '\n';
}

void
Condition::setVarible(const std::string& var, const int& index)
{
    if (index >= 0 && index < varible_list.size())
    {
        varible_list[index].var = var;
    }
    else
    {
        std::cout << "Condition varible could not set\n";
    }
}
#include "truth_table_task/logical_expression.hpp"

#include "truth_table_task/logical_expression_pattern_list.hpp"

LogicalExpression::LogicalExpression() : m_expression(""), m_logical_table()
{
}

void
LogicalExpression::add_default_expression()
{
    char imp_next = ' ';

    int count_letter = 2;

    if (!(rand() % 3))
    {
        m_expression.push_back('!');
    }

    m_expression.push_back('(');

    for (int i = 0; i < count_letter; ++i)
    {
        imp_next = add_letter(imp_next);

        if (i != count_letter - 1)
        {
            add_operator("&=|", 3);
        }
    }
    m_expression.push_back(')');
}

void
LogicalExpression::add_operator(char* operator_list, int size)
{
    int number = rand() % 100;

    m_expression.push_back(operator_list[rand() % size]);
}

char
LogicalExpression::add_letter(char impossible_letter)
{
    if (!(rand() % 3))
    {
        m_expression.push_back('!');
    }
    int min_c = 10;

    std::vector<LogicalVariable*> variant_list;

    for (int i = 0; i < variable_list.size(); ++i)
    {
        if (variable_list[i].getSymbol() != impossible_letter)
        {
            if (variable_list[i].count < min_c)
            {
                variant_list.clear();
                min_c = variable_list[i].count;
                variant_list.emplace_back(&variable_list[i]);
            }
            else if (variable_list[i].count == min_c)
            {
                variant_list.emplace_back(&variable_list[i]);
            }
        }
    }
    if (variant_list.size() == 0)
    {
        variant_list.emplace_back(
            &variable_list[rand() % variable_list.size()]);
    }

    int it = rand() % variant_list.size();

    variant_list[it]->count++;

    m_expression.push_back(variant_list[it]->getSymbol());
    return variant_list[it]->getSymbol();
}

void
LogicalExpression::reconfigureExpression()
{
    bool deleting = false;
    for (int i = 0; i < m_expression.size(); ++i)
    {
        if (m_expression[i] == '(' && !(rand() % 2))
        {
            deleting = true;
            m_expression.erase(m_expression.begin() + i);
        }
        if (m_expression[i] == ')' && deleting)
        {
            m_expression.erase(m_expression.begin() + i);
            deleting = false;
        }
    }
}

bool
is_nonRepeatingStrings(const std::vector<std::string>& vec)
{

    for (int i = 0; i < vec.size(); ++i)
    {
        for (int j = i + 1; j < vec.size(); ++j)
        {
            if (vec[i] == vec[j]) return false;
        }
    }
    return true;
}

bool
LogicalExpression::generateVariableValuesList()
{
    const std::vector<std::string>& _table = m_logical_table.getTable();

    char f;

    for (int i = 0; i < _table.size(); ++i)
    {
        f = _table[i][_table[i].size() - 1];

        if (f == result)
        {
            index_list.emplace_back(i);
        }
    }

    std::vector<int> index_list_2 = index_list;

    variable_values_list.resize(variable_list.size());

    int _count_iteration = 0;

    while (true)
    {
        _count_iteration++;
        if (_count_iteration >= 3)
        {
            return false;
        }
        index_list = index_list_2;

        while (index_list.size() > variable_list.size())
        {
            int j = rand() % index_list.size();

            index_list.erase(index_list.begin() + j);
        }

        for (int i = 0; i < variable_values_list.size(); ++i)
        {
            variable_values_list[i].resize(index_list.size());
            for (int j = 0; j < index_list.size(); ++j)
            {
                variable_values_list[i][j] = _table[index_list[j]][i * 2];
            }
        }

        if (!is_nonRepeatingStrings(variable_values_list))
        {
            continue;
        }

        break;
    }
    return true;
}

void
LogicalExpression::generate()
{
    pattern = pattern_command_list[rand() % pattern_command_list.size()];

    int c = 0;

regenerate:
    c++;

    if (c >= 5)
    {
        int r = 0;
        r++;
    }

    m_expression.clear();

    int count_var;
    if (pattern[0] == Command::CR_4_VAR)
    {
        count_var = 4;
    }
    else if (pattern[0] == Command::CR_3_VAR)
    {
        count_var = 3;
    }

    variable_list.resize(count_var);

    for (int i = 0; i < variable_list.size(); ++i)
    {
        variable_list[i].setSymbol('z' - i);
    }

    for (int i = 0; i < 3; ++i)
    {
        variable_list[rand() % variable_list.size()].swapSymbol(
            variable_list[rand() % variable_list.size()]);
    }

    for (int i = 1; i < pattern.size(); ++i)
    {
        if (pattern[i] == Command::ADD_EXPRESSION)
        {
            add_default_expression();
        }
        else if (pattern[i] == Command::ADD_LETTER)
        {
            add_letter();
        }
        else if (pattern[i] == Command::ADD_OPERATOR)
        {
            add_operator("|&>=", 4);
        }
        else if (pattern[i] == Command::OPEN_BRACKETS)
        {
            m_expression.push_back('(');
        }
        else if (pattern[i] == Command::CLOSE_BRACKETS)
        {
            m_expression.push_back(')');
        }
    }

    m_logical_table.build(m_expression, variable_list);

    int _count =
        m_logical_table.getCountFalse() < m_logical_table.getCountTrue()
            ? m_logical_table.getCountFalse()
            : m_logical_table.getCountTrue();

    bool f = m_logical_table.getCountFalse() < m_logical_table.getCountTrue()
                 ? 0
                 : 1;

    if (variable_list.size() == 4)
    {
        if (_count >= 5)
        {
            result = f + '0';
            if (!generateVariableValuesList())
            {
                goto regenerate;
            }
        }
        else
        {
            goto regenerate;
        }
    }
    else
    {
        if (_count >= 3)
        {
            result = f + '0';
            if (!generateVariableValuesList())
            {
                goto regenerate;
            }
        }
        else
        {
            goto regenerate;
        }
    }
}

std::string
LogicalExpression::getExpression()
{
    return m_expression;
}

int
LogicalExpression::getPriority(char op)
{
    if (op == '!') return 5;
    if (op == '&') return 4;
    if (op == '|') return 3;
    if (op == '>') return 2;
    if (op == '=') return 1;

    return 0;
}

std::string
LogicalExpression::getVariableStr()
{
    std::string str;

    for (int i = 0; i < variable_list.size(); ++i)
    {
        str.push_back(variable_list[i].getSymbol());
    }

    return str;
}

void
LogicalExpression::printFullTable()
{
    m_logical_table.print();
}

void
LogicalExpression::printSecretPart()
{

    // m_logical_table.print();
    const std::vector<std::string>& _table = m_logical_table.getTable();

    // for (int i = 0; i < variable_list.size(); ++i)
    // {
    //     std::cout << variable_list[i].getSymbol() << "|";
    // }
    std::cout << '\n';

    for (int i = 0; i < variable_list.size(); ++i)
    {
        std::cout << "*"
                  << "|";
    }
    std::cout << "f\n";

    for (int i = 0; i < variable_list.size(); ++i)
    {
        for (int j = 0; j < variable_values_list.size(); ++j)
        {
            std::cout << variable_values_list[j][i] << "|";
        }
        std::cout << result << '\n';
    }

    std::cout << '\n';

    std::cout << m_expression << '\n';
}

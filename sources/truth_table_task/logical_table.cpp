#include "truth_table_task/logical_table.hpp"

LogicalTable::LogicalTable()
{
}

void
LogicalTable::modify(std::string& expression)
{
    for (int i = 0; i < expression.size(); ++i)
    {
        if (expression[i] == '!')
        {
            expression.insert(expression.cbegin() + i, '1');
            ++i;
        }
    }
}

int
LogicalTable::getPriority(char op)
{
    if (op == '!') return 5;
    if (op == '&') return 4;
    if (op == '|') return 3;
    if (op == '>') return 2;
    if (op == '=') return 1;

    return 0;
}

bool
LogicalTable::evaluateExpression(const std::string& modified_expression)
{
    std::stack<bool> values;
    std::stack<char> operators;

    for (char c : modified_expression)
    {
        if (c == ' ') continue; // Пропускаем пробелы

        if (c == '0') values.push(false);
        else if (c == '1') values.push(true);
        else if (c == '(') operators.push(c);
        else if (c == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                char op = operators.top();
                operators.pop();

                bool operand2 = values.top();
                values.pop();

                bool operand1 = values.top();
                values.pop();

                if (op == '!') values.push(!operand2);
                else if (op == '|') values.push(operand1 || operand2);
                else if (op == '>') values.push(!operand1 || operand2);
                else if (op == '&') values.push(operand1 && operand2);
                else if (op == '=') values.push(operand1 == operand2);
            }
            operators.pop(); // Убираем '(' из стека операторов
        }
        else
        {
            while (!operators.empty() &&
                   getPriority(c) <= getPriority(operators.top()))
            {
                char op = operators.top();
                operators.pop();

                bool operand2 = values.top();
                values.pop();

                bool operand1 = values.top();
                values.pop();

                if (op == '!') values.push(!operand2);
                else if (op == '|') values.push(operand1 || operand2);
                else if (op == '>') values.push(!operand1 || operand2);
                else if (op == '&') values.push(operand1 && operand2);
                else if (op == '=') values.push(operand1 == operand2);
            }
            operators.push(c);
        }
    }

    while (!operators.empty())
    {
        char op = operators.top();
        operators.pop();

        bool operand2 = values.top();
        values.pop();

        bool operand1 = values.top();
        values.pop();

        if (op == '!') values.push(!operand2);
        else if (op == '|') values.push(operand1 || operand2);
        else if (op == '>') values.push(!operand1 || operand2);
        else if (op == '&') values.push(operand1 && operand2);
        else if (op == '=') values.push(operand1 == operand2);
    }

    return values.top();
}

void
LogicalTable::print()
{
    for (int i = 0; i < m_table.size(); ++i)
    {
        std::cout << m_table[i] << '\n';
    }
}

void
LogicalTable::build(const std::string& expression,
                    const std::vector<LogicalVariable>& variable_list)
{
    m_table.clear();
    std::string copy_expression = expression;

    modify(copy_expression);
    std::string expr = copy_expression;

    std::string str;

    for (int i = 0; i < variable_list.size(); ++i)
    {
        str.push_back(variable_list[i].getSymbol());
        str.push_back('|');
    }

    m_table.emplace_back(str);

    if (variable_list.size() == 4)
    {
        str = " | | | | ";
        for (int i1 = 0; i1 < 2; ++i1)
        {
            str[0] = '0' + i1 % 2;

            for (int i2 = 0; i2 < 2; ++i2)
            {
                str[2] = '0' + i2 % 2;
                for (int i3 = 0; i3 < 2; ++i3)
                {
                    str[4] = '0' + i3 % 2;
                    for (int i4 = 0; i4 < 2; ++i4)
                    {
                        str[6] = '0' + i4 % 2;

                        for (int l = 0; l < copy_expression.size(); ++l)
                        {
                            if (expr[l] == variable_list[0].getSymbol())
                            {
                                copy_expression[l] = str[0];
                            }
                            else if (expr[l] == variable_list[1].getSymbol())
                            {
                                copy_expression[l] = str[2];
                            }
                            else if (expr[l] == variable_list[2].getSymbol())
                            {
                                copy_expression[l] = str[4];
                            }
                            else if (expr[l] == variable_list[3].getSymbol())
                            {
                                copy_expression[l] = str[6];
                            }
                        }
                        str[8] = '0' + evaluateExpression(copy_expression);

                        m_table.push_back(str);
                    }
                }
            }
        }
    }
    else if (variable_list.size() == 3)
    {
        str = " | | | ";
        for (int i1 = 0; i1 < 2; ++i1)
        {
            str[0] = '0' + i1 % 2;

            for (int i2 = 0; i2 < 2; ++i2)
            {
                str[2] = '0' + i2 % 2;
                for (int i3 = 0; i3 < 2; ++i3)
                {
                    str[4] = '0' + i3 % 2;

                    for (int l = 0; l < copy_expression.size(); ++l)
                    {
                        if (expr[l] == variable_list[0].getSymbol())
                        {
                            copy_expression[l] = str[0];
                        }
                        else if (expr[l] == variable_list[1].getSymbol())
                        {
                            copy_expression[l] = str[2];
                        }
                        else if (expr[l] == variable_list[2].getSymbol())
                        {
                            copy_expression[l] = str[4];
                        }
                    }
                    str[6] = '0' + evaluateExpression(copy_expression);

                    m_table.push_back(str);
                }
            }
        }
    }
}

const std::vector<std::string>&
LogicalTable::getTable()
{
    return m_table;
}

int
LogicalTable::getCountFalse()
{
    int c = 0;
    for (int i = 0; i < m_table.size(); ++i)
    {
        if (m_table[i][m_table[i].size() - 1] == '0')
        {
            c++;
        }
    }
    return c;
}

int
LogicalTable::getCountTrue()
{
    int c = 0;
    for (int i = 0; i < m_table.size(); ++i)
    {
        if (m_table[i][m_table[i].size() - 1] == '1')
        {
            c++;
        }
    }
    return c;
}

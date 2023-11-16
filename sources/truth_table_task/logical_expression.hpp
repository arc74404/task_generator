#ifndef LOGICAL_EXPRESSION_HPP
#define LOGICAL_EXPRESSION_HPP

#include <iostream>
#include <string>
#include <vector>

#include "truth_table_task/logical_table.hpp"

class LogicalExpression
{
private:
    enum class Command;

    static std::vector<std::vector<LogicalExpression::Command>>
        pattern_command_list;

    std::string m_expression;

    std::vector<LogicalExpression::Command> pattern;

    std::vector<LogicalVariable> variable_list;

    LogicalTable m_logical_table;

    std::vector<int> index_list;
    std::vector<std::string> variable_values_list;

    char result;

    bool generateVariableValuesList();

    void reconfigureExpression();

    void add_operator(char* operator_list, int size);

    char add_letter(char impossible_letter = ' ');

    void add_default_expression();

    int getPriority(char op);

public:
    LogicalExpression();

    void generate();

    std::string getVariableStr();

    void printSecretPart();

    void printFullTable();

    std::string getExpression();
};

#endif // LOGICAL_EXPRESSION_HPP
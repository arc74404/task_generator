#ifndef LOGICAL_TABLE_HPP
#define LOGICAL_TABLE_HPP

#include <iostream>
#include <stack>
#include <string>
#include <vector>

#include "truth_table_task/logical_variable.hpp"

class LogicalTable
{
private:
    std::vector<std::string> m_table;

    bool evaluateExpression(const std::string& modified_expression);

    int getPriority(char op);

    void modify(std::string& expression);

public:
    LogicalTable();

    void build(const std::string& expression,
               const std::vector<LogicalVariable>& variable_list);

    void print();

    std::string& operator[](int index);

    const std::vector<std::string>& getTable();

    int getCountFalse();

    int getCountTrue();
};

#endif // LOGICAL_TABLE_HPP
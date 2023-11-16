#ifndef BUILDING_LOGICAL_TABLE_TASK_HPP
#define BUILDING_LOGICAL_TABLE_TASK_HPP

#include "task/task.hpp"
#include "truth_table_task/logical_expression.hpp"

class BuildingLogicalTableTask : public Task
{
private:
    static std::vector<std::string> m_condition_pattern_list;
    
    LogicalExpression m_expression;

    void generateConditionAndAnswer() override;

public:
    BuildingLogicalTableTask();

    void print() override;

    void generate() override;
};

#endif // BUILDING_LOGICAL_TABLE_TASK_HPP
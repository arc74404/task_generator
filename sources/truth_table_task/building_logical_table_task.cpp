#include "truth_table_task/building_logical_table_task.hpp"

#include "task/task_type.hpp"

std::vector<std::string> BuildingLogicalTableTask::m_condition_pattern_list = {
    "Determine which column of the truth table corresponds to each of the "
    "variables."};

BuildingLogicalTableTask::BuildingLogicalTableTask()
    : Task(TaskType::SECOND_BUILDING_LOGICAL_TABLE)
{
}

void
BuildingLogicalTableTask::generateConditionAndAnswer()
{
    m_condition =
        m_condition_pattern_list[rand() % m_condition_pattern_list.size()];

    m_answer_list.push_back(m_expression.getVariableStr());
}

void
BuildingLogicalTableTask::generate()
{
    m_expression.generate();

    generateConditionAndAnswer();
}

void
BuildingLogicalTableTask::print()
{
    m_expression.printSecretPart();

    std::cout << "\nCondition:\n";

    m_condition.print();

    std::cout << "\nAnswer:\n";

    print_answer();

    // m_expression.printFullTable();

    std::cout << "++++++++++++++++++++++++\n";
}

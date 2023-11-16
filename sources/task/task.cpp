#include "task.hpp"

Task::Task(TaskType task_type) : m_task_type(task_type), m_answer_list(0)
{
}

std::vector<std::string> const&
Task::getAnswer()
{
    return m_answer_list;
}

void
Task::print_answer()
{
    for (int i = 0; i < m_answer_list.size(); ++i)
    {
        std::cout << i << ": " << m_answer_list[i] << '\n';
    }
}
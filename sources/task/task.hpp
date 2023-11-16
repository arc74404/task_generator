#ifndef TASK_HPP
#define TASK_HPP

#include <shared_mutex>

#include "condition.hpp"

class Task
{
public:
    enum class TaskType;

protected:
    TaskType m_task_type;

    Condition m_condition;

    std::vector<std::string> m_answer_list;

    void print_answer();

    virtual void generateConditionAndAnswer() = 0;

public:
    Task(TaskType task_type);

    std::vector<std::string> const& getAnswer();

    virtual void print() = 0;

    virtual void generate() = 0;
};

#endif // TASK_HPP
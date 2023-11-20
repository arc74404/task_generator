#ifndef TRANSMISSION_INFORMATION_TASK_HPP
#define TRANSMISSION_INFORMATION_TASK_HPP

#include "task/task.hpp"

class TransmissionInformationTask : public Task
{
public:
    enum class TransmissionInformationTaskType;

protected:

    TransmissionInformationTaskType m_transmission_information_task_type;

    virtual void generateConditionAndAnswer() = 0;

public:
    TransmissionInformationTask(TransmissionInformationTaskType t);

    void print() override;

    void generate() override;
};

#endif // TRANSMISSION_INFORMATION_TASK_HPP
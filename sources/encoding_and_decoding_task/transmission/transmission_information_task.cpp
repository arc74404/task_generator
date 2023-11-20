#include "transmission_information_task.hpp"

#include "task/task_type.hpp"
TransmissionInformationTask::TransmissionInformationTask(
    TransmissionInformationTaskType t)
    : Task(Task::TaskType::SEVENTH_ENCODING_AND_DECODING_TRANSMISSION_TASK),
      m_transmission_information_task_type(t)
{
}

void
TransmissionInformationTask::print()
{
    m_condition.print();

    print_answer();
}

void
TransmissionInformationTask::generate()
{
    generateConditionAndAnswer();
}
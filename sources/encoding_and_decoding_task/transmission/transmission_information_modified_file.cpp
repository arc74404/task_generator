#include "transmission_information_modified_file.hpp"

#include "transmission_information_task_type.hpp"

std::vector<std::string>
    TransmissionInformationModifiedFileTask::m_condition_pattern_list = {""};

TransmissionInformationModifiedFileTask::
    TransmissionInformationModifiedFileTask()
    : TransmissionInformationTask(
          TransmissionInformationTaskType::MODIFIED_FILE)
{
}

void
TransmissionInformationModifiedFileTask::generateConditionAndAnswer()
{
    first_audio.generate();

    int total_volume_byte = after_modify_audio.generate(first_audio);

    m_answer_list.emplace_back();
}
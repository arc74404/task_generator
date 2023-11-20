#ifndef TRANSMISSION_INFORMATION_MODIFIED_FILE_TASK_HPP
#define TRANSMISSION_INFORMATION_MODIFIED_FILE_TASK_HPP

#include "audio_file_data.hpp"
#include "transmission_information_task.hpp"

class TransmissionInformationModifiedFileTask
    : public TransmissionInformationTask
{
private:
    static std::vector<std::string> m_condition_pattern_list;

    AudioFileData first_audio;

    AudioFileData after_modify_audio;

    void generateConditionAndAnswer() override;

public:
    TransmissionInformationModifiedFileTask();
};

#endif // TRANSMISSION_INFORMATION_MODIFIED_FILE_TASK_HPP
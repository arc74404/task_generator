#ifndef ENCODING_INFORMATION_HPP
#define ENCODING_INFORMATION_HPP

#include <unordered_map>

#include "task/task.hpp"

#include "alphabet.hpp"
#include "vocabulary.hpp"
#include <algorithm>


class EncodingInformationTask : public Task
{
public:
    enum class EncodingInformationTaskType;

protected:
    Alphabet m_alphabet;

    std::string m_word;

    EncodingInformationTaskType m_encoding_information_task_type;

    virtual void generateConditionAndAnswer() = 0;

public:
    EncodingInformationTask(EncodingInformationTaskType t);

    void print() override;

    void generate() override;
};

#endif // ENCODING_INFORMATION_HPP
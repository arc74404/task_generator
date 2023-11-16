#include "encoding_information_task_minimal_code_task.hpp"

#include "encoding_information_task_type.hpp"

std::vector<std::string>
    EncodingInformationMinimalCodeTask::m_condition_pattern_list = {
        "Letters: <<>> , <<>> , <<>> , <<>> , <<>> , <<>> , <<>> , <<>> "
        ";\nCodes: "
        "<<>> , <<>> , "
        "<<>> , <<>> , <<>> , <<>> , <<>> , <<>> ."};

EncodingInformationMinimalCodeTask::EncodingInformationMinimalCodeTask()
    : EncodingInformationTask(EncodingInformationTaskType::MINIMAL_CODE)
{
}

void
EncodingInformationMinimalCodeTask::generateConditionAndAnswer()
{
    m_condition =
        m_condition_pattern_list[rand() % m_condition_pattern_list.size()];

    m_alphabet.generate(m_word, Alphabet::GenerationType::UNIFORM);

    const std::vector<Letter>& l_list = m_alphabet.getLetterList();

    int random_index = rand() % l_list.size();

    for (int i = 0; i < l_list.size(); ++i)
    {
        m_condition.setVarible(std::string({l_list[i].getSymbol()}), i);

        if (i == random_index)
        {
            m_condition.setVarible("no", i + l_list.size());
        }
        else
        {
            m_condition.setVarible(l_list[i].getCode(), i + l_list.size());
        }
    }

    m_answer_list.emplace_back(l_list[random_index].getCode());
}

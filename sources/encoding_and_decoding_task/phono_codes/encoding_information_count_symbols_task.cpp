#include "encoding_information_count_symbols_task.hpp"

#include "encoding_information_task_type.hpp"

std::vector<std::string>
    EncodingInformationCountSymbolsTask::m_condition_pattern_list = {
        "Letters: <<>> , <<>> , <<>> , <<>> , <<>> , <<>> , <<>> ;\nCodes: "
        "<<>> , "
        "<<>> , <<>> , <<>> , <<>> , <<>> , <<>> .\nFind: minimal counts "
        "symbols.\nWord: <<>> ."};

EncodingInformationCountSymbolsTask::EncodingInformationCountSymbolsTask()
    : EncodingInformationTask(
          EncodingInformationTask::EncodingInformationTaskType::COUNT_SYMBOLS)
{
}

void
EncodingInformationCountSymbolsTask::generateConditionAndAnswer()
{
    m_condition =
        m_condition_pattern_list[rand() % m_condition_pattern_list.size()];

    m_alphabet.generate(m_word, Alphabet::GenerationType::SELECTIVE);

    const std::vector<Letter>& l_list = m_alphabet.getLetterList();

    for (int i = 0; i < l_list.size(); ++i)
    {
        m_condition.setVarible(std::string({l_list[i].getSymbol()}), i);

        if (l_list[i].IsVisible())
        {
            m_condition.setVarible(l_list[i].getCode(), i + l_list.size());
        }
        else
        {
            m_condition.setVarible("no", i + l_list.size());
        }
    }

    m_condition.setVarible(m_word, l_list.size() * 2);

    m_answer_list.emplace_back(
        std::to_string(m_alphabet.getEncryptedWordSize(m_word)));
}


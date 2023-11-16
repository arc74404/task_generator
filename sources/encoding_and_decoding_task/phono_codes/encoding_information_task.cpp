#include "encoding_information_task.hpp"

#include "task/task_type.hpp"

EncodingInformationTask::EncodingInformationTask(EncodingInformationTaskType t)
    : m_encoding_information_task_type(t),
      Task(Task::TaskType::FOURTH_ENCODING_AND_DECODING_TASK)
{
}

void
EncodingInformationTask::print()
{
    std::cout << "Condition:\n";
    m_condition.print();

    std::cout << '\n';
    // m_alphabet.print();

    std::cout << "Answer:\n";
    print_answer();

    std::cout << "++++++++++++++++++++++++++++++++++++++++++++\n";
}

std::string
sortStringByCharacterFrequency(const std::string& input)
{

    std::unordered_map<char, int> frequencyMap;
    for (char c : input)
    {
        frequencyMap[c]++;
    }

    std::vector<std::pair<int, char>> frequencyVector;
    for (const auto& pair : frequencyMap)
    {
        frequencyVector.push_back(std::make_pair(pair.second, pair.first));
    }

    std::sort(frequencyVector.begin(), frequencyVector.end(),
              [](const std::pair<int, char>& a, const std::pair<int, char>& b)
              { return a.first > b.first; });

    std::string output;
    for (const auto& pair : frequencyVector)
    {
        output += std::string(pair.first, pair.second);
    }

    return output;
}

void
EncodingInformationTask::generate()
{
    Vocabulary& v = SingletonVocabulary::GetInstance();

    m_word = v[rand() % v.getSize()];

    generateConditionAndAnswer();
}

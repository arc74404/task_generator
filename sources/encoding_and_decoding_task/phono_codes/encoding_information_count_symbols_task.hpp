#ifndef ENCODING_INFORMATION_COUNT_SYMBOLS_TYPE_HPP
#define ENCODING_INFORMATION_COUNT_SYMBOLS_TYPE_HPP

#include "encoding_information_task.hpp"


class EncodingInformationCountSymbolsTask : public EncodingInformationTask
{
private:
    static std::vector<std::string> m_condition_pattern_list;
	
    void generateConditionAndAnswer() override;

public:
    EncodingInformationCountSymbolsTask();
};

#endif // ENCODING_INFORMATION_COUNT_SYMBOLS_TYPE_HPP
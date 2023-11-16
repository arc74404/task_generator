#ifndef ENCODING_INFORMATION_MINIMAL_CODE_TYPE_HPP
#define ENCODING_INFORMATION_MINIMAL_CODE_TYPE_HPP

#include "encoding_information_task.hpp"


class EncodingInformationMinimalCodeTask : public EncodingInformationTask
{
private:
    static std::vector<std::string> m_condition_pattern_list;
	
    void generateConditionAndAnswer() override;

public:
    EncodingInformationMinimalCodeTask();
};

#endif // ENCODING_INFORMATION_MINIMAL_CODE_TYPE_HPP
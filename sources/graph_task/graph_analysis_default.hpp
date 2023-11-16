#ifndef GRAPH_ANALYSIS_DEFAULT_HPP
#define GRAPH_ANALYSIS_DEFAULT_HPP

#include <map>

#include "graph_task/graph_analysis.hpp"

class GraphAnalysisDefault : public GraphAnalysis
{
private:
    static std::vector<std::string> m_condition_pattern_list;

    void generateConditionAndAnswer() override;

public:
    GraphAnalysisDefault();

    void print() override;

    void generate() override;
};

#endif // GRAPH_ANALYSIS_DEFAULT_HPP
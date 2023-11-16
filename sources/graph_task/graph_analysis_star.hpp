#ifndef GRAPH_ANALYSIS_STAR_HPP
#define GRAPH_ANALYSIS_STAR_HPP

#include <map>

#include "graph_analysis.hpp"

class GraphAnalysisStar : public GraphAnalysis
{
private:
    static std::vector<std::string> m_condition_pattern_list;

    void generateConditionAndAnswer() override;

public:
    GraphAnalysisStar();

    void print() override;
};

#endif // GRAPH_ANALYSIS_STAR_HPP
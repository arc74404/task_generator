#ifndef GRAPH_ANALYSIS_MISS_ROAD_HPP
#define GRAPH_ANALYSIS_MISS_ROAD_HPP

#include <map>

#include "graph_analysis.hpp"

class GraphAnalysisMissRoad : public GraphAnalysis
{
private:
    static std::vector<std::string> m_condition_pattern_list;

    void generateConditionAndAnswer() override;

    std::pair<const Vertex*, const Vertex*> m_miss_road;

public:
    GraphAnalysisMissRoad();

    void print() override;

    void generate() override;
};

#endif // GRAPH_ANALYSIS_MISS_ROAD_HPP
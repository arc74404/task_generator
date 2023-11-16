#ifndef GRAPH_ANALYSIS_TYPE_HPP
#define GRAPH_ANALYSIS_TYPE_HPP

#include "graph_analysis.hpp"

enum class GraphAnalysis::GraphAnalysisType
{
    DEFAULT_FIRST_TASK = 0,
    STAR_GRAPH         = 1,
    MISS_ROAD          = 2
};

#endif // GRAPH_ANALYSIS_TYPE_HPP
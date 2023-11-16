#ifndef GRAPH_ANALYSIS_HPP
#define GRAPH_ANALYSIS_HPP

#include "graph_task/graph.hpp"
#include "task/task.hpp"

class GraphAnalysis : public Task
{
private:

public:
    enum class GraphAnalysisType;

protected:
    GraphAnalysisType m_graph_analysis_type;

    Graph m_graph;

    virtual void generateConditionAndAnswer() = 0;

public:
    virtual void generate() override;

    virtual void print() override;

    GraphAnalysis(GraphAnalysisType graph_analysis_type);
};

#endif // GRAPH_ANALYSIS_HPP
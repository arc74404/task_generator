#include "graph_analysis.hpp"

#include "task/task_type.hpp"

GraphAnalysis::GraphAnalysis(GraphAnalysisType graph_analysis_type)
    : m_graph_analysis_type(graph_analysis_type),
      Task(TaskType::FIRST_GRAPH_ANALYSIS), m_graph(rand() % 2 + 7)
{
}

void
GraphAnalysis::generate()
{
    m_graph.generateGraph();

    m_graph.blendNames();

    generateConditionAndAnswer();
}

void
GraphAnalysis::print()
{
    m_graph.print_default_matrix();

    m_condition.print();
}

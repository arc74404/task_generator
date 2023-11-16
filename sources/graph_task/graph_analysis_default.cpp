#include "graph_analysis_default.hpp"

#include "graph_analysis_type.hpp"

std::vector<std::string> GraphAnalysisDefault::m_condition_pattern_list = {

    std::string("Find: length between <<>> and <<>>")};

GraphAnalysisDefault::GraphAnalysisDefault()
    : GraphAnalysis(GraphAnalysis::GraphAnalysisType::DEFAULT_FIRST_TASK)
{
}

void
GraphAnalysisDefault::generateConditionAndAnswer()
{
    int text_index = rand() % m_condition_pattern_list.size();
    m_condition    = m_condition_pattern_list[text_index];

    m_answer_list.resize(1);

    std::pair<const Vertex*, const Vertex*> r_road = m_graph.getRandomRoad();

    m_answer_list[0].resize(1);

    int l = r_road.first->getLength(r_road.second->getIndex());

    m_condition.setVarible(r_road.first->getName(), 0);
    m_condition.setVarible(r_road.second->getName(), 1);

    m_answer_list[0] = std::to_string(l);
}

void
GraphAnalysisDefault::generate()
{
    GraphAnalysis::generate();

    generateConditionAndAnswer();
}

void
GraphAnalysisDefault::print()
{
    m_graph.print_default_matrix();

    std::cout << '\n' << "list: \n";
    m_graph.print_list();

    std::cout << '\n';
    std::cout << "Condition: \n";
    m_condition.print();

    std::cout << '\n';

    std::cout << "Answer: \n";
    print_answer();

    std::cout << "++++++++++++++++++++++++\n";
}
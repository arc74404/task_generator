#include "graph_analysis_miss_road.hpp"

#include "graph_analysis_type.hpp"

std::vector<std::string> GraphAnalysisMissRoad::m_condition_pattern_list = {

    std::string("Find: length of miss road")};

GraphAnalysisMissRoad::GraphAnalysisMissRoad()
    : GraphAnalysis(GraphAnalysis::GraphAnalysisType::MISS_ROAD)
{
}

void
GraphAnalysisMissRoad::generateConditionAndAnswer()
{
    int text_index = rand() % m_condition_pattern_list.size();
    m_condition    = m_condition_pattern_list[text_index];

    m_answer_list.resize(1);

    int l = m_miss_road.first->getLength(m_miss_road.second->getIndex());

    m_answer_list[0] = std::to_string(l);
}

void
GraphAnalysisMissRoad::generate()
{
    m_graph.generateGraph();
    m_graph.blendNames();

    m_miss_road = m_graph.getRandomRoad();

    generateConditionAndAnswer();
}

void
GraphAnalysisMissRoad::print()
{
    m_graph.print_default_matrix();

    std::cout << '\n' << "list: \n";
    m_graph.print_list();

    std::cout << '\n'
              << "miss road: " << m_miss_road.first->getName()
              << m_miss_road.second->getName() << '\n';

    std::cout << '\n';
    std::cout << "Condition: \n";
    m_condition.print();

    std::cout << '\n';

    std::cout << "Answer: \n";
    print_answer();

    std::cout << "++++++++++++++++++++++++\n";
}
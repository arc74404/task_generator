#include "graph_analysis_star.hpp"

#include "graph_analysis_type.hpp"

std::vector<std::string> GraphAnalysisStar::m_condition_pattern_list = {

    std::string("Find: <<>> and <<>>")};

GraphAnalysisStar::GraphAnalysisStar()
    : GraphAnalysis(GraphAnalysis::GraphAnalysisType::STAR_GRAPH)
{
}

void
GraphAnalysisStar::generateConditionAndAnswer()
{
    m_answer_list.resize(1);

    int text_index = rand() % m_condition_pattern_list.size();
    m_condition    = m_condition_pattern_list[text_index];
    char symb      = 'A' + rand() % (m_graph.getCountVertex() - 1);

    m_answer_list[0].resize(2);
    std::string str = {symb};
    m_condition.setVarible(str, 0);

    m_answer_list[0][0] = m_graph.getVertexIndex(str) + 1 + '0';

    symb++;
    str[0] = symb;
    m_condition.setVarible(str, 1);

    m_answer_list[0][1] = m_graph.getVertexIndex(str) + 1 + '0';

    if (m_answer_list[0][0] > m_answer_list[0][1])
    {
        std::swap(m_answer_list[0][0], m_answer_list[0][1]);
    }
}


void
GraphAnalysisStar::print()
{
    m_graph.print_star_matrix();

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
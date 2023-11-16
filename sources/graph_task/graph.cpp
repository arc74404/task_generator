#include "graph.hpp"

Graph::Graph(const int& n)
{
    m_vertex_list.resize(n);
}

int
Graph::getCountVertex() const
{
    return m_vertex_list.size();
}
int
Graph::getVertexIndex(const std::string& vertex_name)
{
    for (int i = 0; i < m_vertex_list.size(); ++i)
    {
        if (m_vertex_list[i].getName() == vertex_name)
        {
            return i;
        }
    }
    return -1;
}

void
Graph::initializeVertexList()
{

    char letter = 'A';

    std::string str = {letter};

    for (int i = 0; i < m_vertex_list.size(); ++i)
    {
        m_vertex_list[i].setIndex(i);
        m_vertex_list[i].setName(str);
        str[0]++;
    }
}

void
Graph::generateLinks()
{
    int count_neighbor;

    int index_neighbor;

    int length;

    int n = m_vertex_list.size();

    for (int index_vertex = 0; index_vertex < n; ++index_vertex)
    {
        count_neighbor = rand() % 2 + 1;
        if (rand() % (rand() % 2 + 4) == 0)
        {
            count_neighbor++;
        }

        while (m_vertex_list[index_vertex].getCountNeighbor() < count_neighbor)
        {
            index_neighbor = rand() % n;

            if (index_neighbor != index_vertex)
            {
                length = rand() % 90 + 5;

                m_vertex_list[index_vertex].addNeighbor(
                    &m_vertex_list[index_neighbor], length);

                m_vertex_list[index_neighbor].addNeighbor(
                    &m_vertex_list[index_vertex], length);
            }
        }
    }
}

void
Graph::generateGraph()
{
    initializeVertexList();

    generateLinks();
}

std::pair<const Vertex*, const Vertex*>
Graph::getRandomRoad()
{
    int n = m_vertex_list.size();

    int index_vertex = rand() % n;
    std::pair<const Vertex*, const Vertex*> a;

    a.first  = &m_vertex_list[index_vertex];
    a.second = m_vertex_list[index_vertex].getRandomNeighbor();

    return a;
}

void
Graph::blendNames()
{
    int n = m_vertex_list.size();

    int f_i, s_i;

    std::string str;

    for (int i = 0; i < 10; ++i)
    {
        f_i = rand() % n;
        s_i = rand() % n;

        str = m_vertex_list[f_i].getName();

        m_vertex_list[f_i].setName(m_vertex_list[s_i].getName());
        m_vertex_list[s_i].setName(str);
    }
}

void
Graph::print_default_matrix()
{
    int n = m_vertex_list.size();
    std::cout
        << "_____________________________________________________________"
           "___________________________________________________________________"
           "\n";
    for (int index_vertex = 0; index_vertex < n; ++index_vertex)
    {
        std::cout << "|";
        for (int index_neighbor = 0; index_neighbor < n; ++index_neighbor)
        {
            std::cout << "\t";
            std::cout << m_vertex_list[index_vertex].getLength(index_neighbor)
                      << "\t|";
        }

        std::cout
            << "\n_____________________________________________________________"
               "_______________________________________________________________"
               "____"
               "\n";
    }
}

void
Graph::print_star_matrix()
{
    int n = m_vertex_list.size();
    std::cout << "__________________________________________________________\n";
    for (int index_vertex = 0; index_vertex < n; ++index_vertex)
    {

        for (int index_neighbor = 0; index_neighbor < n; ++index_neighbor)
        {
            std::cout << "|  ";
            if (m_vertex_list[index_vertex].getLength(index_neighbor) > 0)
            {
                std::cout << "*";
            }
            else
            {
                std::cout << " ";
            }
            std::cout << "  ";
        }
        std::cout << "|";

        std::cout
            << "\n__________________________________________________________\n";
    }
}

void
Graph::print_list()
{
    for (int i = 0; i < m_vertex_list.size(); ++i)
    {
        m_vertex_list[i].print();
    }
}
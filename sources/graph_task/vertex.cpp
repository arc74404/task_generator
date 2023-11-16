#include "vertex.hpp"

Vertex::Vertex() : m_name(""), m_neighbor_list(0)
{
}

void
Vertex::setName(const std::string& name)
{
    m_name = name;
}
void
Vertex::setIndex(const int& index)
{
    m_index = index;
}

std::string const&
Vertex::getName() const
{
    return m_name;
}

int const&
Vertex::getIndex() const
{
    return m_index;
}

int
Vertex::getCountNeighbor() const
{
    return m_neighbor_list.size();
}

const Vertex*
Vertex::getRandomNeighbor()
{
    return m_neighbor_list[rand() % m_neighbor_list.size()];
}

void
Vertex::addNeighbor(Vertex* vertex, const int& length)
{
    int other_index = vertex->getIndex();

    for (int i = 0; i < m_neighbor_list.size(); ++i)
    {
        if (m_neighbor_list[i]->getIndex() == other_index)
        {
            return;
        }
    }
    m_neighbor_list.emplace_back(vertex);

    m_length_list.emplace_back(length);
}

int
Vertex::getLength(const int& other_index) const
{
    for (int i = 0; i < m_neighbor_list.size(); ++i)
    {
        if (m_neighbor_list[i]->getIndex() == other_index)
        {
            return m_length_list[i];
        }
    }
    return 0;
}

void
Vertex::print()
{
    for (int i = 0; i < m_neighbor_list.size(); ++i)
    {
        std::cout << "name: " << m_name << " " << m_index << " "
                  << m_neighbor_list[i]->getIndex() << " " << m_length_list[i]
                  << '\n';
    }
}
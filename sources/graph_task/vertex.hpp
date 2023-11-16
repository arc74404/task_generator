#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <iostream>
#include <string>
#include <vector>

class Vertex
{
private:
    std::string m_name;

    std::vector<Vertex*> m_neighbor_list;

    std::vector<int> m_length_list;

    int m_index;

public:
    Vertex();

    void setName(const std::string& name);

    void setIndex(const int& index);

    std::string const& getName() const;

    int const& getIndex() const;

    int getCountNeighbor() const;

    void addNeighbor(Vertex* vertex, const int& length);

    int getLength(const int& other_index) const;

    void print();

    const Vertex* getRandomNeighbor();
};

#endif // VERTEX_HPP
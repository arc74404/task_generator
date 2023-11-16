#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>

#include "vertex.hpp"

class Graph
{
private:
    std::vector<Vertex> m_vertex_list;

    void initializeVertexList();

    void generateLinks();

public:
    Graph(const int& n);

    void generateGraph();

    void blendNames();

    int getCountVertex() const;

    int getVertexIndex(const std::string& vertex_name);

    std::pair<const Vertex*, const Vertex*> getRandomRoad();

    void print_default_matrix();

    void print_star_matrix();

    void print_list();
};

#endif // GRAPH_HPP
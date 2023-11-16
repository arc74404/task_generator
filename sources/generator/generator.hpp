#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include <iostream>
#include <shared_mutex>
#include <vector>

#include "encoding_and_decoding_task/phono_codes/encoding_information_count_symbols_task.hpp"
#include "encoding_and_decoding_task/phono_codes/encoding_information_task_minimal_code_task.hpp"

#include "graph_task/graph_analysis_default.hpp"
#include "graph_task/graph_analysis_miss_road.hpp"
#include "graph_task/graph_analysis_star.hpp"
#include "truth_table_task/building_logical_table_task.hpp"

class Generator
{
private:
    std::vector<std::shared_ptr<Task>> m_task_arr;

public:
    Generator();

    void add_task(int task_number, int count);

    void print();
};

#endif // GENERATOR_HPP
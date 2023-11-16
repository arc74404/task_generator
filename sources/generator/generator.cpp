#include "generator.hpp"

#include "task/task_type.hpp"

Generator::Generator()
{
}

void
Generator::add_task(int task_number, int count = 1)
{
    std::shared_ptr<Task> t = NULL;

    float procent = 0;

    for (int i = 0; i < count; ++i)
    {
        switch (task_number)
        {
            case int(Task::TaskType::FIRST_GRAPH_ANALYSIS):

                t = NULL;

                procent = rand() % 100;
                if (procent >= 0 && procent < 33)
                {
                    t = std::make_shared<GraphAnalysisMissRoad>();
                }
                else if (procent >= 33 && procent < 66)
                {
                    t = std::make_shared<GraphAnalysisStar>();
                }
                else if (procent >= 66 && procent < 100)
                {
                    t = std::make_shared<GraphAnalysisDefault>();
                }
                t->generate();
                m_task_arr.emplace_back(t);

                break;
            case int(Task::TaskType::SECOND_BUILDING_LOGICAL_TABLE):

                t = NULL;

                t = std::make_shared<BuildingLogicalTableTask>();
                t->generate();
                m_task_arr.emplace_back(t);

            case int(Task::TaskType::FOURTH_ENCODING_AND_DECODING_TASK):
                t = NULL;

                procent = rand() % 100;

                if (procent >= 0 && procent < 50)
                {
                    t = std::make_shared<EncodingInformationCountSymbolsTask>();
                }
                else if (procent >= 50 && procent < 100)
                {
                    t = std::make_shared<EncodingInformationMinimalCodeTask>();
                }
                t->generate();
                m_task_arr.emplace_back(t);

            default:
                break;
        }
    }

    std::cout << "add_task\n";
}

void
Generator::print()
{
    for (int i = 0; i < m_task_arr.size(); ++i)
    {
        m_task_arr[i]->print();
    }
}
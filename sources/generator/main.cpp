

#include "generator.hpp"

// #define DEBUG 1

int
main()
{
    srand(time(NULL));
    Generator generator;
#if DEBUG != 1

    int task_number;
    int count;

    std::string command;

    while (true)
    {

        std::cout << "Task #: ";
        std::cin >> task_number;

        if (task_number == 0)
        {
            break;
        }

        std::cout << "Count: ";
        std::cin >> count;

        if (count == 0)
        {
            break;
        }

        generator.add_task(task_number, count);
    }
    generator.print();
#else
    EncodingInformationCountSymbolsTask task;

    task.generate();
    task.print();

#endif

    std::cout << "\n\n\n================================\nprogram finished";
    return 0;
}
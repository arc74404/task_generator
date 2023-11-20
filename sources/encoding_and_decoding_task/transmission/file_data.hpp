#ifndef FILE_DATA_HPP
#define FILE_DATA_HPP

#include <random>

class FileData
{
protected:
    int total_volume_byte;

public:
    FileData();

    virtual int generate() = 0;
};

#endif // FILE_DATA_HPP
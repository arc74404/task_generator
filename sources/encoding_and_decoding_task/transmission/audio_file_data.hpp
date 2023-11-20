#ifndef AUDIOFILE_DATA_HPP
#define AUDIOFILE_DATA_HPP
#include "file_data.hpp"

class AudioFileData : public FileData
{
private:
    int number_channels;

    int time_seconds;

    int coding_depth_bit;

    int sampling_rate;

public:
    AudioFileData();

    int generate() override;

    int generate(const AudioFileData& other);
};

#endif // AUDIOFILE_DATA_HPP
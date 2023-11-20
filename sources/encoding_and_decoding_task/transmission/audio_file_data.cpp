#include "audio_file_data.hpp"

AudioFileData::AudioFileData()
{
}

int
AudioFileData::generate()
{
    number_channels = rand() % 3;

    time_seconds = rand() % 60 + 60;

    coding_depth_bit = (rand() % 4 + 2) * 8;

    sampling_rate = (rand() % 4 + 4) * 2000;

    total_volume_byte =
        ((number_channels * time_seconds * coding_depth_bit * sampling_rate) +
         7) /
        8;

    return (total_volume_byte + 7) / 8;
}

int
AudioFileData::generate(const AudioFileData& other)
{
    this->time_seconds = other.time_seconds;

    this->number_channels = other.number_channels * (rand() % 3 + 1);

    this->coding_depth_bit = other.coding_depth_bit * (rand() % 3 + 1) / 2;

    this->sampling_rate = other.sampling_rate * (rand() % 3 + 1) / 2;

    this->total_volume_byte = ((this->number_channels * this->time_seconds *
                                this->coding_depth_bit * this->sampling_rate) +
                               7) /
                              8;

    return this->total_volume_byte;
}
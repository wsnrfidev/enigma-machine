#ifndef ROTORDATA_HPP
#define ROTORDATA_HPP

#include <iostream>
#include <vector>

class RotorData
{
private:
    std::vector<uint32_t> base;
    std::vector<uint32_t> r1;
    std::vector<uint32_t> r2;
    std::vector<uint32_t> r3;
    std::vector<uint32_t> r4;
    std::vector<uint32_t> r5;
public:
    RotorData();
    ~RotorData();

    std::vector<uint32_t> getRotorData (uint32_t code);
};

#endif
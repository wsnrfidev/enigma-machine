#include "../include/RotorData.hpp"

RotorData::RotorData()
{
    this->base = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25}; // Base 0-25 
    this->r1   = {0,1,14,3,4,5,6,7,8,19,10,11,12,13,17,15,18,2,16,9,20,21,22,23,24,25};
    this->r2   = {0,1,8,3,4,5,20,7,2,9,12,11,10,13,15,16,14,17,18,24,25,22,6,23,19,21};
    this->r3   = {1,2,0,3,16,5,6,10,8,9,7,11,12,13,14,15,17,4,18,19,23,21,20,22,24,25};
    this->r4   = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25}; // Non Operational Now
    this->r5   = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25}; // Non Operational Now
}

RotorData::~RotorData()
{
}

std::vector<uint32_t> RotorData::getRotorData (uint32_t code){
    if(code > 5 || code < 1){
        //Eror
    } 

    switch (code)
    {
    case 0:
        return this->base;
    case 1:
        return this->r1;
    case 2:
        return this->r2;
    case 3:
        return this->r3;
    case 4:
        return this->r4;
    case 5:
        return this->r5;
    default:
        break;
    }
    
    return this->base;
}
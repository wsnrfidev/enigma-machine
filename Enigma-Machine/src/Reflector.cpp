#include "../include/Reflector.hpp"

Reflector::Reflector()
{
    this->_reflectVector = {12,4,24,15,1,6,5,19,25,16,23,17,0,22,18,3,9,11,14,7,21,20,13,10,2,8};
}

Reflector::~Reflector(){}

uint32_t Reflector::reflect(uint32_t input)
{
    return this->_reflectVector.at(input);
}

std::ostream& operator<< (std::ostream& out, const Reflector& obj)
{
    uint32_t ring_size = obj._reflectVector.size();
    out << "{";
    for(uint32_t i=0; i < ring_size; ++i){
        out << obj._reflectVector.at(i);
        if(i != ring_size-1)
        {
            out <<", ";
        }
    }
    out << "}\n";
    return out;

}


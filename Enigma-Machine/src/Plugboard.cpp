#include "../include/Plugboard.hpp"


Plugboard::Plugboard()
{
    this->_plugVec = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
}

Plugboard::Plugboard(size_t code)
{
    if(code > 10 ){
    //Eror
    } 

   
    if(code == 0)
        this->_plugVec = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    else if(code == 1)
        this->_plugVec = {0,1,2,3,4,19,6,7,8,9,10,11,12,13,14,15,16,17,18,5,20,21,22,23,24,25};
    else if(code == 2)
        this->_plugVec = {0,1,9,3,4,5,6,22,8,2,10,11,12,13,14,15,16,17,18,19,20,21,7,23,24,25};
    else if(code == 3)
        this->_plugVec = {6,1,2,3,4,5,0,7,8,9,10,11,12,13,14,15,16,17,18,19,23,21,25,20,24,22};
    else if(code == 4)
        this->_plugVec = {0,1,3,2,4,5,6,15,8,9,10,11,12,21,14,7,16,20,18,19,17,13,22,23,24,25};
    else if(code == 5)
        this->_plugVec = {25,1,22,3,4,5,6,7,8,9,10,23,12,13,14,19,16,17,18,15,20,24,2,11,21,0};
    else if(code == 6)
        this->_plugVec = {0,4,2,19,1,5,6,21,10,9,8,11,12,13,16,25,14,17,18,3,20,7,22,23,24,15};
    else if(code == 7)
        this->_plugVec = {10,5,19,11,4,1,6,7,16,9,0,3,12,13,22,21,8,17,18,2,20,15,14,23,24,25};
    else if(code == 8)
        this->_plugVec = {3,1,22,0,11,19,6,25,8,13,16,4,12,9,14,15,10,17,20,5,18,21,2,23,24,7};
    else if(code == 9)
        this->_plugVec = {0,1,2,3,16,15,14,7,8,19,25,11,12,20,6,5,4,22,21,9,13,18,17,24,23,10};
    else if(code == 10)
        this->_plugVec = {9,10,12,5,24,3,6,7,18,0,1,11,2,13,23,15,22,17,8,25,21,20,16,14,4,19};
    else
        this->_plugVec = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};

}

Plugboard::Plugboard(std::vector<uint32_t> config)
{
    this->_plugVec = config;
}

Plugboard::~Plugboard()
{

}

uint32_t Plugboard::getPlug(uint32_t input)
{
    return this->_plugVec.at(input);
}

std::ostream& operator<< (std::ostream& out, const Plugboard& obj)
{
    uint32_t ring_size = obj._plugVec.size();
    out << "{";
    for(uint32_t i=0; i < ring_size; ++i){
        out << obj._plugVec.at(i);
        if(i != ring_size-1)
        {
            out <<", ";
        }
    }
    out << "}\n";
    return out;

}



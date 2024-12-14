#include "../include/Rotor.hpp"
#include "../include/RotorData.hpp"
#include "Keywords.hpp"

Rotor::Rotor()
{
    this->_data = RotorData();
    this->_inputRing = this->_data.getRotorData(0);
    this->_outputRotor = this->_data.getRotorData(1);

    this->_ringTurn = 25;
    this->_current = 0;
}

Rotor::Rotor(uint32_t rotorNum, uint32_t startPoint, uint32_t turn)
{
    this->_data = RotorData();
    this->_inputRing = this->_data.getRotorData(0);
    this->_outputRotor = this->_data.getRotorData(rotorNum);

    this->_ringTurn = turn;
    this->_current = startPoint;
}

Rotor::~Rotor()
{
}

uint32_t Rotor::step(uint32_t turns) 
{
    uint32_t ans(0);
    while (turns > 0)
    {
        ans = this->oneStep();
        turns -= 1;
    }
    return ans;
}

uint32_t Rotor::oneStep()
{
    uint32_t lastElement = 25;
    uint32_t firstElement = 0;

    uint32_t turn = 0;
    uint32_t prevNum = 0;
    uint32_t newNum = 0;
    newNum =  this->_inputRing.at(lastElement);

    while(turn < Keyword::OUT_OF_BOUND)
    {
        prevNum = this->_inputRing.at(turn);
        this->_inputRing.at(turn) = newNum;
        newNum = prevNum;
        
        turn++;
    }
    return this->_inputRing.at(firstElement);
}

uint32_t Rotor::permute(uint32_t input, bool in_out)
{
    uint32_t output = Keyword::OUT_OF_BOUND;

    if(input > 25 || input < 0)
    {
        // error
        std::cout << "Error: Bad input - input must be 0-25, while we got " << input << std::endl;
        return output;
    }

    // in_out = False :from input ring to rotor ring
    if(in_out == false)
    {
        uint32_t represent_in_input_ring = this->_inputRing.at(input);
        output = this->getIndex(represent_in_input_ring, this->_outputRotor);
    }
    else{
        int32_t represent_in_rotor_ring = this->_outputRotor.at(input);
        output = this->getIndex(represent_in_rotor_ring, this->_inputRing);
    }
    
    return output; 
}

uint32_t Rotor::getIndex(uint32_t input, const std::vector<uint32_t> vec)
{
    int32_t index = Keyword::OUT_OF_BOUND;
    for(int32_t i=0; i < vec.size(); ++i){
        if(vec.at(i) == input){
            index = i;
            break;
        }
    }
    return index;
}

std::ostream& operator<< (std::ostream& out, const Rotor& obj)
{
    int32_t ring_size = obj._inputRing.size();
    out << "" << "\n" ;
    out << "Input ring : {";
    for(int32_t i=0; i < ring_size; ++i){
        out << obj._inputRing.at(i);
        if(i != ring_size-1)
        {
            out <<", ";
        }
    }
    out << "}\n";

    out << "Output ring: {";
    for(int32_t i=0; i < ring_size; ++i){
        out << obj._outputRotor.at(i);
        if(i != ring_size-1)
        {
            out <<", ";
        }
    }
    out << "}\n";
    return out;

}






#ifndef ROTOR_HPP
#define ROTOR_HPP

#include <iostream>
#include <vector>

#include "RotorData.hpp"
#include "Keywords.hpp"

class Rotor
{
private:
    std::vector<uint32_t> _inputRing;
    std::vector<uint32_t> _outputRotor;
    uint32_t _current;
    uint32_t _ringTurn;
    RotorData _data;
public:
    Rotor();
    Rotor(uint32_t rotorNum, uint32_t startPoint, uint32_t turn);
    ~Rotor();

    /**
     * Take the input rotor one step up
     * output: the current input.at(0) => start point
    */
    uint32_t step(uint32_t turns);

    /**
     * taking input in - return its permute. 
     * if False - from input ring to rotor ring
     * if True  - from rotor ring to input ring  
    */
    uint32_t permute(uint32_t input, bool in_out);
    
    friend std::ostream& operator<< (std::ostream& out, const Rotor& obj); 

private:
    uint32_t oneStep();
    uint32_t getIndex(uint32_t intput, const std::vector<uint32_t> vec);
};



#endif
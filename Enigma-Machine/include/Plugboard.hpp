#ifndef PLUGBOARD_HPP
#define PLUGBOARD_HPP

#include <iostream>
#include <vector>

class Plugboard
{
private:
    std::vector<uint32_t> _plugVec;

public:
    Plugboard();
    Plugboard(size_t code);
    Plugboard(std::vector<uint32_t> config);
    ~Plugboard();
    
    uint32_t getPlug(uint32_t input);

    friend std::ostream& operator<< (std::ostream& out, const Plugboard& obj); 
};



#endif

#ifndef REFLECTOR_HPP
#define REFLECTOR_HPP

#include <iostream>
#include <vector>

class Reflector
{
private:
    std::vector<uint32_t> _reflectVector;

public:
    Reflector();
    ~Reflector();
    
    uint32_t reflect(uint32_t input);

    friend std::ostream& operator<< (std::ostream& out, const Reflector& obj); 
};



#endif

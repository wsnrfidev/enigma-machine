#ifndef ENIGMA_HPP
#define ENIGMA_HPP

#include "Rotor.hpp"
#include "Reflector.hpp"
#include "Plugboard.hpp"
#include "Keywords.hpp"


class Enigma
{
private:
    Rotor em_r1;
    Rotor em_r2;
    Rotor em_r3;

    Plugboard em_pb;
    Reflector em_rf;

public:
    Enigma();
    Enigma(uint32_t rotor1, uint32_t rotor2, uint32_t rotor3,
    uint32_t start1, uint32_t start2,uint32_t start3,
     uint32_t plugs, uint32_t ref);
    ~Enigma();

    void config();

    void reConfigBaseEnigma();

    uint32_t getPermute(uint32_t num);

    friend std::ostream& operator<< (std::ostream& out, const Enigma& obj); 

private:
    /**
     * Return True for succsess anf False for fail.
    */
    bool setRotor(uint32_t rotor_num_to_change, uint32_t new_rotor, uint32_t strat_point);
    bool setRef(uint32_t ref_number);
    bool setPlugboard(uint32_t plug_num);
    bool setPlugboard(std::vector<uint32_t> plugs);

};

#endif
#include "../include/Enigma.hpp"


Enigma::Enigma()
{
    this->setRotor(1, 1, 0);
    this->setRotor(2, 2, 0);
    this->setRotor(3, 3, 0);

    // stting up plugboard:
    this->setPlugboard(0);

    // setting up reflector:
    this->setRef(0);

};     
Enigma::~Enigma(){};

Enigma::Enigma(uint32_t rotor1, uint32_t rotor2, uint32_t rotor3,
    uint32_t start1, uint32_t start2,uint32_t start3,
    uint32_t plugs, uint32_t ref)
{
    // Setting up the rotors:
    this->setRotor(1, rotor1, start1);
    this->setRotor(2, rotor2, start2);
    this->setRotor(3, rotor3, start3);

    // stting up plugboard:
    this->setPlugboard(plugs);

    // setting up reflector:
    this->setRef(ref);
}

bool Enigma::setRotor(uint32_t rotor_num_to_change, uint32_t new_rotor, uint32_t strat_point)
{
    if(rotor_num_to_change == 1)
    {
        this->em_r1 = Rotor(new_rotor,strat_point,0);
    }
    else if(rotor_num_to_change == 2)
    {
        this->em_r2 = Rotor(new_rotor,strat_point,0);
    }
    else if (rotor_num_to_change == 3)
    {
        this->em_r3 = Rotor(new_rotor,strat_point,0);
    }
    else
    {
        return false;
    }
    
    return true;
}

bool Enigma::setRef(uint32_t ref_number)
{
    // ToDo: add multipul reflector Options.
    if (ref_number >= 0)
    {
        this->em_rf = Reflector();
    }
    else
    {
        return false;
    }
    return true;
}

bool Enigma::setPlugboard(uint32_t plug_num)
{
    if(plug_num <= 10)
    {
        this->em_pb = Plugboard(plug_num);
    }
    else
    {
        return false;
    }
    return true;
}

uint32_t Enigma::getPermute(uint32_t num)
{
    if(num > 25)
    {
        return Keyword::OUT_OF_BOUND;
    }
    uint32_t ans{num};
    uint32_t turn{Keyword::OUT_OF_BOUND};

    // PLug the new key word
    ans = this->em_pb.getPlug(ans);

    // permute the num throu the rotors 1->3
    ans = this->em_r1.permute(ans, false);
    ans = this->em_r2.permute(ans, false);
    ans = this->em_r3.permute(ans, false);

    // reflect ans back
    ans = this->em_rf.reflect(ans);

    // permute the num again throu rotors 3->1
    ans = this->em_r3.permute(ans, true);
    ans = this->em_r2.permute(ans, true);
    ans = this->em_r1.permute(ans, true);

    // PLug the new key word
    ans = this->em_pb.getPlug(ans);

    // update rotors
    turn = this->em_r1.step(1);
    if(turn == 0)
    {
        turn = this->em_r2.step(1);
        if(turn == 0)
        {
            turn = this->em_r3.step(1);
        }
    }

    // return ans -> EM(num)
    return ans;
}

void Enigma::reConfigBaseEnigma()
{
    this->setRotor(1, 1, 0);
    this->setRotor(2, 2, 0);
    this->setRotor(3, 3, 0);

    // stting up plugboard:
    this->setPlugboard(0);

    // setting up reflector:
    this->setRef(0);
}

std::ostream& operator<< (std::ostream& out, const Enigma& obj)
{
    out << " - - - - - - - - - - - - - - - - Rotor 1: - - - - - - - - - - - - - - - - " << obj.em_r1  << "\n";
    out << " - - - - - - - - - - - - - - - - Rotor 2: - - - - - - - - - - - - - - - - " << obj.em_r2  << "\n" ;
    out << " - - - - - - - - - - - - - - - - Rotor 3: - - - - - - - - - - - - - - - - " << obj.em_r3  << "\n" ;

    out << " - - - - - - - - - - - - - - - - Reflector: - - - - - - - - - - - - - - - \n" << "Reflector  : ";
    out << obj.em_rf  <<"\n";

    out << " - - - - - - - - - - - - - - - - Plugboard: - - - - - - - - - - - - - - - \n" << "Plugboard  : ";
    out << obj.em_pb << "\n";

    return out;

}




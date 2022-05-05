//
// Created by Kis Beni on 2022. 05. 01..
//

#ifndef PROG2_NHF_CEG_H
#define PROG2_NHF_CEG_H
#include "Bejegyzes.h"
#include <iostream>
#include <string>


class Ceg : public Bejegyzes {
    std::string cnev;
    std::string cegtipus;
public:
    Ceg() : Bejegyzes("ceg") {}
    Ceg(const std::string& szam, const std::string& cim, const std::string& cnev, const std::string& cegtipus) :Bejegyzes("ceg", szam, cim) {
        this->cnev = cnev;
        this->cegtipus = cegtipus;
    }
    std::string get_cnev() const {return cnev;}
    std::string get_cegtipus() const {return cegtipus;}

    void print() {
        std::cout << "Telefonszam: " << szam << "\nCim: " << cim
        << "\nCegnev: " << cnev << "\nCegtipus: " << cegtipus
        << std::endl;
    }
};


#endif //PROG2_NHF_CEG_H
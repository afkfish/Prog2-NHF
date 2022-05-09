//
// Created by Kis Beni on 2022. 05. 01..
//

#ifndef PROG2_NHF_SZEMELY_H
#define PROG2_NHF_SZEMELY_H
#include "Bejegyzes.h"
#include <iostream>
#include <string>

class Szemely : public Bejegyzes{
    std::string vnev;
    std::string knev;
    std::string bnev;
    std::string mszam;
public:
    Szemely() : Bejegyzes("szemely") {}
    Szemely(const std::string& szam, const std::string& cim, const std::string& vnev, const std::string& knev, const std::string& bnev, const std::string& mszam) : Bejegyzes("szemely",szam, cim) {
        this->vnev = vnev;
        this->knev = knev;
        this->bnev = bnev;
        this->mszam = mszam;
    }
    std::string get_vnev() const {return vnev;}
    std::string get_knev() const {return knev;}
    std::string get_bnev() const {return bnev;}
    std::string get_mszam() const {return mszam;}
    void print(std::ostream& os) const {
        std::cout << "Tipus: " << tipus << "\n\nVezetek nev: " << vnev
        << "\nKeresztnev: " << knev << "\nBecenev: " << bnev << "\nTelefonszam: "
        << szam << "\nCim: " << cim << "\nMunkahelyi szam: " << mszam
        << "\n---------------" << std::endl;
    }
};


#endif //PROG2_NHF_SZEMELY_H

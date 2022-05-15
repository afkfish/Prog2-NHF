//
// Created by Kis Beni on 2022. 05. 01..
//

#ifndef PROG2_NHF_SZEMELY_H
#define PROG2_NHF_SZEMELY_H
#include "Bejegyzes.h"
#include <iostream>
#include <string>

/**
 * szemely osztaly bejegyzes leszarmazottja
 */
class Szemely : public Bejegyzes{
    std::string vnev; // vezeteknev
    std::string knev; // keresztnev
    std::string bnev; // becenev
    std::string mszam; // munkahelyi szam
public:
    Szemely() : Bejegyzes("szemely") {} // default konstruktor
    /**
     * konstruktor adatokkal
     * @param szam
     * @param cim
     * @param vnev
     * @param knev
     * @param bnev
     * @param mszam
     */
    Szemely(const std::string& szam, const std::string& cim, const std::string& vnev, const std::string& knev, const std::string& bnev, const std::string& mszam) : Bejegyzes("szemely",szam, cim) {
        this->vnev = vnev;
        this->knev = knev;
        this->bnev = bnev;
        this->mszam = mszam;
    }
    /**
     * nev getter override
     * @return vnev+knev
     */
    std::string get_n() const override {return vnev + " " + knev;}
    /**
     * vnev getter
     * @return vnev
     */
    std::string get_vnev() const {return vnev;}
    /**
     * knev getter
     * @return knev
     */
    std::string get_knev() const {return knev;}
    /**
     * bnev getter
     * @return bnev
     */
    std::string get_bnev() const {return bnev;}
    /**
     * mszam getter
     * @return mszam
     */
    std::string get_mszam() const {return mszam;}
    /**
     * print override
     * @param os
     */
    void print(std::ostream& os) const override {
        os << "Tipus: " << tipus << "\n\nVezetek nev: " << vnev
        << "\nKeresztnev: " << knev << "\nBecenev: " << bnev << "\nTelefonszam: "
        << szam << "\nCim: " << cim << "\nMunkahelyi szam: " << mszam
        << "\n---------------" << std::endl;
    }
};


#endif //PROG2_NHF_SZEMELY_H

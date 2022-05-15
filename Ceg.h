//
// Created by Kis Beni on 2022. 05. 01..
//

#ifndef PROG2_NHF_CEG_H
#define PROG2_NHF_CEG_H
#include "Bejegyzes.h"
#include <iostream>
#include <string>

/**
 * ceg osztaj bejegyzes leszarmazottja
 */
class Ceg : public Bejegyzes {
    std::string cnev; //ceg neve
    std::string cegtipus; //ceg tipusa
public:
    Ceg() : Bejegyzes("ceg") {} // default kostruktor
    /**
     * kostruktor adatokkal
     * @param szam
     * @param cim
     * @param cnev
     * @param cegtipus
     */
    Ceg(const std::string& szam, const std::string& cim, const std::string& cnev, const std::string& cegtipus) :Bejegyzes("ceg", szam, cim) {
        this->cnev = cnev;
        this->cegtipus = cegtipus;
    }
    /**
     * cnev getter override
     * @return cnev
     */
    std::string get_n() const override {return cnev;}
    /**
     * cnev getter
     * @return cnev
     */
    std::string get_cnev() const {return cnev;}
    /**
     * cegtipus getter
     * @return cegtipus
     */
    std::string get_cegtipus() const {return cegtipus;}
    /**
     * print override
     * @param os
     */
    void print(std::ostream& os) const override {
        os << "Tipus: " << tipus << "\n\nCegnev: "
        << cnev << "\nTelefonszam: " << szam << "\nCim: "
        << cim << "\nCegtipus: " << cegtipus
        << "\n---------------" << std::endl;
    }
};


#endif //PROG2_NHF_CEG_H

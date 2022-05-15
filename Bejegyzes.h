//
// Created by Kis Beni on 2022. 05. 01..
//

#ifndef PROG2_NHF_BEJEGYZES_H
#define PROG2_NHF_BEJEGYZES_H
#include <iostream>
#include <string>

/**
 * bejegyzes osztaj egz bejegyzes adatainak tarolasara
 */
class Bejegyzes {
protected:
    std::string tipus; //bejegyzes tipusa
    std::string szam; //bejegyzes szama
    std::string cim; //bejegyzes cime
public:
    Bejegyzes() {} // default konstruktor
    /**
     * alap konstruktor a gyerek osztajoknak a konnyu adatfelvetel miatt
     * @param tipus
     * @param szam
     * @param cim
     */
    Bejegyzes(const std::string& tipus, const std::string& szam = "", const std::string& cim = "") {
        this->tipus = tipus;
        this->szam = szam;
        this->cim = cim;
    }
    /**
     * szam getter
     * @return szam
     */
    std::string get_szam() const {return szam;}
    /**
     * tipus getter
     * @return tipus
     */
    std::string get_tipus() const {return tipus;}
    /**
     * cim getter
     * @return cim
     */
    std::string get_cim() const {return cim;}
    /**
     * tisztan virtualis print fuggveny
     * @param os
     */
    virtual void print(std::ostream& os) const = 0;
    /**
     * gyerek osztajban szereplo nev lekerdezesere virtual getter
     * @return nev
     */
    virtual std::string get_n() const = 0;
    /**
     * destruktor
     */
    virtual ~Bejegyzes() = default;
};
/**
 * kiiro operator
 * @param os
 * @param b
 * @return ostream
 */
std::ostream& operator<<(std::ostream& os, const Bejegyzes& b);


#endif //PROG2_NHF_BEJEGYZES_H

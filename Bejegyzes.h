//
// Created by Kis Beni on 2022. 05. 01..
//

#ifndef PROG2_NHF_BEJEGYZES_H
#define PROG2_NHF_BEJEGYZES_H
#include <iostream>
#include <string>
#include <stdlib.h>

class Bejegyzes {
protected:
    int id;
    std::string tipus;
    std::string szam;
    std::string cim;
public:
    Bejegyzes() { srand(time(0)); id = rand(); }
    Bejegyzes(const std::string& tipus, const std::string& szam = "", const std::string& cim = "") {
        srand(time(0));
        id = rand();
        this->tipus = tipus;
        this->szam = szam;
        this->cim = cim;
    }
    int get_id() const {return id;}
    std::string get_szam() const {return szam;}
    std::string get_tipus() const {return tipus;}
    std::string get_cim() const {return cim;}

    virtual void print(std::ostream& os) const = 0;
    virtual std::string get_n() const = 0;
    virtual ~Bejegyzes() = default;
};
std::ostream& operator<<(std::ostream& os, const Bejegyzes& b);


#endif //PROG2_NHF_BEJEGYZES_H

//
// Created by Kis Beni on 2022. 04. 08..
//

#ifndef PROG2_NHF_TELEFONKONYV_H
#define PROG2_NHF_TELEFONKONYV_H

#include <string>
#include <iostream>
#include <fstream>
#include "Bejegyzes.h"
#include "Szemely.h"
#include "Ceg.h"
#include "memtrace.h"

class Telefonkonyv {
    static int maxu;
    int size;
    Bejegyzes *ugyfelek[0];
public:
    Telefonkonyv() :size(0) {}
    ~Telefonkonyv() {
        if(size > 0) {
            for(int i = 0 ; i < size; i++) {
                delete ugyfelek[i];
            }
        }
    }
    int get_size() const {return size;}
    void add(std::string tipus, std::string szam, std::string cim, std::string vnev, std::string knev, std::string bnev, std::string mszam, std::string cnev, std::string cegtipus);
    void del(std::string szam);
    void list() const;
    void exp(const std::string&) const;
    void imp(const std::string&);
    Bejegyzes** get_ugyfelek() {return this->ugyfelek;}
    void keres(std::string& sza) const;
};


#endif //PROG2_NHF_TELEFONKONYV_H

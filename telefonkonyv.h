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

/**
 * telefonkonyv osztaj a bejegyzesek tarolasara szolgal
 */
class Telefonkonyv {
    int size; // meret
    Bejegyzes *ugyfelek[0]; // bejegyzes lista
public:
    Telefonkonyv() :size(0) {} // default konstruktor letrehoz egy ures telefonkonyvet
    ~Telefonkonyv() { // destruktor felszabaditja a bejegyzeseket ha lett lefoglalva
        if(size > 0) {
            for(int i = 0 ; i < size; i++) {
                delete ugyfelek[i];
            }
        }
    }
    /**
     * telefonkonyv meret lekerdezes
     * @return size (int)
     */
    int get_size() const {return size;}
    void add(std::string tipus, std::string szam, std::string cim, std::string vnev, std::string knev, std::string bnev, std::string mszam, std::string cnev, std::string cegtipus);
    void del(std::string szam);
    void list() const;
    void exp(const std::string&) const;
    void imp(const std::string&);
    /**
     * egyfel lista lekerderdezes teszteknek
     * @return Bejegyzes**
     */
    Bejegyzes** get_ugyfelek() {return this->ugyfelek;}
    void keres(std::string& sza) const;
    void keresn(std::string& nev) const;
};


#endif //PROG2_NHF_TELEFONKONYV_H

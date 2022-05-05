//
// Created by Kis Beni on 2022. 04. 08..
//

#include "telefonkonyv.h"

int Telefonkonyv::maxu = 10;
void Telefonkonyv::add(std::string tipus, std::string szam, std::string cim = "", std::string vnev = "", std::string knev = "", std::string bnev = "", std::string mszam = "", std::string cnev = "", std::string cegtipus = "") {
    if(size < maxu){
        if(tipus == "szemely") {
            ugyfelek[size] = new Szemely(szam, cim, vnev, knev, bnev, mszam);
        } else if(tipus == "ceg") {
            ugyfelek[size] = new Ceg(szam, cim, cnev, cegtipus);
        } else {
            throw "nem elfogadott bejegyzes!";
        }
        size++;
    } else {
        std::cout << "A telefonkonyv megtelt!" << std::endl;
    }
}

void Telefonkonyv::del(std::string szam) {
    Bejegyzes *tmp[size-1];
    int j = 0;
    for(int i = 0; i < size; i++) {
        if(ugyfelek[i]->get_szam() != szam) {
            tmp[j] = ugyfelek[i];
            delete ugyfelek[i];
            j++;
        }
    }
    for(int i = 0; i < j; i++) {
        ugyfelek[i] = tmp[i];
    }
    size--;
}

void Telefonkonyv::list() const {
    if(size > 0) {
        for(int i = 0; i < size; i++){
            ugyfelek[i]->print();
            std::cout << std::endl;
        }
    } else {
        std::cout << "A telefonkonyv ures!" << std::endl;
    }
}

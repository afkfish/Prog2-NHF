//
// Created by Kis Beni on 2022. 04. 08..
//

#include "telefonkonyv.h"

void Telefonkonyv::add(std::string tipus, std::string szam, std::string cim, std::string vnev, std::string knev, std::string bnev, std::string mszam, std::string cnev, std::string cegtipus) {
    if(size < maxu){
        if(tipus == "szemely") {
            ugyfelek[size] = new Szemely(szam, cim, vnev, knev, bnev, mszam);
        } else if(tipus == "ceg") {
            ugyfelek[size] = new Ceg(szam, cim, cnev, cegtipus);
        }
        size++;
    } else {
        std::cout << "A telefonkonyv megtelt!" << std::endl;
    }
}

void Telefonkonyv::del(std::string szam) {
    if(size > 0) {
        Bejegyzes *tmp[size-1];
        int j = 0;
        bool found = false;
        for(int i = 0; i < size; i++) {
            if(ugyfelek[i]->get_szam() != szam or found) {
                tmp[j] = ugyfelek[i];
                j++;
            } else {
                found = true;
                delete ugyfelek[i];
            }
        }
        for(int i = 0; i < j; i++) {
            ugyfelek[i] = tmp[i];
        }
        if(!found) {
            throw std::out_of_range("");
        } else {
            size--;
        }
    } else {
        throw std::out_of_range("");
    }
}

void Telefonkonyv::list() const {
    if(size > 0) {
        for(int i = 0; i < size; i++){
            ugyfelek[i]->print(std::cout);
            std::cout << std::endl;
        }
    } else {
        std::cout << "A telefonkonyv ures!" << std::endl;
    }
}

void Telefonkonyv::exp(const std::string& f) const {
    std::ofstream file;
    file.open(f);
    file << size << std::endl;
    for(int i = 0; i < size; i++){
        std::cout << *ugyfelek[i];
        file << *ugyfelek[i];
    }
    file.close();
}

void Telefonkonyv::imp(const std::string& f) {
    int s;
    std::string egyeb;
    std::string tipus, szam, vnev, knev, cim, bnev, mszam, cnev, cegtipus;
    std::ifstream file(f);
    if(file) {
        file >> s;
        for(int i = 0; i < s; i++) {
            file >> egyeb;
            file >> tipus;
            if(tipus == "szemely") {
                file >> egyeb;
                file >> egyeb;
                file >> vnev;
                file >> egyeb;
                file >> knev;
                file >> egyeb;
                file >> bnev;
                file >> egyeb;
                file >> szam;
                file >> egyeb;
                file >> cim;
                file >> egyeb;
                file >> egyeb;
                file >> mszam;
                this->add(tipus, szam, cim, vnev, knev, bnev, mszam, "", "");
            } else if(tipus == "ceg") {
                file >> egyeb;
                file >> cnev;
                file >> egyeb;
                file >> szam;
                file >> egyeb;
                file >> cim;
                file >> egyeb;
                file >> cegtipus;
                this->add(tipus, szam, cim, "", "", "", "", cnev, cegtipus);
            } else {
                throw std::invalid_argument("");
            }
            file >> egyeb;
        }
    }
    file.close();
}

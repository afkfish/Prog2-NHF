#include "telefonkonyv.h"

/**
 * uj bejegyzes felvetele a telefonkonyvbe
 * @param tipus
 * @param szam
 * @param cim
 * @param vnev
 * @param knev
 * @param bnev
 * @param mszam
 * @param cnev
 * @param cegtipus
 */
void Telefonkonyv::add(std::string tipus, std::string szam, std::string cim, std::string vnev, std::string knev, std::string bnev, std::string mszam, std::string cnev, std::string cegtipus) {
    if(tipus == "szemely") {
        try{
            ugyfelek[size] = new Szemely(szam, cim, vnev, knev, bnev, mszam);
        } catch(std::bad_alloc&){
            std::cout << "\033[0;31mHiba tortent a bejegyzes felvetelekor\033[0m" << std::endl;
        }
    } else if(tipus == "ceg") {
        try {
            ugyfelek[size] = new Ceg(szam, cim, cnev, cegtipus);
        } catch (std::bad_alloc&) {
            std::cout << "\033[0;31mHiba tortent a bejegyzes felvetelekor\033[0m" << std::endl;
        }
    }
    size++;
}
/**
 * torles a telefonkonyvbol szam alapjan
 * @param szam
 */
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
/**
 * a bejegyzesek listazasa
 */
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
/**
 * f filenev alapjan exportalja az adatokat
 * @param f
 */
void Telefonkonyv::exp(const std::string& f) const {
    std::ofstream file;
    file.open(f);
    if(file){
        file << size << std::endl;
        for(int i = 0; i < size; i++){
            file << *ugyfelek[i];
        }
    }
    file.close();
}
/**
 * f filenev alapjan importalja az adatokat ha a fajl helyesen formazott
 * @param f
 */
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
/**
 * kereso fuggveny a telefonszamra
 * @param sza
 */
void Telefonkonyv::keres(std::string& sza) const {
    int j = 0;
    for(int i = 0; i < size; i++){
        if(ugyfelek[i]->get_szam().find(sza) != std::string::npos){
            ugyfelek[i]->print(std::cout);
            j++;
        }
    }
    if (j == 0) {
        throw std::out_of_range("");
    } else {
        std::cout << j << " db ugyfel letezik ezzel a szammal." << std::endl;
    }
}
/**
 * kereso fuggveny a nevre
 * @param nev
 */
void Telefonkonyv::keresn(std::string &nev) const {
    int j = 0;
    for(int i = 0; i < size; i++) {
        if(ugyfelek[i]->get_n().find(nev) != std::string::npos) {
            ugyfelek[i]->print(std::cout);
            j++;
        }
    }
    if (j == 0) {
        throw std::out_of_range("");
    } else {
        std::cout << j << " db ugyfel letezik ezzel a szammal." << std::endl;
    }
}

//
// Created by Kis Beni on 2022. 04. 08..
//

#ifndef PROG2_NHF_TELEFONKONYV_H
#define PROG2_NHF_TELEFONKONYV_H

#include "ugyfel.h"

class Telefonkonyv {
    static int maxu;
    Ugyfel* ugyfel;
public:
    Telefonkonyv():ugyfel(new Ugyfel[maxu]) {}
    ~Telefonkonyv() {
        delete[] ugyfel;
    }
};


#endif //PROG2_NHF_TELEFONKONYV_H

//
// Created by Kis Beni on 2022. 05. 09..
//
#include "Bejegyzes.h"

std::ostream& operator<<(std::ostream& os, const Bejegyzes& b) {
    b.print(os);
    return os;
}

//
// Created by Kis Beni on 2022. 04. 08..
//
#include "telefonkonyv.h"

int main() {

    Telefonkonyv a;

    a.add("szemely", "123", "alma", "korte", "", "barack", "1234567", "", "");

    a.add("ceg", "123456789", "nem", "", "", "", "", "orion", "informatika");

    std::cout<< a.get_size() <<std::endl;

    a.list();

    a.del("7654321");

    a.list();
    std::cout<< "Vege!" << std::endl;
}
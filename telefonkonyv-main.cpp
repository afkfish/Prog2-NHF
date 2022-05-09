//
// Created by Kis Beni on 2022. 04. 08..
//
#include "telefonkonyv.h"
#include <string>

int Telefonkonyv::maxu = 10;

int main() {
    Telefonkonyv telefonkonyv;
    bool a = true;
    while(a) {
        int command = 0;
        int ch = 9;
        std::string szam, vnev, knev, cim, bnev, mszam, cnev, cegtipus;
        std::string fi;
        std::cout << "\n"
                  << "\033[0;32m0 -> Kilepes" << std::endl
                  << "1 -> Bejegyzes hozzaadasa" << std::endl
                  << "2 -> Bejegyzes torlese" << std::endl
                  << "3 -> Bejegyzesek listazasa" << std::endl
                  << "4 -> Kereses a bejegyzesek kozott" << std::endl
                  << "5 -> Bejegyzesek exportalasa\033[0m\n" << std::endl;

        std::cin >> command;
        switch (command) {
            case 1:
                std::cout << "Bejegyzes hozzaadasa:\n" << std::endl;
                std::cout
                        << "0 -> Szemely" << std::endl
                        << "1 -> Ceg" << std::endl;
                std::cin >> ch;
                if (ch == 0) {
                    std::cout << "Szemely felvetele:\n" << std::endl;
                    std::getline(std::cin,szam);
                    std::cout << "Telefonszama:" << std::endl;
                    std::getline(std::cin,szam);
                    std::cout << "\nVezeteknev:" << std::endl;
                    std::getline(std::cin, vnev);
                    std::cout << "\nKeresztnev:" << std::endl;
                    std::getline(std::cin, knev);
                    std::cout << "\nBecenev:" << std::endl;
                    std::getline(std::cin, bnev);
                    std::cout << "\nCim:" << std::endl;
                    std::getline(std::cin, cim);
                    std::cout << "\nMunkahelyi szam:" << std::endl;
                    std::getline(std::cin, mszam);
                    telefonkonyv.add("szemely", szam, cim, vnev, knev, bnev, mszam, "", "");
                    std::cout << "\033[0;33mSzemely sikeresen felveve!\033[0m" << std::endl;
                } else if(ch == 1) {
                    std::cout << "Ceg felvetele:\n" << std::endl;
                    std::getline(std::cin,szam);
                    std::cout << "Telefonszama:" << std::endl;
                    std::getline(std::cin, szam);
                    std::cout << "\nCeg neve:" << std::endl;
                    std::getline(std::cin, cnev);
                    std::cout << "\nCeg tipusa:" << std::endl;
                    std::getline(std::cin, cegtipus);
                    std::cout << "\nCim:" << std::endl;
                    std::getline(std::cin, cim);
                    telefonkonyv.add("ceg", szam, cim, "", "", "", "", cnev, cegtipus);
                    std::cout << "\033[0;33mCeg sikeresen felveve!\033[0m" << std::endl;
                } else {
                    std::cout << "\n\033[0;31mNem elfogadott bejegyzes tipus felvetele nem lehetseges!\033[0m" << std::endl;
                }
                break;
            case 2:
                std::cout << "Bejegyzes torlese:\n" << std::endl;
                std::getline(std::cin,szam);
                std::cout << "Torlendo szam:" << std::endl;
                std::getline(std::cin, szam);
                try{
                    telefonkonyv.del(szam);
                } catch(std::out_of_range) {
                    std::cout << "\n\033[0;31mNem volt a szamnak megfelelo bejegyzes!\033[0m" << std::endl;
                }
                break;
            case 3:
                std::cout << "Bejegyzesek listazasa:\n" << std::endl;
                telefonkonyv.list();
                break;
            case 4:
                std::cout << "Kereses a bejegyzesek kozott:\n" << std::endl;
                break;
            case 5:
                std::cout << "Bejegyzesek exportalasa:\n" << std::endl;
                std::getline(std::cin, fi);
                std::cout << "Export file neve:" << std::endl;
                std::getline(std::cin, fi);
                telefonkonyv.exp(fi+".txt");
                break;
            default:
                std::cout << "\033[0;31mKilepes.\033[0m" << std::endl;
                a = false;
                break;
        }
    }
}
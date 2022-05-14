//
// Created by Kis Beni on 2022. 04. 08..
//
#include "telefonkonyv.h"
#include <string>
#include "gtest_lite.h"


int main() {
    Telefonkonyv telefonkonyv;
    bool a = true;
    while(a) {
        int command = 0;
        int ch = 9;
        std::string szam, nev, vnev, knev, cim, bnev, mszam, cnev, cegtipus;
        std::string fi;
        std::cout << "\n"
                  << "\033[0;32m0 -> Kilepes" << std::endl
                  << "1 -> Bejegyzes hozzaadasa" << std::endl
                  << "2 -> Bejegyzes torlese" << std::endl
                  << "3 -> Bejegyzesek listazasa" << std::endl
                  << "4 -> Kereses a bejegyzesek kozott" << std::endl
                  << "5 -> Bejegyzesek exportalasa" << std::endl
                  << "6 -> Bejegyzesek importalasa\033[0m\n" << std::endl;

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
                } catch(std::out_of_range&) {
                    std::cout << "\n\033[0;31mNem volt a szamnak megfelelo bejegyzes!\033[0m" << std::endl;
                }
                break;
            case 3:
                std::cout << "Bejegyzesek listazasa:\n" << std::endl;
                telefonkonyv.list();
                break;
            case 4:
                std::cout << "Kereses a bejegyzesek kozott:\n" << std::endl;
                std::cout
                        << "0 -> Telefonszam alapjan" << std::endl
                        << "1 -> Nev alapjan" << std::endl;
                std::cin >> ch;
                if(ch == 0) {
                    std::getline(std::cin,szam);
                    std::cout << "Keresendo szam:" << std::endl;
                    std::getline(std::cin, szam);
                    try{
                        telefonkonyv.keres(szam);
                    } catch(std::out_of_range&) {
                        std::cout << "\n\033[0;31mNem volt a szamnak megfelelo bejegyzes!\033[0m" << std::endl;
                    }
                } else if (ch == 1) {
                    std::getline(std::cin,nev);
                    std::cout << "Keresendo nev:" << std::endl;
                    std::getline(std::cin, nev);
                    try{
                        telefonkonyv.keresn(nev);
                    } catch(std::out_of_range&) {
                        std::cout << "\n\033[0;31mNem volt a nevnek megfelelo bejegyzes!\033[0m" << std::endl;
                    }
                } else {
                    std::cout << "\n\033[0;31mA keresesi opcio nem letezik!\033[0m" << std::endl;
                }
                break;
            case 5:
                std::cout << "Bejegyzesek exportalasa:\n" << std::endl;
                std::getline(std::cin, fi);
                std::cout << "Export file neve:" << std::endl;
                std::getline(std::cin, fi);
                telefonkonyv.exp(fi+".txt");
                break;
            case 6:
                std::cout << "Bejegyzesek importalasa:\n" << std::endl;
                std::getline(std::cin, fi);
                std::cout << "Import file neve:" << std::endl;
                std::getline(std::cin, fi);
                try {
                    telefonkonyv.imp(fi+".txt");
                } catch(std::invalid_argument&) {
                    std::cout << "\n\033[0;31mHibas az input fajl!\033[0m" << std::endl;
                }
                break;
            default:
                std::cout << "\033[0;31mKilepes.\033[0m" << std::endl;
                a = false;
                break;
        }
    }
    Telefonkonyv t;
    TEST(ADD, SZEMELY)
        t.add("szemely", "123", "cim", "vnev", "knev", "bnev", "mszam", "", "");
        EXPECT_EQ(1, t.get_size());
        EXPECT_STREQ("123", t.get_ugyfelek()[0]->get_szam().c_str());
    END

    TEST(ADD, CEG)
        t.add("ceg", "123", "cim", "", "", "", "", "cnev", "cegtipus");
        EXPECT_EQ(2, t.get_size());
        EXPECT_STREQ("cim", t.get_ugyfelek()[1]->get_cim().c_str());
    END

    TEST(DEL, TEST)
        t.del("123");
        EXPECT_EQ(1, t.get_size());
        t.del("123");
        EXPECT_EQ(0, t.get_size());
    END
}
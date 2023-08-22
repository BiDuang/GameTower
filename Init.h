//
// Created by Jiarong on 2023/8/22.
//

#ifndef GAMETOWER_INIT_H
#define GAMETOWER_INIT_H

#include <iostream>
#include <fstream>

bool checkProfileExist() {
    std::ifstream fin("profile.dat");
    if (fin) {
        return true;
    } else {
        return false;
    }

}

void init() {
    if (checkProfileExist()) {
        std::cout << "��⵽�浵���Ƿ��ȡ�浵��(Y/N)" << std::endl;
        char choice;
        std::cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            // ��ȡ�浵
        } else {
            std::cout << "���ڴ����´浵..." << std::endl;
            std::ofstream fout("profile.dat");
            fout << time(NULL) << std::endl;

        }
    }
}


#endif //GAMETOWER_INIT_H

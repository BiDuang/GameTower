//
// Created by Jiarong on 2023/8/21.
//

//A MUD Game

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include <iostream>
#include <fstream>
#include "Interface.h"

using std::cout, std::cin, std::endl, std::ifstream, std::string;
using namespace PosControl;

void welcome() {
    centerWindow();

    cout << "����Tab��������ӭ����" << endl << endl;
    ifstream welcomeFile("../Assets/.welcome");
    char welcome;
    bool flagTab = false;
    while (welcomeFile.get(welcome)) {
        if (GetAsyncKeyState(VK_TAB)) {
            flagTab = true;
        }
        if (!flagTab) Sleep(20);
        cout << welcome;

    }
    welcomeFile.close();

    cout << "\t\t";
    for (int i = 0; i < 6 * 2; i++) {
        Sleep(50);
        cout << ".";
    }
    cout << endl;

    int x, y;
    getPos(x, y);
    int spaceLength = (screen_width / 12 * 4 / 5 - 88) / 2;
    string space(spaceLength, ' ');
    while (1) {
        setPos(x, y);
        ifstream logoFile("../Assets/.logo");
        string logo;
        while (getline(logoFile, logo)) {
            int color = rand() % 15 + 1;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
            Sleep(50);
            cout << space;
            cout << logo << endl;
        }
        logoFile.close();
//        Sleep(1000);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << endl << "���»س�������..." << endl;
        if (GetAsyncKeyState(VK_RETURN)) {
            cin.get();
            break;
        }
    }
}

void printSwitcher() {
    // ����Ϸ ������Ϸ �˳���Ϸ
    // ʹ��ͻ����ɫ��ʾ��ǩ �����»��߱�ʾ��ݼ�
    // 1. ����Ϸ
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "\t";
    cout << "1. ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << "����Ϸ" << endl;

    // 2. ������Ϸ
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "\t";
    cout << "2. ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << "������Ϸ" << endl;

    // 3. �˳���Ϸ
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "\t";
    cout << "3. ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << "�˳���Ϸ" << endl;

    // switch
    cout << endl << endl;
    cout << "\t" << "��������ѡ��";
}

int switcher() {
    int switch_x, switch_y;
    getPos(switch_x, switch_y);
    int choice;
    switch_choice:
    setPos(switch_x, switch_y);
    cout << "                                                          ";
    setPos(switch_x, switch_y);
    cin >> choice;
    if (choice != 1 && choice != 2 && choice != 3) {
        cout << "\t" << "����������������룺";
        return switcher();
    }
    return choice;
}

int main() {
    welcome();
    printSwitcher();
    switch (switcher()) {
        case 1:
            // ����Ϸ
            break;
        case 2:
            // ������Ϸ
            break;
        case 3:
            // �˳���Ϸ
            return 0;
    }
    system("cls");
    system("pause");
    return 0;
}

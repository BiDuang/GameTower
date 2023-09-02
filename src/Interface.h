//
// Created by Jiarong on 2023/8/22.
//

#ifndef GAMETOWER_INTERFACE_H
#define GAMETOWER_INTERFACE_H

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <random>
//#include "utils\\rand.h"

using std::cout, std::cin, std::endl, std::ifstream, std::string;

int randInt(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

namespace PosControl {

    int screen_width = GetSystemMetrics(SM_CXSCREEN);
    int screen_height = GetSystemMetrics(SM_CYSCREEN);

    // ���ڳ���
    struct Size {
        int width;
        int height;
    } size = {1020, 860};

    void centerWindow() {
        HWND hwnd = GetForegroundWindow();
        SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, size.width, size.height, 1);
        MoveWindow(hwnd, (screen_width - size.width) / 2, (screen_height - size.height) / 2, size.width, size.height,
                   1);
    }

// �ص�����λ�ã�������Ҫ����
    void setPos(int x, int y) {
        COORD coord{static_cast<SHORT>(y), static_cast<SHORT>(x)};
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);  //�ص�����������λ�ý����������
    }


// ��ȡ��ǰ��׼�����λ��
    void getPos(int &x, int &y) {
        CONSOLE_SCREEN_BUFFER_INFO b;           // ��������̨��Ļ����������Ϣ
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &b);    //  ��ȡ��׼������
        y = b.dwCursorPosition.X;
        x = b.dwCursorPosition.Y;
    }


}

void setDPI() {
    system("SetDpi.exe value > currDPI.txt");
    system("SetDpi.exe 150");
}

struct Menu {
    string name;
};

void welcomePage() {

    PosControl::centerWindow();

    cout << "���� \033[31m[Tab��] \033[0m��������..." << endl << endl;
    ifstream welcomeFile("./Assets/.welcomePage");
    char welcome;
    bool flagTab = false;
    while (welcomeFile.get(welcome)) {
        if(kbhit()) {
            char c;
            c = getch();
            if (c == '\t') {
                flagTab = true;
            }
        }
        if (!flagTab) Sleep(50);
        cout << welcome;
    }
    welcomeFile.close();

    cout << endl << endl;
    for (int i = 0; i < 103; i++) {
        Sleep(5);
        cout << "=";
    }
    cout << endl << endl;

    int x, y;
    PosControl::getPos(x, y);
    int spaceLength = std::max((PosControl::size.width / 10 - 88) / 2 + 2, 0);
    string space(spaceLength, ' ');
    while (1) {
        PosControl::setPos(x, y);
        ifstream logoFile("./Assets/.logo");
        string logo;
        while (getline(logoFile, logo)) {
            int color = randInt(1, 15);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
            Sleep(50);
            cout << space << logo << endl;
        }
        logoFile.close();

        cout << endl << "\033[0m���� \033[31m[Enter��] \033[0m����..." << endl;

        if(kbhit()){
            char c;
            c = getch();
            if (c == '\r' || c == '\n') {
                PosControl::setPos(x+7, 0);
                return;
            }
        }
    }
}

int switcher() {

    Menu menu[3]{
            "����Ϸ",
            "������Ϸ",
            "�˳���Ϸ"
    };

    cout << "=======================================================================================================" << endl;
    cout << endl;
    int x, y;
    PosControl::getPos(x, y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

    for (int i = 0; i < 3; i++) {
        cout << "    > " << menu[i].name << endl;
    }
    cout << endl;
    cout << "=======================================================================================================" << endl;

    char c;
    int choice = 0;
    int prevChoice = 0;

    while (1) {

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        PosControl::setPos(x + prevChoice, y);
        cout << "    > " << menu[prevChoice].name;

        PosControl::setPos(x + choice, y);
        cout << "\33[43;37m" << "    > " << menu[choice].name << "\33[0m";
        c = getch();
        switch (c) {
            case 'w':
            case 'W':
            case 72: // 72���ϼ�ͷ
                prevChoice = choice;
                choice = (choice + 3 - 1) % 3;
                break;
            case 's':
            case 'S':
            case 80: // 80���¼�ͷ
                prevChoice = choice;
                choice = (choice + 1) % 3;
                break;
            case '\r':
            case '\n':
                return choice;
            default:
                prevChoice = choice;
                break;
        }
    }
}

void goodbye() {
    // TODO: exit page
    cout << "exit page" << endl;
}

#endif //GAMETOWER_INTERFACE_H

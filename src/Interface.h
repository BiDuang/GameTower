//
// Created by Jiarong on 2023/8/22.
//

#ifndef GAMETOWER_INTERFACE_H
#define GAMETOWER_INTERFACE_H

#include <windows.h>

namespace PosControl {

    int screen_width = GetSystemMetrics(SM_CXSCREEN);
    int screen_height = GetSystemMetrics(SM_CYSCREEN);
// x����Ļ��ȣ�y����Ļ�߶�

    void centerWindow() {
        HWND hwnd = GetForegroundWindow();
        SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, screen_width, screen_height, NULL);
        MoveWindow(hwnd, screen_width / 10, screen_height / 10, screen_width * 4 / 5, screen_height * 4 / 5, 1);
    }

// �ص�����λ�ã�������Ҫ����
    void setPos(int x, int y) {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);  //�ص�����������λ�ý����������
    }


// ��ȡ��ǰ��׼�����λ��
    void getPos(int &x, int &y) {
        CONSOLE_SCREEN_BUFFER_INFO b;           // ��������̨��Ļ����������Ϣ
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &b);    //  ��ȡ��׼������
        x = b.dwCursorPosition.X;
        y = b.dwCursorPosition.Y;
    }

}

#endif //GAMETOWER_INTERFACE_H

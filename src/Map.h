//
// Created by Jiarong on 2023/8/21.
//

#ifndef GAMETOWER_MAP_H
#define GAMETOWER_MAP_H

#include "Location.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Interface.h"

using std::cout;
using std::endl;

class Map {
public:
    Map();
    ~Map() = default;
    static void printMap();
    Location *getLocation(int line, int column) const { return locations[line][column]; }

private:
    Location *locations[10][10]{};
};

Map::Map() {

    for (int i = 0; i <= 9; i++)
        for (int j = 0; j <= 9; j++)
            locations[i][j] = new Location();

    locations[8][4] = new Place("У��", 34, 50);
    locations[7][4] = new Road(true);
    locations[6][4] = new Place("ӭ�´���", 26, 50);
    locations[5][4] = new Road(true);
    locations[4][4] = new Place("�칦�����", 18, 50, true);
    locations[3][4] = new Road(true);
    locations[2][4] = new Place("ʥ̳", 8, 52);
    locations[4][2] = new Place("սǰ׼��Ӫ��",19, 13 ,true);
    locations[4][3] = new Road(false);
    locations[4][5] = new Road(true);
    locations[4][6] = new Place("���ܻ�����", 18, 84);
    locations[2][5] = new Road(true);
    locations[2][6] = new Place("���ص�ħ��Ĺ��", 6, 84);
}

void Map::printMap(){
    system("cls");
    PosControl::setPos(0, 0);
    std::ifstream mapFile("./Assets/.map");
    char map;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    while (mapFile.get(map)) {
        cout << map;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    mapFile.close();

    //dyed the roads with grey
    PosControl::setPos(0, 0);
    std::ifstream pathFile("./Assets/.map_path");
    char path;
    while (pathFile.get(path)) {
        if (path != ' ') {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
            cout << path;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        } else if (path == '\n') {
            cout << endl;
        } else {
            cout << "\033[1C";
        }
    }
    pathFile.close();

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    cout << "\033[34;50HУ��";
    cout << "\033[26;50Hӭ�´���";
    cout << "\033[18;50H�칦�����";
    cout << "\033[8;52Hʥ̳";
    cout << "\033[19;13Hսǰ׼��Ӫ��";
    cout << "\033[18;84H���ܻ�����";
    cout << "\033[6;84H���ص�ħ��Ĺ��";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    PosControl::setPos(0, 0);
}


#endif //GAMETOWER_MAP_H

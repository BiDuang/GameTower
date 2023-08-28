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
    void printMap() const;
private:
    Location *locations[10][10]{};
};

Map::Map() {

    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
            locations[i][j] = new Location();

    locations[8][4]=new Place("У��");
    locations[7][4]=new Road(true);
    locations[6][4]=new Place("ӭ�´���");
    locations[5][4]=new Road(true);
    locations[4][4]=new Place("�칦�����", true);
    locations[3][4]=new Road(true);
    locations[2][4]=new Place("ʥ̳");
    locations[4][2]=new Place("սǰ׼��Ӫ��", true);
    locations[4][3]=new Road(false);
    locations[4][5]=new Road(true);
    locations[4][6]=new Place("���ܻ�����");
    locations[2][5]=new Road(true);
    locations[2][6]=new Place("���ص�ħ��Ĺ��");
}

void Map::printMap() const {

    std::ifstream mapFile("./Assets/.map");
    // print the map
    char map;
    while (mapFile.get(map)) {
        cout << map;
    }
    mapFile.close();
    // print the locations
    PosControl::setPos(1, 1);
    // TODO: ƥ���ͼλ��
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (locations[i][j]->isPlace()) {
                cout << std::setw(10) << std::left << static_cast<Place *>(locations[i][j])->getName();
            } else {
                cout << std::setw(10) << std::left << " ";
            }
        }
        cout << endl;
    }
}


#endif //GAMETOWER_MAP_H

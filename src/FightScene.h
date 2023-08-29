//
// Created by xiao on 2023-08-21.
//

#ifndef GAMETOWER1_FIGHT_SCENE_H
#define GAMETOWER1_FIGHT_SCENE_H

#include <vector>
#include "Monster.h"
//#include "Player.h"
#include "Interface.h"
#include "Word.h"


class FightScene {
public:
    FightScene(string name): name(name){}
    void loadScene(std::vector<Word> wordList);
    void showScene();//��ͣ����չʾ������
    void drop();//���ַ�
    void fight();//Ч�������
    void showTutorial();//չʾ�̳�
private:
    Monster monster;//��������ԵĹ���
    std::string name;

};

void FightScene::loadScene(std::vector<Word> wordList) {
    showScene();

}

void FightScene::showScene() {
    system("cls");
    PosControl::setPos(0,1);
    for(int i=0;i<101;i++) {
        cout<<'=';
    }
    PosControl::setPos(1,0);
    for(int i=0;i<36;i++) {
        cout<<'|'<<'\n';
    }

    for(int i=0;i<36;i++) {
        PosControl::setPos(1+i,101);
        cout<<'|';
    }
    PosControl::setPos(35,1);
    for(int i=0;i<101;i++) {
        cout<<'=';
    }
    PosControl::setPos(0,0);
    cout<<'*';
    PosControl::setPos(0,101);
    cout<<'*';
    PosControl::setPos(35,0);
    cout<<'*';
    PosControl::setPos(35,101);
    cout<<'*';
    PosControl::setPos(16,1);
    for(int i=0;i<101;i++) {
        cout<<'=';
    }
    PosControl::setPos(21,1);
    for(int i=0;i<101;i++) {
        cout<<'=';
    }

//    getch();
}

#endif //GAMETOWER1_FIGHT_SCENE_H

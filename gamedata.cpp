#include "gamedata.h"


int GameData::getGame(){
    return Game;
}
int GameData::getStatus(){
    return status;
}
int GameData::getX(){
    return x;
}
int GameData::getY(){
    return y;
}
QString GameData::getMsg(){

    return msg;

}
void GameData:: setGame(int Games){
  Game=Games;
}

void GameData:: setStatus(int stat){
    status=stat;
}

void GameData:: setX(int rx){
    x=rx;
}

void GameData:: setY(int ry){
    y=ry;
}

void GameData:: setMsg(QString msgs){
  msg=msgs;
}
void GameData::setNext(bool nexts){
 next=nexts;
}
bool GameData::getNext(){
return next;
}

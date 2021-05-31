#include "netwowrk.h"
Netwowrk::Netwowrk(){

   connect(&tcpsocket,SIGNAL(readyRead()),this,SLOT(RecGameData()));

}
void Netwowrk::SendGameData(GameData data){
   QJsonObject object;
   object.insert("Game",data.getGame());
   object.insert("status",data.getStatus());
   object.insert("x",data.getX());
   object.insert("y",data.getY());
   object.insert("msg",data.getMsg());
   QJsonDocument docment;
   docment.setObject(object);
    QByteArray dataArray = docment.toJson();
    tcpsocket.write(dataArray);

}
QString Netwowrk::FindServer(QHostAddress ip,quint16 port){
   QString info="GameServer is connceted!";
    tcpsocket.connectToHost(ip,port);
    return info;
}
void Netwowrk::RecGameData(){
   isGame=true;
   QByteArray byte= tcpsocket.readAll();
   QJsonDocument doc=QJsonDocument::fromJson(byte,&error);
   recdata= doc.object();

}


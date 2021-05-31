#ifndef NETWOWRK_H
#define NETWOWRK_H
#include<QTcpSocket>
#include<QJsonObject>
#include<QJsonDocument>
#include <QHostAddress>
#include<QObject>
#include <gamedata.h>
class Netwowrk:public QObject
{
  Q_OBJECT

  private:
     QString info;
     QTcpSocket tcpsocket;


  public:
     bool isGame=true;
     /**游戏接收数据
     * @brief recdata
     */
    QJsonObject recdata;
    /**检查连接状态
     * @brief conncet_status
     */
    bool conncet_status=false;
    /**解析错误i
     * @brief error
     */
    QJsonParseError error;
    /**统计次数
     * @brief count_rectime
     */
    int count_rectime=0;
  public:
    Netwowrk();
    void SendGameData(GameData data);
    QString FindServer(QHostAddress ip,quint16 port);
    bool IsConncet();
  public slots:
    void RecGameData();
};

#endif // NETWOWRK_H

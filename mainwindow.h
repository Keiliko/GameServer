#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>
#include<QPoint>
#include<QDebug>
#include<math.h>
#include<chess.h>
#include<QMessageBox>
#include <QJsonObject>
#include<netwowrk.h>
#include<QHostAddress>
#include<QJsonDocument>
#include<gamedata.h>
#define kuan 900
#define gao 900
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
   void paintEvent(QPaintEvent *event);

   void mousePressEvent(QMouseEvent *event);
   void DrawGameMap();
   void PlayChess();
   void CheckGameOver();
   void GameDataController();
   void ClearChess();
   /**存储棋子
    * @brief chesses
    */
   QList<Chess> chesses;
private slots:
   void on_ConncetServer_clicked();

   void on_StartGame_clicked();

   void on_palyer_select_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;

    /**Jason 数据用于封装游戏数据
     * @brief gamedata
     */
    QJsonObject gamedata;
    /**网络socket数据传输
     * @brief network
     */
    Netwowrk network;
    GameData data;
    int pos[16][16]={{0}};

    /** 0 代表游戏结束 1 palyer_1回合 2 palyer_2回合 3代表未开始
     *
     * @brief Game
     */
    int Game=3;
    /**1 代表执黑棋 2 代表执白棋
     * @brief status
     */
    int status=0;
    int jianju=kuan/15;
};



#endif // MAINWINDOW_H

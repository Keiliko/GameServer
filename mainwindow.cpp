#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include<QPen>
#include<QThread>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;

}
void MainWindow::GameDataController(){
   int RecGame=network.recdata.value("Game").toInt();
   int RecStat=network.recdata.value("status").toInt();
   int RecX=network.recdata.value("x").toInt();
   int RecY=network.recdata.value("y").toInt();
   QString RecMsg=network.recdata.value("msg").toString();
   if(RecX>0&&RecY>0){
       if(pos[RecX/60][RecY/60]==0){
           Game=RecGame;
           QPoint point;
           point.setX(RecX);
           point.setY(RecY);
           Chess chess;
           chess.setPoint(point);
           chess.setStatus(RecStat);
           chesses.append(chess);
       }
   }

}

void MainWindow::paintEvent(QPaintEvent *event){
   event->Pointer;
   DrawGameMap();
   if(Game==0){
       data.setGame(0);

    if(data.getStatus()==1){
        QMessageBox::warning(this,"Title","黑棋获胜");
        Game=3;
    }
    if(data.getStatus()==2){
        QMessageBox::warning(this,"Title","白棋获胜");
        Game=3;
    }
    data.setStatus(status);
    ClearChess();
    network.SendGameData(data);
    Game=3;
   }
   if(Game==1){
       PlayChess();
       GameDataController();
       CheckGameOver();
       update();
   }
  if(Game==3){
      ui->StartGame->setEnabled(true);
  }

}

void MainWindow::CheckGameOver(){
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++){
             if(pos[i][j]==status&&pos[i][j+1]==status&&pos[i][j+2]&&pos[i][j+3]==status&&pos[i][j+4]&&pos[i][j+4]==status){
                  Game=0;

                  break;
             }
             if(pos[i][j]==status&&pos[i+1][j]==status&&pos[i+2][j]==status&&pos[i+3][j]&&pos[i+4][j]==status){
                 Game=0;
                 break;
             }
             if(pos[i][j]==status&&pos[i+1][j+1]==status&&pos[i+2][j+2]==status&&pos[i+3][j+3]==status&&pos[i+4][j+4]==status){
                 Game=0;
                 break;
             }
             if(pos[i][j]==status&&pos[i+1][j-1]==status&&pos[i+2][j-2]==status&&pos[i+3][j-3]==status&&pos[i+4][j-4]==status){
                 Game=0;break;
             }
        }
    }

}

void MainWindow::DrawGameMap(){


  QPainter painter(this);

  painter.setPen(QPen(QColor(Qt::black),2));
  painter.setBrush(Qt::yellow);
  for(int i=kuan/15;i<=kuan-15;i+=kuan/15){
      painter.drawLine(QPoint(i,kuan/15),QPoint(i,gao-kuan/15-2));
      painter.drawLine(QPoint(gao/15,i),QPoint(kuan-gao/15-2,i));
  }

}

void MainWindow::PlayChess(){
    QPainter painter(this);

    for(int i=0;i<chesses.length();i++){
         if(chesses[i].status==1){

             painter.setBrush(Qt::black);
              painter.drawEllipse(chesses[i].getpoint(),24,24);
         }
         if(chesses[i].status==2){
             painter.setPen(QPen(QColor(Qt::white),2));
             painter.setBrush(Qt::white);
             painter.drawEllipse(chesses[i].getpoint(),24,24);
         }
    }
}
void MainWindow::mousePressEvent(QMouseEvent *event){
    qDebug()<<Game;
   if(Game==1){
       if(network.isGame){
           Chess chess;
           QPoint point_mouse;
           int chazhi_x=(event->pos().x()+10)%60;
           int chazhi_y=(event->pos().y()+10)%60;

           /*坐标系第二区*/
           if(chazhi_x<20&&chazhi_y<20){
               point_mouse.setX(event->pos().x()-chazhi_x+10);
               point_mouse.setY(event->pos().y()-chazhi_y+10);
               /*检测是否重复*/
              if( pos[point_mouse.x()/60][point_mouse.y()/60]==0){
                  pos[point_mouse.x()/60][point_mouse.y()/60]=status;
                  chess.setPoint(point_mouse);
                  data.setX(point_mouse.x());
                  data.setY(point_mouse.y());
                  data.setStatus(status);
                  chess.setStatus(status);
                  chesses.append(chess);
                  network.SendGameData(data);
                  network.isGame=false;
                  data.setNext(false);
              }else{
                  return;
              }

           }
           else
           {
               return;
           }
       }

   }
}

void MainWindow::on_ConncetServer_clicked()
{
    QHostAddress address;
    address.setAddress(ui->ip->text());
    qint16 port=ui->port->text().toInt();
    QString info= network.FindServer(address,port);
    ui->info->append(info);

}

void MainWindow::on_StartGame_clicked()
{
    Game=1;
    ClearChess();
    data.setMsg("gaming");
    data.setGame(Game);
    data.setX(-1);
    data.setY(-1);
    ui->StartGame->setEnabled(false);
    ui->ConncetServer->setEnabled(false);
    network.SendGameData(data);
}


void MainWindow::on_palyer_select_currentIndexChanged(int index)
{
    status=index;
    qDebug()<<status;
    qDebug()<<data.getGame();
    qDebug()<<"--------------";
}

void MainWindow::ClearChess(){
   for(int i=0;i<16;i++){
      for(int j=0;j<16;j++){
         pos[i][j]=0;
      }
   }
    chesses.clear();
}


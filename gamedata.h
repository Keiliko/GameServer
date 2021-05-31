#ifndef GAMEDATA_H
#define GAMEDATA_H
#include<QString>

class GameData
{

   public:

      int getGame();
      int getStatus();
      int getX();
      int getY();
      bool getNext();
      QString getMsg();
      void setGame(int Games);
      void setStatus(int stat);
      void setX(int rx);
      void setY(int ry);
      void setMsg(QString msg);
      void setNext(bool nexts);
   private:
      /**Game游戏状态
       * @brief Game
       */
      int Game=3;
      /**黑白棋
       * @brief status
       */
      int status=0;
      /**x坐标
       * @brief x
       */
      int x=-999;
      /**y坐标
       * @brief y
       */
      int y=-999;
      /**信息
       * @brief msg
       */

      QString msg="";
      /**
       * 是否可以下一步
       * @brief next
       */
      int next=true;
};

#endif // GAMEDATA_H

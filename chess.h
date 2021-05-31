#ifndef CHESS_H
#define CHESS_H
#include<QPoint>


class Chess
{
public:
   QPoint point;
   /**
    * @brief status
    * 0 代表未下，1代表白方，2代表黑方
    */
   int status;
public:
   void setPoint(QPoint pos);
   void setStatus(int stas);
   QPoint getpoint();
   int getStatus();
};

#endif // CHESS_H

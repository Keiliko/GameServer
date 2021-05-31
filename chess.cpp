#include "chess.h"

void Chess::setPoint(QPoint pos){
   point=pos;
}
void Chess::setStatus(int stas){
    status=stas;
}
QPoint Chess::getpoint(){
  return point;
}
int Chess::getStatus(){
  return status;
}

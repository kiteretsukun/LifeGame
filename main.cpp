#include "all.h"
#include "board.h"
#include "nextboard.h"
#include "currentboard.h"

int main(){

    //初期状態を設定するBoard
    life_game::CurrentBoard* currentboard = new life_game::CurrentBoard() ;
    currentboard->setInit() ;
    currentboard->show() ;

    //次世代を計算し、計算結果を格納するBoard
    life_game::NextBoard* nextboard = new life_game::NextBoard() ;

    for (int i=1; i <= 10; i++){
        for (int v = 0; v <= currentboard->row(); v++){
            for (int h = 0; h <= currentboard->clm(); h++){
                bool result = currentboard->judge(&v,&h) ; //judge(row, column)
                if ( result == true ){
                    nextboard->setCell(&v, &h, 1) ;
                }else{
                    nextboard->setCell(&v, &h, 0) ; // これがないとゴミがでる
                }
            }
        }
        //NextBoardに格納した計算結果を、次の計算ようにCurrentBoardに移す
        currentboard->setCell(nextboard) ;
        currentboard->show() ;
    }

}
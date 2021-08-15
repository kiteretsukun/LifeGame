#include "all.h"
#include "board.h"
#include "nextboard.h"
#include "currentboard.h"


void testBoard(){
    life_game::CurrentBoard* board = new life_game::CurrentBoard() ;
    board->show() ;
}

void testinitBoard(){
    life_game::CurrentBoard* currentboard = new life_game::CurrentBoard() ;
    currentboard->setInit() ;
    currentboard->show() ;
}

void testcpBoard(){
    life_game::CurrentBoard* currentboard = new life_game::CurrentBoard() ;
    currentboard->setInit() ;
    life_game::NextBoard* nextboard = new life_game::NextBoard() ;
    currentboard->setCell(nextboard) ;
    currentboard->show() ;
    life_game::NextBoard* calboard = new life_game::NextBoard() ;
    int r = 5 ;
    int c = 5 ;
    calboard->setCell(&r,&c,1) ;
    currentboard->setCell(calboard) ;
    nextboard = calboard ;
    nextboard->show() ;
    //NextBoardは、CurrentBoardから計算された結果を格納する使い方にする
    //計算が終わったら、currentboard->setCell(nextboard) ;　で最新値に更新するようにする
}

void testCell(){
    life_game::CurrentBoard* currentboard = new life_game::CurrentBoard() ;
    currentboard->setInit() ;
    currentboard->show() ;
    int r = 3 ;
    int c = 3 ;
    bool result = currentboard->judge(&r,&c) ; //judge(row, column)
    assert(result == true ) ;
    r = 5 ;
    c = 5 ;
    result = currentboard->judge(&r,&c) ; //judge(row, column)
    assert(result == false ) ;
}

void testCorner(){
    life_game::CurrentBoard* currentboard = new life_game::CurrentBoard() ;
    currentboard->setTest() ;
    currentboard->show() ;
    int r = 1 ;
    int c = 1 ;
    bool result = currentboard->judge(&r,&c) ; //judge(row, column)
    assert(result == true ) ;
    r = 10 ;
    c = 9 ;
    result = currentboard->judge(&r,&c) ; //judge(row, column)
    assert(result == true ) ;

}

void testNext(){
    life_game::CurrentBoard* currentboard = new life_game::CurrentBoard() ;
    currentboard->setTest() ;
    currentboard->show() ;
    life_game::NextBoard* nextboard = new life_game::NextBoard() ;
    int r = 10 ;
    int c = 9 ;
    bool result = currentboard->judge(&r,&c) ; //judge(row, column)
    assert(result == true ) ;
    if ( result == true ){
        nextboard->setCell(&r, &c, 1) ;
    }
    nextboard->show() ;
    currentboard->setCell(nextboard) ;
    currentboard->show() ;
}

int main(void){
    //testBoard();
    //testinitBoard();
    //testcpBoard();
    testCell();
    testCorner() ;
    testNext() ;
}
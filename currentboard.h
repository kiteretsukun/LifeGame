namespace life_game {

    class CurrentBoard : public Board {
    public:
        void setCell(NextBoard* nextboard) ;
        bool judge(int* r, int* c) ;  //row, colomn
        void show();                // view board
        void setInit() ;
        void setTest() ;
        int row() ;
        int clm() ;
    } ;

    void CurrentBoard::setCell(NextBoard* nextboard){
        for (int v = 0; v < Board::row; v++){
            for (int h = 0; h < Board::clm; h++){
                if (nextboard->cell[v][h] == 1) {
                    this->cell[v][h] = 1;
                }else{
                    this->cell[v][h] = 0;
                }
            }
        }
    }

    void CurrentBoard::setInit(){
        cell[4][5] = 1 ;
        cell[3][4] = 1 ;
        cell[3][6] = 1 ;

        cell[5][4] = 1 ;
        cell[4][3] = 1 ;
        cell[6][3] = 1 ;

        cell[5][6] = 1 ;
        cell[4][7] = 1 ;
        cell[6][7] = 1 ;
        
        cell[6][5] = 1 ;
        cell[7][4] = 1 ;
        cell[7][6] = 1 ;

    }

    bool CurrentBoard::judge(int* r, int* c){
        //judge
        int counter = 0 ;
        for ( int v = *r-1 ; v <= *r + 1 ; v++ ){
            if ( v >= 0 && v < Board::row ){
                for ( int h = *c -1 ; h <= *c + 1 ; h++){
                    if ( h >= 0 && h < Board::clm ){
                        if (v == *r && h == *c){
                            //Nothing
                        }else{
                            if ( cell[v][h] == 1 ){ 
                                counter += 1 ; 
                                //std::cout << v << "," << h << "\n" ;
                            }
                        }
                    }
                }
            }
        }
        //誕生（＝白→黒になる）条件：白いマスの周囲に3つの黒いマスがあれば次の世代では黒いマスになる。
        if (cell[*r][*c] == 0 && counter == 3 ){
            //std::cout << counter << "\n" ;
            return true ;
        //維持（＝黒→黒のまま）条件：黒いマスの周囲に2つか3つの黒いマスがあれば次の世代でも黒いマスになる。
        }else if (cell[*r][*c] == 1 && (counter == 2 || counter ==3 )) {
            return true ;
        //上記以外の場合には，次の世代で白いマスになる。
        }else{
            //std::cout << counter << "\n" ;
            return false ;
        }
    }

    void CurrentBoard::show(){
        return Board::show() ;
    }

    void CurrentBoard::setTest() {
        cell[0][0] = 1 ;
        cell[1][0] = 1 ;

        cell[10][10] = 1 ;
        cell[9][10] = 1 ;
        cell[9][9] = 1 ;
    }

    int CurrentBoard::row() {
        return Board::row ;
    }

    int CurrentBoard::clm() {
        return Board::clm ;
    }

}
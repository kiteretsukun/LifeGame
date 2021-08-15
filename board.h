namespace life_game {

    class Board{
    protected:
        const int row = 11;
        const int clm = 11;
    public:
        int cell[11][11];           // 10 x 10
        void show();                // view board
        //virtual void setCell() = 0;     // write life in the Board
        virtual bool judge(int r, int c);       // judge live or death. row and column
        Board();                    // constructer
    } ;

    Board::Board(){
        for (int v = 0; v < row; v++){
            for (int h = 0 ; h < clm; h++){
                cell[v][h] = 0 ;
            }
        }
    }

    void Board::show() {
        std::cout << "\n" ;
        std::cout << "|" ;
        for (int i = 0; i< clm; i++){
            std::cout << "-" ;
        }
        std::cout << "|\n" ;
        for (int v = 0; v < row; v++){
            std::cout << "|" ;
            for (int h = 0; h < clm; h++){
                if (cell[v][h] == 0 ){
                    std::cout << " " ;
                }else if (cell[v][h] == 1 ){
                    std::cout << "*" ;
                }
            }
            std::cout << "|\n" ;
        }
        std::cout << "|" ;
        for (int i = 0; i< clm; i++){
            std::cout << "-" ;
        }
        std::cout << "|\n" ;
        std::cout << "\n" ;
    }

    //virtualでもメンバ関数を作る必要あり
    bool Board::judge(int r, int c){
        return true ;
    }

}
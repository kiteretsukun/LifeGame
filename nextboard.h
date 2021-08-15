namespace life_game {

    class NextBoard : public Board {
    public:
        void setCell(int* r, int* c, int v) ; //row, col, value
        void show();                // view board
    } ;

    void NextBoard::setCell(int* r, int* c, int v){
        this->cell[*r][*c] = v ;
    }

    void NextBoard::show(){
        return Board::show() ;
    }

}
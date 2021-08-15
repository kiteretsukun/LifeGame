#ifndef CPBOARD_H
#define CPBOARD_H

namespace life_game {

    class CpBoard : public CurrentBoard, public NextBoard{
        public:
            void copyCurrentToNext(CurrentBoard* currentboard, NextBoard* nextboard);
    } ;

    void copyCurrentToNext(CurrentBoard* currentboard, NextBoard* nextboard){
        for (int v = 0; v < 10; v++){
            for (int h = 0; h < 10; h++){
                if (currentboard->cell[v][h] == 1) {
                    nextboard->cell[v][h] = 1 ;
                }else{
                    nextboard->cell[v][h] = 0 ;
                }
            }
        }
    }

}

#endif
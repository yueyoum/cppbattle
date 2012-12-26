#ifndef BATTLE_MAP_H_INCLUDED
#define BATTLE_MAP_H_INCLUDED

#include <vector>

using namespace std;

#include "character.h"


typedef vector<Character*> charprt_vec_t;
typedef vector<charprt_vec_t> matrix_t;


class BattleMap
{
    public:
        BattleMap();
        BattleMap(int);
        BattleMap(int, int, int);
        ~BattleMap();

        bool put_left_chars(Character **, int);
        bool put_right_chars(Character **, int);

        void output(void);


    private:
        int bg;
        int width;
        int height;

        matrix_t left;
        matrix_t right;

        void initialize(void);

};



#endif

#ifndef BATTLE_MAP_H_INCLUDED
#define BATTLE_MAP_H_INCLUDED

#include <vector>
#include <map>

using namespace std;

#include "character.h"


typedef map<int, Character> cid_char_t;
typedef vector<int> line_t;
typedef vector<line_t> matrix_t;


class BattleMap
{
    public:
        BattleMap(void);
        BattleMap(int);
        BattleMap(int, int, int);
        bool put_char(Character&);
        vector<Character>& get_chars(void);
        vector<Character>& get_chars(matrix_t::iterator&, matrix_t::iterator&);


    private:
        int bg;
        int width;
        int height;

        // map类型，first为 cid, second 为 Character
        cid_char_t cid_chars;

        matrix_t matrix;

        void initialize(void);
};



#endif

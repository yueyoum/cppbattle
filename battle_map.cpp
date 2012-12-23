#include "battle_map.h"
#include "character.h"

BattleMap::BattleMap(void):bg(1), width(9), height(3)
{
    initialize();
}

BattleMap::BattleMap(int b):bg(b), width(9), height(3)
{
    initialize();
}

BattleMap::BattleMap(int b, int w, int h):bg(b), width(w), height(h)
{
    initialize();
}


void BattleMap::initialize(void)
{
    line_t line;
    for(int y=0; y<height; y++)
    {
        for(int x=0; x<width; x++)
        {
            line.push_back(0);
        }
        matrix.push_back(line);
        line.clear();
    }
}


bool BattleMap::put_char(Character &c)
{
    int cid = c.get_cid();
    if(cid_chars.count(cid)) return false;
    cid_chars[cid] = c;
    matrix[c.get_y()][c.get_x()] = cid;
    return true;
}

int main(void){return 0;};

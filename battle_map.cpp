#include <iostream>

#include "battle_map.h"
#include "character.h"

using namespace std;

BattleMap::BattleMap():bg(1), width(6), height(3)
{
    initialize();
}

BattleMap::BattleMap(int b):bg(b), width(6), height(3)
{
    initialize();
}

BattleMap::BattleMap(int b, int w, int h):bg(b), width(w), height(h)
{
    initialize();
}


BattleMap::~BattleMap()
{
    auto delete_one_side = [](matrix_t &side)
    {
        for(auto &line: side)
        {
            for(auto &c: line)
            {
                if(c) delete c;
            }
        }
    };

    delete_one_side(left);
    delete_one_side(right);
}



void BattleMap::initialize(void)
{
    charprt_vec_t line;
    int half_width = width/2;

    line.reserve(half_width);
    left.reserve(height);
    right.reserve(height);

    auto init_one_side = [this, &line, &half_width](matrix_t &side)
    {
        for(int h=0; h<this->height; h++)
        {
            for(int w=0; w<half_width; w++)
            {
                line.push_back(NULL);
            }
            side.push_back(line);
            line.clear();
        }
    };

    init_one_side(left);
    init_one_side(right);
}






bool BattleMap::put_left_chars(Character **chars, int size)
{
    int x, y;
    for(int i=0; i<size; i++)
    {
        y = (*(chars+i))->get_y();
        x = (*(chars+i))->get_x();
        if(left[y][x]) return false;
        left[y][x] = *(chars+i);
    }
    return true;
}

bool BattleMap::put_right_chars(Character **chars, int size)
{
    // reverse x first. 0 -> 2, 1 -> 1, 2 -> 0

    int half_width = width / 2;
    auto reverse_x = [&half_width](int x)->int
    {
        if(half_width % 2 != 0)
        {
            int m = half_width/2;
            x += (m-x) * 2;
            return x;
        }
        else
        {
            int m_max = half_width/2;
            int m_min = m_max - 1;
            if(x<=m_min) x += (m_min-x) * 2 + 1;
            else x += (m_max-x) * 2 - 1;
            return x;
        }
    };


    int x, y, new_x;
    for(int i=0; i<size; i++)
    {
        y = (*(chars+i))->get_y();
        x = (*(chars+i))->get_x();
        new_x = reverse_x(x);
        if( right[y][new_x] ) return false;
        right[y][new_x] = *(chars+i);
    }
    return true;
}

void BattleMap::output(void)
{
    for(auto &line: left)
    {
        for(auto &c: line)
            cout << (c ? c->get_s() : ".") << "  ";
        cout << endl;
    }
    cout << endl;
    for(auto &line: right)
    {
        for(auto &c: line)
            cout << (c ? c->get_s() : ".") << "  ";
        cout << endl;
    }
}


// for test
int main(void)
{
    Character *team1[3];
    Character *team2[3];

    *(team1+0) = new Character("a", 0, 1);
    *(team1+1) = new Character("b", 1, 1);
    *(team1+2) = new Character("c", 1, 2);

    *(team2+0) = new Character("d", 0, 0);
    *(team2+1) = new Character("e", 0, 2);
    *(team2+2) = new Character("f", 1, 1);


    BattleMap battle;
    battle.put_left_chars(team1, 3);
    battle.put_right_chars(team2, 3);

    battle.output();
    return 0;

}

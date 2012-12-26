#include <iostream>

#include "battle_map.h"
#include "character.h"

using namespace std;

BattleMap::BattleMap():bg(1), width(9), height(3)
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


BattleMap::~BattleMap()
{
    auto delete_one_side = [](matrix_t &side)
    {
        for(auto &line: side)
        {
            for(auto &c: line)
            {
                //if(c) delete c;
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
    auto init_one_side = [this, &line, &half_width](matrix_t &side)
    {
        for(int h=0; h<this->height; h++)
        {
            for(int w=0; w<half_width; w++)
            {
                line.push_back(NULL);
                cout << "init" << endl;
            }
            side.push_back(line);
            line.clear();
        }
    };

    init_one_side(left);
    init_one_side(right);
}






bool BattleMap::put_left_chars(vector<Character> &chars)
{
    for(auto &c: chars)
    {
        if( left[c.get_y()][c.get_x()] ) return false;
        left[c.get_y()][c.get_x()] = &c;
    }
    return true;
}

bool BattleMap::put_right_chars(vector<Character> &chars)
{
    // reverse x first. 0 -> 2, 1 -> 1, 2 -> 0

    int half_width = width / 2;
    int new_x;
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

    for(auto &c: chars)
    {
        new_x = reverse_x(c.get_x());
        if( right[c.get_y()][new_x] ) return false;
        right[c.get_y()][new_x] = &c;
    }
    return true;
}

void BattleMap::output(void) const
{
    for(auto &line: left)
    {
        for(auto &c: line)
            cout << (c ? 'A' : ' ') << "  " << endl;
    }
    cout << endl;
    for(auto &line: right)
    {
        for(auto &c: line)
            cout << (c ? 'A' : ' ') << "  " << endl;
    }
}


// for test
int main(void)
{
    vector<Character> team1;
    vector<Character> team2;

    team1.push_back(Character("a", 0, 0));
    team1.push_back(Character("b", 1, 1));
    team1.push_back(Character("c", 1, 2));

    team2.push_back(Character("d", 0, 0));
    team2.push_back(Character("e", 0, 2));
    team2.push_back(Character("f", 1, 1));

    cout << "aaa" << endl;

    BattleMap battle;
    battle.put_left_chars(team1);
    battle.put_right_chars(team2);

    //battle.output();
    return 0;

}

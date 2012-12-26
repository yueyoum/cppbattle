#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Character
{
    public:
        Character(string _s, int _y, int _x):y(_y), x(_x), s(_s){cout << "char init: "  << s << endl;};
        ~Character();
        int get_cid(void)const{return 1;};
        int get_y(void)const{return y;};
        int get_x(void)const{return x;};
        string get_s(void)const{return s;};


    private:
        int id, uid, model_id, race, cls, str, sta, dex, wis,
            spd, atk, defe, matk, mdef, cid, y, x;
        string s;

};



Character::~Character()
{
    cout << "die: " << s << ':' << y << ',' << x << endl;
}


#endif

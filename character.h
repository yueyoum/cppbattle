#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED


class Character
{
    public:
        Character(){};
        ~Character(){};
        int get_cid(void){return 1;};
        int get_y(void){return 1;};
        int get_x(void){return 1;};


    private:
        int id, uid, model_id, race, cls, str, sta, dex, wis,
            spd, atk, defe, matk, mdef, cid, x, y;

};


#endif

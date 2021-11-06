#include <string>
#include <vector>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <math.h>

using namespace std;


class Dragon{
    public:

    bool status = true;// true - Alive |||||| false - dead
    bool key = false;
    int posX = 1;
    int posY = 3;
    char move;
    bool sword = false;
    bool trigger;
    bool triggerA;

    
    bool killDragon(int &pX, int &pY, Dragon &dr, Player &p, vector<vector<char>> v);
    
    void dragonMove(Dragon &dr, vector<vector<char>> v, Player &player, int tami);

    
    void TeleportDragon(Dragon &dr, Player &player);

};
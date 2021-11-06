#include <string>
#include <vector>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <math.h>


using namespace std;

class Player{
    public:
    
    bool chave = false;
    bool weapon = false;
    char state = 'H';
    int posX = 1;
    int posY = 1;
    int swordPosX;
    int swordPosY;
    bool validKey;
    
    //Keyboards Inputs
    void InputHandle(char move, int &pX, int &pY, vector<vector<char>> &v, Player &inv, char &justmove);

};
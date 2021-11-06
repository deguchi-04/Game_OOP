#include <string>
#include <vector>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <math.h>


using namespace std;

class Key{
    public:
    int posX;
    int posY;
    
    bool gotKey(int &pX, int &pY, vector<vector<char>> levelKey, Player &player);
};
#include <string>
#include <vector>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <math.h>

#include "PlayerClass.hpp"
#include "DragonClass.hpp"
#include "BoardLevelClass.hpp"
#include "KeyClass.hpp"
#include "MapClass.hpp"

using namespace std;


class Game{
    public:
    
    void gameLoop(int &playerPosX, int &playerPosY, Player &player ,int exitPos[2], vector<vector<char>> levelKey, Dragon &drogo, char &movement);

    private: 

    bool CheckWinCondition(int &pX, int &pY, Player &in, int exitPos[2]);

    bool CheckLoseCondition(int &pX, int &pY, Dragon &dr, Player &player);

};
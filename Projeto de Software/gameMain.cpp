#include <string>
#include <vector>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <math.h>
#include "gameLogic.cpp"
 
//QUEST 2 
//Author : Thaidy Deguchi
//MIEEC
//Incomplete, without exercise 'C'

using namespace std;

int main(){

    Game game;
    Dragon drogo;
    Map map;
    Player player;
    vector<vector<char>> level, levelKey;
    int exitPos[2];
    char movement = ' ', state;
    level = map.board();
    levelKey = map.mapConfig(level,drogo, exitPos);
    
        cout<<endl<<"Hello, welcome to The Maze and The Dragon"<<endl
        <<"Use WASD to walk with your hero (H) to pick up the Sword(S)."<<endl
        <<"Use the sword to kill the dragon(D) and then the dragon will drop the key(K)"<< endl
        <<"Finally, pick the key and go to the Exit(E)"<<endl
        <<"Wanna Begin?(Y/N)"<<endl<<endl;

    cin >> state;
    map.Clear();
    if(state == 'Y' || state == 'y'){
        
        game.gameLoop(player.posX, player.posY, player,exitPos,levelKey, drogo, movement);
        
    }
    else if(state == 'N' || state == 'n'){
        cout<<"See Ya"<<endl;
        return 0;
    }
    return 0;
}
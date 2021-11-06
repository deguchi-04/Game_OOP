#include <string>
#include <vector>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <math.h>



using namespace std;

class Map{
    public:
    void Clear();
    
    
    //generate random key
    vector<vector<char>> mapConfig(vector<vector<char>> v, Dragon &dr, int exitPos[2]);
        
    //define board design
    vector<vector<char>> board();
    
    //calc board size
    void tamanhoBoard(vector<vector<char>> v, BoardLevel &board);
    
    //show board 
    void Display(int &pX, int &pY, vector<vector<char>> v, Player &player, Dragon &dr);

};
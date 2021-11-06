#include <string>
#include <vector>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <math.h>
#include "GameClass.hpp"

using namespace std;

//clear the terminal every turn
void Map::Clear(){
    system("clear");//clear console
}

//controls
void Player::InputHandle(char move, int &pX, int &pY, vector<vector<char>> &v, Player &inv, char &justmove){
    
    cin >> move;
    BoardLevel board;
    Map obj;
    justmove = move;
    //since the board are nXn i can use numCol or numLine to limit the cases
    
        switch(move){
            case 'w':
                inv.validKey = true;
                if( pY-1 >= 0 ){
                    if(v[pY-1][pX] == 'X'){
                       //nothing happens
                       inv.validKey = false;
                    }
                    if(v[pY-1][pX] == ' '){
                        pY--;
                        break;
                    }
                    if(v[pY-1][pX] == 'E' && inv.chave){
                        v[pY-1][pX]  = ' ';  
                    }
                    if(v[pY-1][pX] == 'E' && !inv.chave){
                        //nothing happens
                        inv.validKey = false;
                    }
                    if(v[pY-1][pX] == 'S'){
                        pY--;
                    }
                    if(v[pY-1][pX] == 'K'){
                        pY--;
                    }
                
                }
                break;

            case 's':
                inv.validKey = true;
                if( pY+1 <= board.numColunas ){
                    if(v[pY+1][pX] == 'X'){
                       //nothing happens
                       inv.validKey = false;
                    }
                    if(v[pY+1][pX] == ' '){
                        pY++;
                        break;
                    }
                    if(v[pY+1][pX] == 'E' && inv.chave){
                        v[pY+1][pX]  = ' ';  
                    }
                    if(v[pY+1][pX] == 'E' && !inv.chave){
                        //nothing happens
                        inv.validKey = false;
                    }
                    if(v[pY+1][pX] == 'S'){
                        pY++;
                    }
                    if(v[pY+1][pX] == 'K'){
                        pY++;
                    }
                }
            break;

            case 'd':
                inv.validKey = true;
                if(pX+1 <= board.numColunas){
                    if(v[pY][pX+1] == 'X'){
                        //nothing happens
                        inv.validKey = false;
                    }
                    if(v[pY][pX+1] == ' '){
                        pX++;
                        break;
                    }
                    if(v[pY][pX+1] == 'E' && inv.chave){
                        v[pY][pX+1]  = ' ';  
                    }
                    if(v[pY][pX+1] == 'E' && !inv.chave){
                        //nothing happens
                        inv.validKey = false;
                    }
                    if(v[pY][pX+1] == 'S'){
                        pX++;
                    }
                    if(v[pY][pX+1] == 'K'){
                        pX++;
                    }
                   
                }
            break;

            case 'a':
                inv.validKey = true;
                if(pX-1 >= 0 ){
                    if(v[pY][pX-1] == 'X'){
                        //nothing happens
                        inv.validKey = false;
                    }
                    if(v[pY][pX-1] == ' '){
                        pX--;
                        break;
                    }
                    if(v[pY][pX-1] == 'E' && inv.chave){
                        v[pY][pX-1]  = ' ';  
                    }
                    if(v[pY][pX-1] == 'E' && !inv.chave){
                        //nothing happens
                        inv.validKey = false;
                    }
                    if(v[pY][pX-1] == 'S'){
                        pX--;
                    }
                    if(v[pY][pX-1] == 'K'){
                        pX--;
                    }
                }
                default:
                    inv.validKey = false;
                    break;
        }
}


void Map::Display(int &pX, int &pY, vector<vector<char>> v, Player &player, Dragon &dr){
    
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            if(j==pX && i==pY && player.state == 'H'){//put player's 'H' 
                cout<<"H ";
                continue;  
            }
            if(j==dr.posX && i==dr.posY && dr.status == true && dr.sword == false){//put D 
                cout<<"D ";
                continue;  
            } 
            if(j==dr.posX && i==dr.posY && dr.status == true && dr.sword == true){//put F 
                cout<<"F ";
                continue;  
            } 
            else if(j==pX && i==pY && player.state == 'A'){//put players A
                cout<<"A ";
                continue;
            } 
            
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

//maze
vector<vector<char>> Map::board(){
    vector<vector<char>> board{
        {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X','X','X','X', 'X','X','X'},
        {'X', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ',' ','X','X','X', 'X','X','X'},
        {'X', ' ', 'X', 'X', ' ', ' ', ' ', 'X', ' ', 'X','X','X','X','X', 'X','X','X'},
        {'X', ' ', 'X', 'X', ' ', 'X', ' ', 'X', ' ', 'X',' ','X','X','X', 'X','X','X'},
        {'X', ' ', 'X', 'X', ' ', 'X', ' ', 'X', ' ', 'X',' ',' ',' ',' ', ' ',' ','X'},
        {'X', ' ', 'X', 'X', ' ', 'X', 'X', 'X', ' ', 'X',' ','X','X','X', 'X',' ','X'},
        {'X', ' ', ' ', ' ', ' ', 'X', ' ', 'X', ' ', 'X',' ','X','X',' ', 'X',' ','X'},
        {'X', ' ', ' ', 'X', ' ', 'X', ' ', ' ', ' ', 'X',' ',' ','X',' ', 'X',' ','X'},
        {'X', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X','X',' ','X',' ', 'X',' ','X'},
        {'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X','X',' ','X',' ', ' ',' ','X'},
        {'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ',' ',' ','X',' ', 'X','X','X'},
        {'X', 'X', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X','X','X','X', ' ', 'X',' ','X'},
        {'X', 'X', ' ', 'X', 'X', ' ', ' ', ' ', ' ', ' ',' ',' ','X', ' ', 'X',' ','X'},
        {'X', 'X', ' ', 'X', 'X', ' ', 'X', 'X', 'X', 'X','X',' ','X', ' ', 'X',' ','X'},
        {'X', 'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X','X',' ',' ', ' ', ' ',' ','X'},
        {'X', 'X', 'E', 'X', 'X', 'X', 'X', 'X', 'X', 'X','X','X','X', 'X', 'X','X','X'},
        
    };
    return board;
    
}

void Map::tamanhoBoard(vector<vector<char>> v, BoardLevel &board){//calculate the board size
    int linhas=0, colunas=0;
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v[i].size(); j++){
            colunas++;
        }
        linhas++;
    }
    board.v = v;
    board.numLinhas = linhas;
    board.numColunas = colunas;   
}


//function to randomize the key and save exit position
vector<vector<char>> Map::mapConfig(vector<vector<char>> v, Dragon &dr, int exitPos[2]){
    int rand1, rand2, tam;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j] == 'E'){
                exitPos[0]= i;
                exitPos[1] = j;
            }
        }
        tam++;
    }
    while(1){
        random_device rd;
        mt19937 eng(rd());
        uniform_int_distribution<int> distr(1, tam-1);
            rand1 = distr(eng);
        mt19937 eng2(rd());
            rand2 = distr(eng2);
    
        if((v[rand1][rand2] == ' ')){
            v[rand1][rand2] = 'S';
            break;
        }
        else{
            
        }
    }
    return v;
}


bool Game::CheckWinCondition(int &pX, int &pY, Player &in, int exitPos[2]){
    if(pX==exitPos[1] && pY ==exitPos[0] && in.chave == true){
        return true;
    }
    else{
        return false;
    }

}

//ver se perde
bool Game::CheckLoseCondition(int &pX, int &pY, Dragon &dr, Player &player)
{
    if(((pX-1 == dr.posX && pY == dr.posY )|| 
       (pX+1 == dr.posX && pY == dr.posY )||
       (pX == dr.posX && pY+1 == dr.posY )||
       (pX == dr.posX && pY-1 == dr.posY )) && !player.weapon){//kill hero if dragon is in an adjacent position
        return true;
    }
    else if (player.posX == dr.posX && player.posY == dr.posY && !player.weapon){//kill hero if dragon is flying above
        return true;
    } 
    else{
        return false;
    }
    
}

void Game::gameLoop(int &playerPosX, int &playerPosY, Player &player ,int exitPos[2], vector<vector<char>> levelKey, Dragon &drogo, char &movement){
    char justmove;
    Map map;
    Key key;
    int tam = 0;
    while(!CheckWinCondition(playerPosX,playerPosY, player,exitPos)){//if player is not in the finish, loop 
            for(int i=0;i<levelKey.size();i++){//calculate the position of D and S every turn
                for(int j=0;j<levelKey[i].size();j++){
                    if(levelKey[i][j] == 'D'){
                        drogo.posY = i;
                        drogo.posX = j;
                    }  
                    if(levelKey[i][j] == 'S'){
                        player.swordPosY = i;
                        player.swordPosX = j;
                    }   
                }
                tam++;// nXn size map
            } 

            drogo.TeleportDragon(drogo, player);
            
            if(!player.validKey){
                cout << "Please, do a valid movement"<< endl<< endl;
            }
            if(drogo.posY == player.swordPosY && drogo.posX == player.swordPosX){
                drogo.sword = true;
                levelKey[drogo.posY][drogo.posX] == 'F';
            }
            else{
                drogo.sword = false;
            }
            if(drogo.killDragon(playerPosX, playerPosY, drogo, player, levelKey)){
                drogo.status = false;
                levelKey[drogo.posY][drogo.posX] = 'K';
                cout<<"You have killed the dragon, get the key and escape"<<endl<<endl;
            }
            if(key.gotKey(playerPosX, playerPosY,levelKey, player)){
                player.chave = true;
                levelKey[playerPosY][playerPosX] = ' ';
            }
            if(levelKey[playerPosY][playerPosX] != 'S'){
                map.Display(playerPosX, playerPosY,levelKey, player, drogo);//Show current maze
                player.InputHandle(movement, playerPosX, playerPosY,levelKey,player, justmove);//take input 
                drogo.dragonMove(drogo,levelKey, player,tam);  
                map.Clear();
            }   
            else if (levelKey[playerPosY][playerPosX] == 'S'){  
                levelKey[playerPosY][playerPosX] = ' ';
                player.weapon = true;
                player.state = 'A';
                cout<<"You found the sword, go face the dragon"<<endl<<endl; 
            }   
            if(CheckLoseCondition(playerPosX,playerPosY, drogo, player)){
                map.Display(playerPosX, playerPosY,levelKey, player, drogo);//Show current maze
                cout<<"YOU ARE DEAD"<<endl<<endl;
                exit(0);
            }  
        }      
        map.Display(playerPosX, playerPosY,levelKey, player, drogo);//Show current maze
        cout<<"*******Congrats, you finished the maze!*******"<<endl<<endl;
}


bool Dragon::killDragon(int &pX, int &pY, Dragon &dr, Player &player, vector<vector<char>> v){
    if(((pX-1 == dr.posX && pY == dr.posY )|| 
       (pX+1 == dr.posX && pY == dr.posY )||
       (pX == dr.posX && pY+1 == dr.posY )||
       (pX == dr.posX && pY-1 == dr.posY )) && player.weapon == true && dr.status){//kill dragon in adjacents positions
        dr.trigger == true;
        return true;
    }
    else if (player.posX == dr.posX && player.posY == dr.posY && player.weapon)//kill if dragon is flying above
    {
        return true;
    } 
    else{
        return false;
    }
}

bool Key::gotKey(int &pX, int &pY, vector<vector<char>> levelKey, Player &player){
    if(levelKey[pY][pX] == 'K'){
        return true;
    }  
    else{
        return false;
    }
}

void Dragon::dragonMove(Dragon &dr, vector<vector<char>> v, Player &player, int tami){
    int rand1, randnewDr1, randnewDr2, tam=0;
    for (int i = 0; i < v.size(); i++)
    {
        
        tam++;
        
    }
    
    bool ok= false, ok2= false, ok3 = false;
    //caso 0-UP, 1-DOWN, 2-RIGHT, 3-LEFT
    if(player.validKey == true){// if player enter a valid command on keyboard{
        while (ok != true){//flag to show me when stop the loop
            random_device rd;
            mt19937 eng(rd());
            uniform_int_distribution<int> distr(0, 3);//random number to the four cases
            rand1 = distr(eng);
            if(dr.trigger == true){//if trigger true teleport the dragon
                while(ok2 != true){  
                    random_device rd;
                    mt19937 eng(rd());
                    uniform_int_distribution<int> distr(0, tam-1);
                    randnewDr1 = distr(eng);
                    mt19937 eng2(rd());
                    randnewDr2 = distr(eng2);

                    if(v[randnewDr1][randnewDr2] == ' '){
                        dr.posY = randnewDr1;
                        dr.posX = randnewDr2; 
                        ok2 = true;
                        break;
                    }
                }
            }
            else if(dr.triggerA == true){//if trigger true teleport the dragon
                while(ok3 != true){  
                    random_device rd;
                    mt19937 eng(rd());
                    uniform_int_distribution<int> distr(0, tam-1);
                    randnewDr1 = distr(eng);
                    mt19937 eng2(rd());
                    randnewDr2 = distr(eng2);

                    if(v[randnewDr1][randnewDr2] == ' ' && 
                    (randnewDr1 <= player.posY-3 || 
                     randnewDr1 <= player.posY+3 || 
                     randnewDr2 <= player.posX-3 || 
                     randnewDr1 <= player.posX+3) && 
                     (randnewDr1 <=tam-1 && randnewDr2 <=tam-1)){
                        dr.posY = randnewDr1;
                        dr.posX = randnewDr2; 
                        ok3 = true;
                        break;
                    }
                }
            }
            switch (rand1){//all four movement cases 
                case 0:
                    if(v[dr.posY][dr.posX-1] == ' ' ){
                        dr.posX--;
                        ok = true;
                    }
                    else if(v[dr.posY][dr.posX-1] == 'S'  ){
                        dr.posX--;
                        ok = true;
                    }
                    break;
                case 1:
                    if(v[dr.posY][dr.posX+1] == ' ' ){
                        dr.posX++;
                        ok = true;  
                    }

                    else if(v[dr.posY][dr.posX+1] == 'S' ){
                        dr.posX++;
                        ok = true;  
                    }
                    break;
                case 2:
                    if(v[dr.posY+1][dr.posX] == ' ' ){
                        dr.posY++;
                        ok = true;
                    }
                    else if(v[dr.posY+1][dr.posX] == 'S' ){
                        dr.posY++;
                        ok = true;
                    }
                    break;
                case 3:
                    if(v[dr.posY-1][dr.posX] == ' '){
                        dr.posY--;
                        ok = true;
                    }
                    else if(v[dr.posY-1][dr.posX] == 'S'){
                        dr.posY--;
                        ok = true;
                    }
                    break;
                    
            } 
        }
    }
}


void Dragon::TeleportDragon(Dragon &dr, Player &player){
    int rand1, rand2;
    if (player.state == 'A')//if player is armed
    {
        random_device rd;
        mt19937 eng(rd());
        uniform_int_distribution<int> distr(0, 19); // generate 20 numbers -- 7/20 = 0.35
        rand1 = distr(eng);


        random_device rd2;
        mt19937 eng2(rd2());
        uniform_int_distribution<int> distr2(0, 4);// 1/5 = 0.2
        rand2 = distr2(eng2);
        if(rand2 == 0)//if its 0, trigger teleportation
        {
            dr.trigger = true;
        }
        else{
            dr.trigger = false;
        }

        if(rand1 <= 6 &&
          ((player.posX-2 == dr.posX && player.posY == dr.posY )|| 
          (player.posX+2 == dr.posX && player.posY == dr.posY )||
          (player.posX == dr.posX && player.posY+2 == dr.posY )||
          (player.posX == dr.posX && player.posY-2 == dr.posY ))){//if its any number between 0 and 6, triggerArmed teleport

            dr.triggerA = true;
        }
        else{
            dr.triggerA = false;
        }
    }
    // dragon lottery \o/ 0-teleport, else dont
    else{
        random_device rd;
        mt19937 eng(rd());
        uniform_int_distribution<int> distr(0, 4);// 1/5 = 0.2
        rand1 = distr(eng);
        if(rand1 == 0)//if its 0, trigger teleportation
        {
            dr.trigger = true;
        }
        else{
            dr.trigger = false;
        }
    }
    
    
}

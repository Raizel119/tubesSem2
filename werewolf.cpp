#include <iostream>
#include <random>
#include <time.h>
#include <stdlib.h>

using namespace std;

#define nPlayer 7
//4 vill, 2 ww, 1 solo
//seer, doctor, loud_mouth, villager
//werewolf, junior werewolf
//clown

class Player{
protected:
    string name;
    string role;
    bool isAlive;    //masih hidup atau ga
    bool isProtected;   //dilindungi atau ga
public:
    Player(){};
    Player(string name, string role){
        this->name = name;
        this->role = role;
        this->isAlive = true;
        this->isProtected = false;
        srand(time(NULL));
    }
    void virtual reset(){
        isProtected = false;
    }
    string getName(){return name;}
    string getRole(){return role;}
    bool getIsAlive(){return isAlive;}
    bool getIsProtected(){return isProtected;}
};

class Villager : public Player{
public:
    Villager(string name) : Player(name, "Villager"){}
};

int main(){
    system("cls");
    cout << "---------- Werewolf Game ----------" << endl;
    cout << "Jumlah Pemain : " << nPlayer << endl;
    string player[nPlayer] = {};
    for (int i = 0; i < nPlayer; i++){
        cout << "Player " << i+1 << " : ";
        getline(cin, player[i]);
    }

    system("cls");
    cout << "---------- Werewolf Game ----------" << endl;
    string roles[nPlayer] = {"Seer", "Doctor", "Loudmouth", "Villager", "Werewolf", "Junior Werewolf", "Clown"};
    cout << "Roles : " << endl;
    for (int i = 0; i < nPlayer; i++){
        cout << i+1 << ". " << roles[i] << endl;
    }

    Player players[nPlayer];
    //randomize role
    for (int i = 0; i < nPlayer; i++){
        //players[i].role = roles[rand() % nPlayer]; 
    }



    return 0 ;
}
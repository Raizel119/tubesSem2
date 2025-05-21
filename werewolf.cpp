#include <iostream>
#include <random>
#include <time.h>
#include <stdlib.h>
#include "role.h"

using namespace std;

#define nPlayer 7
//4 vill, 2 ww, 1 solo
//seer, doctor, loud_mouth, villager
//werewolf, junior werewolf
//clown

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
    
    Player* players[nPlayer];   //nyimpan objek players

    //randomize role
    string shuffledRoles[nPlayer] = {};
    bool roleUsed[nPlayer] = {};
    srand(time(0));     //seed random number generator
    for (int i = 0; i < nPlayer; i++){
        int r;
        do{
            r = rand() % nPlayer;
        } while (roleUsed[r]);
        roleUsed[r] = true;             //tandai role sudah dipilih
        shuffledRoles[i] = roles[r];    //tambahkan role
    }

    //assign role ke player
    for (int i = 0; i < nPlayer; i++){
        if (shuffledRoles[i] == "Seer"){
            players[i] = new Seer(player[i]);
        } else if (shuffledRoles[i] == "Doctor"){
            players[i] = new Doctor(player[i]);
        } else if (shuffledRoles[i] == "Loudmouth"){
            players[i] = new Loudmouth(player[i]);
        } else if (shuffledRoles[i] == "Villager"){
            players[i] = new Villager(player[i]);
        } else if (shuffledRoles[i] == "Werewolf"){
            players[i] = new Werewolf(player[i]);
        } else if (shuffledRoles[i] == "Junior Werewolf"){
            players[i] = new JuniorWerewolf(player[i]);
        } else if (shuffledRoles[i] == "Clown"){
            players[i] = new Clown(player[i]);
        }
    }
    


    return 0 ;
}
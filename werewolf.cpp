#include <iostream>
#include <random>
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
    


    return 0 ;
}
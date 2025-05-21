#include "role.h"
#include <string>
using namespace std;
//class Player
//constructor
Player::Player(string name, string role){
    this->name = name;
    this->role = role;
    this->isAlive = true;
    this->isProtected = false;
}
string Player::getName(){return name;}
string Player::getRole(){return role;}
bool Player::getIsAlive(){return isAlive;}
bool Player::getIsProtected(){return isProtected;}
void Player::reset(){
    isProtected = false;
}

//class Villager
Villager::Villager(string name) : Player(name, "Villager"){}

//class Seer
Seer::Seer(string name) : Player(name, "Seer"){}

//class Doctor
Doctor::Doctor(string name) : Player(name, "Doctor"){}

//class Loudmouth
Loudmouth::Loudmouth(string name) : Player(name, "Loudmouth"){}

//class Werewolf
Werewolf::Werewolf(string name) : Player(name, "Werewolf"){}

//class JuniorWerewolf
JuniorWerewolf::JuniorWerewolf(string name) : Player(name, "Junior Werewolf"){}

//class Clown
Clown::Clown(string name) : Player(name, "Clown"){}
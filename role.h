#ifndef ROLE_H
#define ROLE_H
#include <string>
using namespace std;

class Player{
    private:
        string name;
        string role;
        bool isAlive;
        bool isProtected;
    public:
        Player();
        Player(string name, string role);
        string getName();
        string getRole();
        bool getIsAlive();
        bool getIsProtected();
        void reset();
};

class Villager : public Player{
public:
    Villager(string name);
};

#endif
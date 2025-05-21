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

class Seer : public Player{
public:
    Seer(string name);
};

class Doctor : public Player{
public:
    Doctor(string name);
};

class Loudmouth : public Player{
public:
    Loudmouth(string name);
};

class Werewolf : public Player{
public:
    Werewolf(string name);
};

class Clown : public Player{
public:
    Clown(string name);
};

class JuniorWerewolf : public Player{
public:
    JuniorWerewolf(string name);
};

#endif
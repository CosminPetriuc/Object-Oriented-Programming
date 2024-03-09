#pragma once
#include <string>
#include <vector>
#include <cassert>
#include <iostream>
using namespace std;

class Character {
public:
    Character();
    Character(std::string name, int health, int level);

    std::string getName()const;
    int getHealth()const;
    int getLevel()const;

    void setName(std::string name);
    void setHealth(int health);
    void setLevel(int level);
    static void runTests();
protected:
    std::string name;
    int health;
    int level;


};

class Wizard : public Character {
public:
    Wizard();
    Wizard(std::string name, int health, int level, int mana, std::vector<std::string> spells, int spellPower);

    bool castSpell(std::string spell);

    //GETTERS
    void setMana(int mana);
    void setSpells(std::vector<std::string> spells);
    void setSpellPower(int spellPower);

    //SETTERS
    int getMana();
    int getSpellPower();
    std::vector<std::string> getSpells();

private:
    int mana; //mana unchanged if the wizard does not know the requested spell
    std::vector<std::string>spells; //each requests 10 mana
    int spellPower;

};

class Knight : public Character {
public:
    //default const
    Knight();
    //constructor
    Knight(std::string name, int health, int level, int armor, int swordDamage);

    int getArmor()const;
    void setArmor(int armor);
    int getSwordDamage()const;
    void setSwordDamage(int swordDamage);
    void takeDamage(int damage);
    static void runTests();

private:
    int armor;
    int swordDamage;

};
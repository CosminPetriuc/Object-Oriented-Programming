#include "PB2.h"
#include <vector>
#include <string>
#include <cassert>
#include <iostream>
using namespace std;


Character::Character()
{
    this->name = '\0';
    this->health = 0;
    this->level = 0;
}

Character::Character(std::string name, int health, int level)
{
    this->name = name;
    this->health = health;
    this->level = level;
}

std::string Character::getName()const {
    return this->name;
}

int Character::getHealth()const {
    return this->health;
}

int Character::getLevel()const {
    return this->level;
}
void Character::setName(std::string name) {
    this-> name = name;
}
void Character::setHealth(int health) {
    this ->health = health;
}
void Character::setLevel(int level) {
    this-> level = level;
}



Wizard::Wizard() {
    this->name = "NO NAME";
    this->health = 0;
    this->level = 0;
    this->mana = 0;
    this->spells = std::vector<string>();
    this->spellPower = 0;

}
Wizard::Wizard(std::string name, int health, int level, int mana, std::vector<std::string> spells, int spellPower) {
    this->name = name;
    this->health = health;
    this->level = level;
    this->mana = mana;
    this->spells = spells;
    this->spellPower = spellPower;

}

void Wizard::setMana(int mana) {
    this->mana = mana;
}
void Wizard::setSpells(std::vector<std::string> spells) {
    this->spells = spells;
}
void Wizard::setSpellPower(int spellPower) {
    this->spellPower = spellPower;
}

int Wizard::getMana() {
    return this->mana;
}
int Wizard::getSpellPower() {
    return this->spellPower;
}
std::vector<std::string> Wizard::getSpells() {
    return this->spells;
}

bool Wizard::castSpell(std::string spell) {
    if (mana >= 10) {
        // Search for the spell in the spells vector
        for (std::string s : spells) {
            if (s == spell) {
                // The wizard knows the spell, so cast it
                mana -= 10;
                return true;
            }
        }
    }
    // The wizard either doesn't know the spell or doesn't have enough mana
    return false;
}

Knight::Knight()
{
    this->name = "\0";
    this->health = 0;
    this->level = 0;
    this->armor = 0;
    this->swordDamage = 0;
}
Knight::Knight(std::string name, int health, int level, int armor, int swordDamage) 
{
    this->name = name;
    this->health = health;
    this->level = level;
    this->armor = armor;
    this->swordDamage = swordDamage;
}

int Knight::getArmor()const {
    return this->armor;
}
void Knight::setArmor(int armor) {
    this->armor = armor;
}
int Knight::getSwordDamage()const {
    return this->swordDamage;
}
void Knight::setSwordDamage(int swordDamage) {
    this-> swordDamage = swordDamage;
}
void Knight::takeDamage(int damage) {
    armor = armor - damage;
    if (armor < 0) {
        health = 0;
        armor = 0;
    }
}


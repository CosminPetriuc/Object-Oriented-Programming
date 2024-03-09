#include <iostream>
#include <cassert>
#include <vector>
#include "PB2.h"

class CharacterTest {
public:
    static void runTests() {
        testGetName();
        testSetName();
        testGetHealth();
        testSetHealth();
        testGetLevel();
        testSetLevel();
        cout << "All Character tests passed!#_#" << endl;
    }

private:
    static void testGetName() {
        Character c("Bob", 100, 1);
        assert(c.getName() == "Bob");
    }

    static void testSetName() {
        Character c("Bob", 100, 1);
        c.setName("Alice");
        assert(c.getName() == "Alice");
    }

    static void testGetHealth() {
        Character c("Bob", 100, 1);
        assert(c.getHealth() == 100);
    }

    static void testSetHealth() {
        Character c("Bob", 100, 1);
        c.setHealth(50);
        assert(c.getHealth() == 50);
    }

    static void testGetLevel() {
        Character c("Bob", 100, 1);
        assert(c.getLevel() == 1);
    }

    static void testSetLevel() {
        Character c("Bob", 100, 1);
        c.setLevel(2);
        assert(c.getLevel() == 2);
    }
};

class WizardTest {
public:
    static void runTests() {
        testGetMana();
        testSetMana();
        testGetSpells();
        testSetSpells();
        testGetSpellPower();
        testSetSpellPower();
        testCastSpell();
        cout << "All Wizard tests passed!@_@" << endl;
    }

private:
    static void testGetMana() {
        Wizard w("AureluDauCuSpelu", 100, 5, 50, std::vector<std::string>(), 20);
        assert(w.getMana() == 50);
    }

    static void testSetMana() {
        Wizard w("AureluDauCuSpelu", 100, 5, 50, std::vector<std::string>(), 20);
        w.setMana(60);
        assert(w.getMana() == 60);
    }

    static void testGetSpells() {
        std::vector<std::string> spells = { "Fireball", "Ice Bolt", "Lightning Strike" };
        Wizard w("AureluDauCuSpelu", 100, 5, 50, spells, 20);
        assert(w.getSpells() == spells);
    }

    static void testSetSpells() {
        std::vector<std::string> spells = { "Fireball", "Ice Bolt", "Lightning Strike" };
        Wizard w("AureluDauCuSpelu", 100, 5, 50, spells, 20);
        std::vector<std::string> newSpells = { "Fireball", "Ice Bolt", "Thunder Wave" };
        w.setSpells(newSpells);
        assert(w.getSpells() == newSpells);
    }

    static void testGetSpellPower() {
        Wizard w("AureluDauCuSpelu", 100, 5, 50, std::vector<std::string>(), 20);
        assert(w.getSpellPower() == 20);
    }

    static void testSetSpellPower() {
        Wizard w("AureluDauCuSpelu", 100, 5, 50, std::vector<std::string>(), 20);
        w.setSpellPower(30);
        assert(w.getSpellPower() == 30);
    }

    static void testCastSpell() {
        std::vector<std::string> spells = { "Fireball", "Ice Bolt", "Lightning Strike" };
        Wizard w("AureluDauCuSpelu", 100, 5, 50, spells, 20);
        bool castSuccess = w.castSpell("Magic Missile");
        assert(!castSuccess);
        assert(w.getMana() == 50);
        castSuccess = w.castSpell("Ice Bolt");
        assert(castSuccess);
        assert(w.getMana() == 40);
    }
};

class KnightTest {
public:
    static void runTests() {
        testTakeDamage();
        testSettersGetters();
        cout << "All Knight tests passed!(:" << endl;
    }

    static void testTakeDamage() {
        Knight k("Arthur", 100, 5, 0, 5);

        // Take damage that reduces armor to 0
        k.takeDamage(4);
        assert(k.getArmor() == 0);
        assert(k.getHealth() != 100);

        // Take damage that reduces armor below 0
        k.takeDamage(8);
        assert(k.getArmor() == 0);
        assert(k.getHealth() != 100);
    }
    static void testSettersGetters() {
        Knight k("Arthur", 100, 5, 0, 5);

        assert(k.getName() == "Arthur");
        assert(k.getHealth() == 100);
        assert(k.getLevel() == 5);
        assert(k.getSwordDamage() == 5);
        assert(k.getArmor() == 0);

        // Test setters
        k.setName("Lancelot");
        k.setHealth(90);
        k.setLevel(6);
        k.setSwordDamage(6);
        k.setArmor(0);

        assert(k.getName() == "Lancelot");
        assert(k.getHealth() == 90);
        assert(k.getLevel() == 6);
        assert(k.getSwordDamage() == 6);
        assert(k.getArmor() == 0);
    }

};

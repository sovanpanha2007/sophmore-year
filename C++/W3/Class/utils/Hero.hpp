// Cleaned-up Hero.hpp
#ifndef UTILS_HERO_HPP
#define UTILS_HERO_HPP

    #include <iostream>
    #include <string>
#include <algorithm>

using namespace std;

class Hero{

    private:
        string name;
        int health;
        int armor;
        int power;
        string weapon;
        
    public:
        Hero(string name, int health, int armor, int power, string weapon){
            this->name = name;
            this->health = health;
            this->armor = armor;
            this->power = power;
            this->weapon = weapon;
        }

        void info() const{
            cout << "Name: " << getName()<< endl;
            cout << "Health: " << getHealth() << endl;
            cout << "Armor: " << getArmor() << endl;
            cout << "Power: " << getPower() << endl;
            cout << "Weapon: " << getWeapon() << "\n" << endl;
        }

        void strike(Hero& enemy){
            cout << name << " strikes " << enemy.name << " with " << weapon << " (power " << power << ")" << endl;

            int remaining = power;
            if (enemy.armor > 0){
                int absorbed = min(remaining, enemy.armor);
                enemy.armor -= absorbed;
                remaining -= absorbed;
                cout << " -> " << enemy.name << "'s armor absorbs " << absorbed << " damage (armor now " << enemy.armor << ")" << endl;
            }
            if (remaining > 0){
                enemy.health -= remaining;
                cout << " -> " << enemy.name << " takes " << remaining << " health damage (health now " << enemy.health << ")" << endl;
                if (enemy.health <= 0) {
                    enemy.health = 0; 
                    cout << " -> " << enemy.name << " died" << endl;
                }
            }
        }

        string getName() const { return name; }
        int getHealth() const { return health; }
        int getArmor() const { return armor; }
        int getPower() const { return power; }
        string getWeapon() const { return weapon; }
};

#endif

#include <iostream>
#include <cstring>
#include "SuperHero.h"

using namespace std;

namespace sict 
{
   SuperHero::SuperHero() : Hero()
   {
      m_bonus = 0;
      m_defend = 0;
   }

   SuperHero::SuperHero(const char name[], int health, int attack, int bonus, int defend) : Hero(name, health, attack)
   {
      *this = SuperHero();
      if (name != nullptr && name[0] != '\0' && health > 0 && attack > 0 && bonus > 0 && defend > 0) 
      {
         strcpy(m_name, name);
         m_health = health;
         m_attack = attack;
         m_bonus = bonus;
         m_defend = defend;
      }
   }

   int SuperHero::attackStrength() const
   {
      return m_bonus + m_attack;
   }

   int SuperHero::defend() const 
   {
      return m_defend;
   }

   void SuperHero::operator-=(int attack)
   {
      if (attack > 0)
      {
         m_health -= attack - this->defend();
         if (m_health < 0) 
         {
            m_health = 0;
         }
      }
        
   }

   const SuperHero& operator*(const SuperHero& first, const SuperHero& second)
   {
      SuperHero one = first;
      SuperHero two = second;
      const SuperHero *winner = nullptr;
      int round = 0;

      while (one.isAlive() && two.isAlive() && round < max_round)
      {
         round++;
         one -= two.attackStrength();
         two -= one.attackStrength();
      }
      if (one.isAlive() == two.isAlive())
      {
         winner = &first;
      }
      else if (one.isAlive() > two.isAlive()) {
         winner = &first;
      }
      else if (one.isAlive() < two.isAlive()) {
         winner = &second;
      }

      cout << "Super Fight! " << first << " vs " << second << " : " << "Winner is " << *winner << " in " << round << " rounds." << endl;
      return *winner;
   
   }
}
// Workshop 7 - Derived Classes
// File Hero.cpp
// Version 2.0
// Date 2018/03/20
// Author       Sang Jun Park
// Description
//       This file demonstrates the client module of w7
/////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
#include "Hero.h"

using namespace std;

namespace sict
{

   Hero::Hero()
   {
      m_name[0] = '\0';
      m_health = 0;
      m_attack = 0;
   }

   Hero::Hero(const char name[], int health, int attack)
   {
      *this = Hero();
      if (name != nullptr && name[0] != '\0' && health > 0 && attack > 0)
      {
         strcpy(m_name, name);
         m_health = health;
         m_attack = attack;
      }
   }

   void Hero::operator-=(int attack)
   {
      if (attack > 0)
      {
         m_health -= attack;
         if (m_health < 0)
         {
            m_health = 0;
         }
      }
   }

   bool Hero::isAlive() const
   {
      return m_health > 0;
   }

   int Hero::attackStrength() const
   {
      return m_attack;
   }

   ostream& operator<<(ostream& os, const Hero& hero)
   {
      if (hero.m_name[0] == '\0' && hero.m_attack == 0 && hero.m_health == 0)
      {
         os << "No hero" << endl;
      }
      else {
         os << hero.m_name;
      }
      return os;
   }

   const Hero& operator*(const Hero& first, const Hero& second)
   {
      Hero one = first;
      Hero two = second;
      const Hero* winner = nullptr;

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

      cout << "Ancient Battle! " << first << " vs " << second << " : " << "Winner is " << *winner << " in " << round << " rounds." << endl;
      return *winner;
   }

}
// Workshop 7 - Derived Classes
// File Hero.h
// Version 2.0
// Date 2018/03/20
// Author       Sang Jun Park
// Description
//       This file demonstrates the client module of w7
/////////////////////////////////////////////////////
#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H
#include"Hero.h"

namespace sict
{

   class SuperHero : public Hero
   {
      int m_bonus;
      int m_defend;

   public:
      SuperHero();
      SuperHero(const char name[], int health, int attack, int bonus, int defend);
      void operator-=(int attack);
      int attackStrength() const;
      int defend() const;

   };

   const SuperHero& operator*(const SuperHero& first, const SuperHero& second);

}
#endif

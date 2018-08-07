// Workshop 7 - Derived Classes
// File Hero.h
// Version 2.0
// Date 2018/03/20
// Author       Sang Jun Park
// Description
//       This file demonstrates the client module of w7
/////////////////////////////////////////////////////
#ifndef SICT_HERO_H
#define SICT_HERO_H

namespace sict
{

   const int max_round = 100;

   class Hero
   {
   protected:
      char m_name[41];
      int m_health;
      int m_attack;

   public:
      Hero();
      Hero(const char name[], int health, int attack);
      void operator-=(int attack);
      bool isAlive() const;
      int attackStrength() const;

      friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
   };

   const Hero& operator*(const Hero& first, const Hero& second);

}
#endif


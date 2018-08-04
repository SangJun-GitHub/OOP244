/***********************************************************
// Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 2.0
// Date 2018.02.04
// Author Sang Jun, Park
// Description
// Email sjpark24@myseneca.ca
// Student number 112293170
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
***********************************************************/
#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H

namespace sict 
{
   class Kingdom
   {
   public:
      char m_name[32];
      int m_population;

   };
   void display(const Kingdom&);
   void display(const Kingdom* pKingdom, int count);
}
#endif
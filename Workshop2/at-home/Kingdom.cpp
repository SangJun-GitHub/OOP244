/***********************************************************
// Workshop 2: Dynamic Memory
// File Kingdom.cpp
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
#include <iostream>
#include "Kingdom.h"

using namespace std;

namespace sict 
{
   void display(const Kingdom& pKingdom)
   {
      cout << pKingdom.m_name << ", population " << pKingdom.m_population << endl; 
   }

   void display(const Kingdom* pKingdom, int count)
   {
      int totalPop = 0;
      cout << "------------------------------" << endl;
      cout << "Kingdoms are" << endl;
      cout << "------------------------------" << endl;
      for (int i = 0; i < count; i++) 
      {
         cout << i + 1 << ". " << pKingdom[i].m_name
            << ", population " << pKingdom[i].m_population << endl;
         totalPop += pKingdom[i].m_population;
      }
      cout << "------------------------------" << endl;
      cout << "Total population of all Kingdoms: " << totalPop << endl;
      cout << "------------------------------" << endl;
   }
}
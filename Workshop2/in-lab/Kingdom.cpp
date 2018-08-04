/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date : 2018-01-30
// Author : Sang Jun, Park
// Description
// Email : sjpark24@myseneca.ca
// Student number : 112293170
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/


// TODO: include the necessary headers
#include <iostream>
#include "Kingdom.h"
using namespace std;

// TODO: the sict namespace
namespace sict
{

   // TODO:definition for display(...) 
   void display(const Kingdom& pKingdom)
   {
      cout << pKingdom.m_name << ", population " << pKingdom.m_population << endl;
   }

}
// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: Allocator.cpp
// Version: 2.0
// Date: 2018/03/27
// Author: Sang Jun Park
// Description:
// This file tests in_lab section of your workshop
///////////////////////////////////////////////////
#include "SavingsAccount.h" 

namespace sict {

	// define interest rate
	//
   const double savingRate = 0.05;

	// TODO: Allocator function
	//
   iAccount* CreateAccount(const char* accountType, double balance)
   {
      SavingsAccount* type = nullptr;
      if (accountType[0] == 'S' || accountType[0] == 's')
      {
         SavingsAccount* CreateAccount = new SavingsAccount(balance, savingRate);
         type = CreateAccount;
      }
         return type;
   }

}

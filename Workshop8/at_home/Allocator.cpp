// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: Allocator.cpp
// Version: 2.0
// Date: 2018/04/01
// Author: Sang Jun Park
// Description:
// This file tests at_home section of your workshop
///////////////////////////////////////////////////
#include "SavingsAccount.h"
#include "ChequingAccount.h"

namespace sict {

	// define interest rate
	//
   const double savingRate = 0.05;
   const double transactionFee = 0.50;
   const double monthlyFee = 2.00;


	// TODO: Allocator function
	//
   iAccount* CreateAccount(const char* accountType, double balance)
   {

      if (accountType[0] == 'S' || accountType[0] == 's')
      { 
         SavingsAccount* CreateAccount = new SavingsAccount(balance, savingRate);
         return CreateAccount;
      } else if (accountType[0] == 'C' || accountType[0] == 'c'){
         ChequingAccount* CreateAccount = new ChequingAccount(balance, transactionFee, monthlyFee);
         return CreateAccount;
      } else { 
         return nullptr; 
      }
   }
}

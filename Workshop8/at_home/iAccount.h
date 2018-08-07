// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: iAccount.h
// Version: 2.0
// Date: 2018/04/01
// Author: Sang Jun Park
// Description:
// This file tests at_home section of your workshop
///////////////////////////////////////////////////
#ifndef SICT_IACCOUNT_H__
#define SICT_IACCOUNT_H__
#include <iostream>

namespace sict 
{
	class iAccount 
   {
	public:
		// TODO: credit adds +ve amount to the balance
      virtual bool credit(double credit) = 0;

		// TODO: debit subtracts a +ve amount from the balance
      virtual bool debit(double debit) = 0;

		// TODO: month end adds month end costs
      virtual void monthEnd() = 0;

		// TODO: display inserts the account information into an ostream
      virtual void display(std::ostream&) const = 0;
	};

	// TODO: add prototype for Allocator function
   iAccount* CreateAccount(const char* accountType, double balance);
}
#endif


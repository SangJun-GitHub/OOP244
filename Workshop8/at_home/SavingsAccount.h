// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: SavingsAccount.h
// Version: 2.0
// Date: 2018/04/01
// Author: Sang Jun Park
// Description:
// This file tests at_home section of your workshop
///////////////////////////////////////////////////
#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__
#include "Account.h"

namespace sict 
{
	class SavingsAccount : public Account
   {
      double m_rate;

	public:
			// TODO: constructor initializes balance and interest rate
      SavingsAccount(double balance, double rate);

			// TODO: perform month end transactions
      void monthEnd();

			// TODO: display inserts the account information into an ostream			
      void display(std::ostream& out) const;
	};
}
#endif

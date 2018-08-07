// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: Account.h
// Version: 2.0
// Date: 2018/03/27
// Author: Sang Jun Park
// Description:
// This file tests in_lab section of your workshop
///////////////////////////////////////////////////
#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__
#include "iAccount.h"

namespace sict 
{
	class Account : public iAccount
   {
      double m_balance;

	protected:
      double balance() const;

	public:
		// TODO: constructor initializes account balance, defaults to 0.0 
      Account(double balance);

		// TODO: credit adds +ve amount to the balance 
      bool credit(double creadit);

		// TODO: debit subtracts a +ve amount from the balance
      bool debit(double debit);
	};
}
#endif

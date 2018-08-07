// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.h
// Version: 2.0
// Date: 2018/04/01
// Author: Sang Jun Park
// Description:
// This file tests at_home section of your workshop
///////////////////////////////////////////////////
#ifndef SICT_CHEQUINGACCOUNT_H__
#define SICT_CHEQUINGACCOUNT_H__

#include "Account.h"

namespace sict 
{
	class ChequingAccount : public Account
   {
      double m_transactionFee;
      double m_monthlyFee;

		public:
			// TODO: constructor initializes account balance and transaction fee
         ChequingAccount(double balance, double transactionFee, double monthEndFee);

			// TODDO: credit adds +ve amount to the balance
         bool credit(double credit);

			// TODO: debit subtracts a +ve amount from the balance
         bool debit(double debit);

			// TODO: month end
         void monthEnd();

			// TODO: display inserts the account information into an ostream
         void display(std::ostream& out) const;
	};
}
#endif

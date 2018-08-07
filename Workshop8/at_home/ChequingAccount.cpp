// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2018/04/01
// Author: Sang Jun Park
// Description:
// This file tests at_home section of your workshop
///////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include "ChequingAccount.h"

using namespace std;

namespace sict 
{
	// constructor initializes balance and transaction fee
	//
   ChequingAccount::ChequingAccount(double balance, double transactionFee, double monthEndFee) : Account(balance)
   {
      m_transactionFee = 0;
      m_monthlyFee = 0;

      if (transactionFee > 0)
      {
         m_transactionFee = transactionFee;
      }
      if (monthEndFee > 0) 
      {
         m_monthlyFee = monthEndFee;
      }
   }

	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	//
   bool ChequingAccount::credit(double credit)
   {
      bool valid = false;
      if ((balance() + credit) - m_transactionFee > 0) 
      {
         double caluator = credit - m_transactionFee;
         Account::credit(caluator);
         valid = true;
      }
      return valid;
   }

	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	//
   bool ChequingAccount::debit(double debit)
   {
      bool valid = false;
      if ((balance() - debit) - m_transactionFee > 0) 
      {
         double caluator = debit + m_transactionFee;
         Account::debit(caluator);
      }
      return valid;
   }

	// monthEnd debits month end fee
	//
   void ChequingAccount::monthEnd()
   {
      Account::debit(m_transactionFee + m_monthlyFee);
   }

	// display inserts account information into ostream os
	//
   void ChequingAccount::display(std::ostream& out) const
   {
      out << fixed << setprecision(2);
      out << "Account type: Chequing" << endl;
      out << "Balance: $" << balance() << endl;
      out << "Per Transaction Fee: " << m_transactionFee << endl;
      out << "Monthly Fee: " << m_monthlyFee << endl;
   }
}
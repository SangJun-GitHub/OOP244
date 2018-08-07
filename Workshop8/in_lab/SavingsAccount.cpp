// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: SavingsAccount.cpp
// Version: 2.0
// Date: 2018/03/27
// Author: Sang Jun Park
// Description:
// This file tests in_lab section of your workshop
///////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include "SavingsAccount.h"

using namespace std;

namespace sict
{

   // TODO: constructor initializes balance and interest rate
   SavingsAccount::SavingsAccount(double balance, double rate) : Account(balance)
   {
      if (rate > 0) 
      {
         m_rate = rate;
      } else { 
         m_rate = 0; 
      }
   }

   // TODO: perform month end transactions
   void SavingsAccount::monthEnd()
   {
      credit(balance() * m_rate);
   }

   // TODO: display inserts the account information into an ostream			
   void  SavingsAccount::display(std::ostream& out) const 
   {
      out << fixed << setprecision(2);
      out << "Account type: Savings" << endl;
      out << "Balance: $" << balance() << endl;
      out << "Interest Rate (%): " << m_rate * 100 << endl;
   }
}

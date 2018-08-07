// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: Account.cpp
// Version: 2.0
// Date: 2018/04/01
// Author: Sang Jun Park
// Description:
// This file tests at_home section of your workshop
///////////////////////////////////////////////////
#include "Account.h"

namespace sict 
{
   double Account::balance() const
   {
      return m_balance;
   }
   
   Account::Account(double balance) 
   {
      if (balance > 0) 
      {
         m_balance = balance;
      } else {
         m_balance = 0;
      }
   }

   bool Account::credit(double credit) 
   {
      bool valid = false;
      if (credit > 0) 
      {
         m_balance = balance() + credit;
         valid = true;
      }
      return valid;
   }

   bool Account::debit(double debit)
   {
      bool valid = false;
      if (debit > 0) 
      {
         m_balance = balance() - debit;
         valid = true;
      }
      return valid;
   }
}

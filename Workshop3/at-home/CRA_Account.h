/**********************************************************
// Workshop 3: Classes and Privacy
// CRA_Account.h
// Version 2.1
// 2018/02/11
// Sang Jun, Park
// Description
// Email: sjpark24@myseneca.ca
// Student number: 112293170
// 
//
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		          Reason
// 
///////////////////////////////////////////////////////////
**********************************************************/
#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

namespace sict
{
   const int max_name_length = 40;
   const long min_sin = 100000000;
   const long max_sin = 999999999;
   const int max_yrs = 4;

   class CRA_Account
   {
   private:
      char m_familyName[max_name_length + 1];
      char m_givenName[max_name_length + 1];
      int m_sin;
      int m_tax[max_yrs];
      double m_balance[max_yrs];
      int m_years;

   public:
      void set(const char* familyName, const char* givenName, int sin);
      bool isEmpty() const;
      void display() const;
      void set(int year, double balance);
   };
}
#endif

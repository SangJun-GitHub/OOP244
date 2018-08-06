/**********************************************************
// Workshop 3: Classes and Privacy
// CRA_Account.cpp
// Version 2.1
// 2017/09/09
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
#include <iostream>
#include <cstring>
#include <cmath>
#include "CRA_Account.h"

using namespace std;
using namespace sict;

void CRA_Account::set(const char* familyName, const char* givenName, int sin)
{
   {
      if ((sin < max_sin) && (sin > min_sin) && (familyName[0] != '\0') && (givenName[0] != '\0')) {
         int check = 0;
         int c_sin1 = sin / 10;
         int c_sin2 = sin / 100;
         check += sin % 10;
         int cal1 = 0;
         int cal2 = 0;
         int total = 0;
         int hight = 0;
         for (int i = 0; i < 4; i++) {
            int add = 2 * (c_sin1 % 10);
            if (add >= 10) {
               cal1 += add % 10;
               cal1 += add / 10;
            }
            else {
               cal1 += add;
            }
            c_sin1 /= 100;
         }
         for (int i = 0; i < 4; i++) {
            cal2 += c_sin2 % 10;
            c_sin2 /= 100;
         }
         total = cal1 + cal2;
         hight = ((total / 10) + 1) * 10;
         total = hight - total;
         if (check == total) {
            strcpy(m_familyName, familyName);
            strcpy(m_givenName, givenName);
            m_sin = sin;
            m_years = 0;
         }
      }
         else {
            strcpy(m_familyName, "");
            strcpy(m_givenName, "");
            m_sin = 0;
            m_years = 0;
         }
      
   }
}

bool CRA_Account::isEmpty() const
{
   if ((m_sin == 0) || (m_sin > max_sin) || (m_sin < min_sin)||(m_familyName[0] == '\0')||(m_givenName[0] == '\0'))
   {
      return true;
   }
   else {
      return false;
   }
}

void CRA_Account::display() const
{
   if ((m_familyName != nullptr) && (m_givenName != nullptr) && (m_sin != 0))
   {
      cout << "Family Name: " << m_familyName << endl;
      cout << "Given Name : " << m_givenName << endl;
      cout << "CRA Account: " << m_sin << endl;
      for (int i = 0; i < m_years; i++) {
            cout.setf(ios::fixed);
            cout.precision(2);
            if (m_balance[i] > 2) {
               cout << "Year (" << m_tax[i] << ") balance owing: " << fabs(m_balance[i]) << endl;
            } else if (m_balance[i] < -2) {
               cout << "Year (" << m_tax[i] << ") refund due: " << fabs(m_balance[i]) << endl;
               }
            else { 
               cout << "Year (" << m_tax[i] << ") No balance owing or refund due!" << endl;
            }
      }
      cout.unsetf(ios::fixed);
      cout.precision(6);
   } else {
      cout << "Account object is empty!" << endl;
   }
}
void CRA_Account::set(int year, double balance)
{
   if ((m_sin != 0) && (m_sin < max_sin) && (m_sin > min_sin))
   {
      if (m_years < max_yrs) {
         m_tax[m_years] = year;
         m_balance[m_years] = balance;
         m_years++;
      } 
   }
}
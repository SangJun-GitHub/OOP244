#include <iostream>
#include <cstring>
#include "CRA_Account.h"

using namespace std;
using namespace sict;

void CRA_Account::set(const char* familyName, const char* givenName, int sin)
{
   if ((sin > max_sin) || (sin < min_sin)) 
   {
      strcpy(m_familyName, "");
      strcpy(m_givenName, "");
      sin = 0;
   } else {
      strcpy(m_familyName, familyName);
      strcpy(m_givenName, givenName);
      m_sin = sin;
   }
}

bool CRA_Account::isEmpty() const
{
   if ((m_sin == 0) || (m_sin > max_sin) || (m_sin < min_sin)) 
   {
      return true;
   } else {
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
   } else {
      cout << "Account object is empty!" << endl;
   }
}
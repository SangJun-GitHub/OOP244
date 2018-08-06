// Workshop 6 - Class with a Resource
// Contact.cpp
// Snag Jun Park
// 2018/03/18

#include <iostream>
#include <cstring>
#include "Contact.h"

using namespace std;

namespace sict
{
   Contact::Contact()
   {
      m_name[0] = '\0';
      m_phoneNumber = nullptr;
      m_numOfPhoneNumber = 0;
   }

   Contact::Contact(const char* name, long long* phoneNumber, int numOfPhoneNumber)
   {
      m_name[0] = '\0';
      m_phoneNumber = nullptr;
      m_numOfPhoneNumber = 0;

      long long check;
      int contry = 0;
      int area = 0;
      int pNumber = 0;

      if (name != nullptr && name[0] != '\0')
      {
         strncpy(m_name, name, 20);
         m_name[19] = '\0';
         for (int i = 0; i < numOfPhoneNumber; i++)
         {
            m_phoneNumber = new long long[numOfPhoneNumber];
            m_numOfPhoneNumber = numOfPhoneNumber;
            for (int i = 0; i < numOfPhoneNumber; i++)
            {
               check = phoneNumber[i];
               contry = check / 10000000000;
               area = check / 10000000 % 1000;
               pNumber = check % 10000000;
               if ((contry >= 1 && contry <= 99) && (area >= 100 && area <= 999) && (pNumber >= 1000000 && pNumber <= 9999999))
               {
                  m_phoneNumber[i] = phoneNumber[i];
               }
            }
         }
      }
   }

   Contact::Contact(const Contact& rhs) {
      if (isEmpty() == false)
      {
         strncpy(m_name, rhs.m_name, 20);
         m_name[19] = '\0';
         m_numOfPhoneNumber = rhs.m_numOfPhoneNumber;
         if (m_numOfPhoneNumber > 0) {
            long long *temp = new long long[m_numOfPhoneNumber];
            for (int i = 0; i < m_numOfPhoneNumber; i++)
            {
               temp[i] = rhs.m_phoneNumber[i];
            }
            m_phoneNumber = temp;
         }
         else {
            m_phoneNumber = nullptr;
         }
      }
      else {
         for (int i = 0; i < 21; i++)
         {
            m_name[i] = '\0';
         }
         delete[] m_phoneNumber;
         m_phoneNumber = nullptr;
         m_numOfPhoneNumber = 0;
      }
   }

   Contact::~Contact()
   {
      delete[] m_phoneNumber;
      m_phoneNumber = nullptr;
   }

   bool Contact::isEmpty() const
   {
      bool empty = false;
      if (m_name[0] == '\0')   
      {
         empty = true;
      }
      return empty;
   }

   void Contact::display() const
   {
      int contry;
      int area;
      int pNumberfirst;
      int pNumberlast;

      if (isEmpty())
      {
         cout << "Empty contact!" << endl;
      } else {
         cout << m_name << endl;
         for (int i = 0; i < m_numOfPhoneNumber; i++) 
         {
            contry = m_phoneNumber[i] / 10000000000;
            area = m_phoneNumber[i] / 10000000 % 1000;
            pNumberfirst = m_phoneNumber[i] % 10000000 / 10000;
            pNumberlast = m_phoneNumber[i] % 10000;
            cout << "(+" << contry << ") " << area << " " << pNumberfirst << "-";
            cout.width(4);
            cout.fill('0');
            cout << pNumberlast << endl;
         }
      }
   }

   Contact& Contact::operator=(const Contact &rhs) 
   {
      if (this != &rhs)
      {
         if (m_phoneNumber != nullptr) 
         {
            delete[] m_phoneNumber;
            m_phoneNumber = nullptr;
         }
         m_numOfPhoneNumber = rhs.m_numOfPhoneNumber;
         strncpy(m_name, rhs.m_name, 20);
         m_name[19] = '\0';
         m_phoneNumber = new long long[m_numOfPhoneNumber];
         for (int i = 0; i < m_numOfPhoneNumber; i++) 
         {
            m_phoneNumber[i] = rhs.m_phoneNumber[i];
         }
      }
      return *this;
   }

   Contact& Contact::operator+=(const long long phoneNumber) 
   {
      long long* temp;
      temp = new long long[m_numOfPhoneNumber + 1];
      for (int i = 0; i < m_numOfPhoneNumber; i++) 
      {
         temp[i] = m_phoneNumber[i];
      }
      m_numOfPhoneNumber++;
      if (m_phoneNumber != nullptr) 
      {
         delete[] m_phoneNumber;
      }
      m_phoneNumber = new long long[m_numOfPhoneNumber];
      for (int a = 0; a < m_numOfPhoneNumber; a++) 
      {
         m_phoneNumber[a] = temp[a];
      }
      m_phoneNumber[m_numOfPhoneNumber - 1] = phoneNumber;
      delete[] temp;
      return *this;
   }

}
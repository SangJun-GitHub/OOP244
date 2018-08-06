// Workshop 6 - Class with a Resource
// Contact.cpp
// Snag Jun Park
// 2018/03/13

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

   Contact::~Contact()
   {
      delete[] m_phoneNumber;
      m_phoneNumber = nullptr;
   }

   bool Contact::isEmpty() const
   {
      bool empty = false;
      if (m_name[0] == '\0' && m_phoneNumber == nullptr && m_numOfPhoneNumber == 0)
      {
         empty = true;
      }
      return empty;
   }

   void Contact::display() const
   {
      long long tem_number = 0;
      int number[20];
      int number_count = 0;
      if (isEmpty())
      {
         cout << "Empty contact!" << endl;
      }
      else {
         cout << m_name << endl;

         for (int i = 0; i < m_numOfPhoneNumber; i++)
         {
            tem_number = m_phoneNumber[i];
            while (tem_number != 0)
            {
               number[number_count] = tem_number % 10;
               tem_number /= 10;
               number_count++;
            }
            if (number_count == 11)
            {
               cout << "(+" << number[10] << ") " << number[9] << number[8] << number[7] << " "
                  << number[6] << number[5] << number[4] << "-" << number[3]
                  << number[2] << number[1] << number[0] << endl;
            }
            else if (number_count == 12) {
               cout << "(+" << number[11] << number[10] << ") " << number[9] << number[8]
                  << number[7] << " " << number[6] << number[5] << number[4] << "-" << number[3]
                  << number[2] << number[1] << number[0] << endl;
            }
            while (number_count != 0) {
               number[number_count] = 0;
               number_count--;
            }
         }
      }
   }
}
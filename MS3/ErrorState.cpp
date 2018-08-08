// Final Project - Milestone 3 - Product Module
// Version 3.3
// Date	2018-04-09
// ErrorState.cpp
// Author	SangJunPark
/////////////////////////////////////////////////////////////////    
#include <cstring>
#include <iostream>
#include "ErrorState.h"
using namespace std;

namespace AMA {

   ErrorState::ErrorState(const char* errorMessage)
   {
      m_message = nullptr;
      if (errorMessage)
         message(errorMessage);
   }
   ErrorState::~ErrorState()
   {
      delete[] this->m_message;
   }
   bool ErrorState::isClear()const 
   {
      bool empty = true;
      if (this->m_message != nullptr) 
      {
         empty = false;
      }
         return empty;
   }
   void ErrorState::clear()
   {
      delete[] m_message;
      m_message = nullptr;
   }
   void ErrorState::message(const char * str)
   {
      if (str == nullptr) 
      {
         m_message = nullptr;
      } else {
         if (this->m_message != nullptr)
         {
            delete[] m_message;
            m_message = new char[strlen(str) + 1];
            strcpy(m_message, str);
         }
      }
   }
   const char * ErrorState::message() const
   {
      return m_message;
   }
   std::ostream& operator<<(std::ostream& os, const ErrorState& e) {
      if (!e.isClear()) {
         os << e.message();
      }
      return os;
   }
}




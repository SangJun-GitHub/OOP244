// Final Project Milestone 5
//
// Name:Sang Jun Park Date:2018.04.16
///////////////////////////////////////////////////////////////// 
#include <iostream>
#include <cstring>
#include "ErrorState.h"

namespace AMA 
{
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
            delete[] m_message;
            m_message = nullptr;
            m_message = new char[strlen(str) + 1];
            strcpy(m_message, str);
            m_message[strlen(str)] = '\0';
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




// Final Project Milestone 2 - ErrorState Class
// Version 3.3
// ErrorState.cpp
// Date	2018-03-03
// Author	Chris Szalwinski, Fardad Soleimanloo
//
// For you final test before submission:
//      DO NOT MODIFY THIS FILE IN ANY WAY
//
//
// Revision History
// --------------------------------------------------------------
// Name               Date                 Reason
// Sang Jun Park     2018/03/23
/////////////////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
#include "ErrorState.h"

using namespace std;

namespace AMA 
{

   ErrorState::ErrorState(const char* errorMessage)
   {
      if (errorMessage == nullptr) 
      {
         m_errorMessage = nullptr;
      } else {
         m_errorMessage = nullptr;
         message(errorMessage);
      }
   }

   ErrorState::~ErrorState()
   {
      clear();
   }

   void ErrorState::clear()
   {
      delete[] m_errorMessage;
      m_errorMessage = nullptr;
   }

   bool ErrorState::isClear() const
   {
      return m_errorMessage == nullptr;
   }

   void ErrorState::message(const char* str)
   {
      if (m_errorMessage != nullptr) 
      {
         clear();
      }
      m_errorMessage = new char[strlen(str) + 1];
      strcpy(m_errorMessage, str);
   }

   const char* ErrorState::message()const
   {
      return m_errorMessage;
   }

   std::ostream& operator<<(std::ostream& out, const ErrorState& errorMessage)
   {
      if (!errorMessage.isClear())
      {
         out << errorMessage.message();
      }
      return out;
   }
}
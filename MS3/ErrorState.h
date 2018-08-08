// Final Project - Milestone 3 - Product Module
// Version 3.3
// Date	2018-04-09
// ErrorState.h
// Author	SangJunPark
/////////////////////////////////////////////////////////////////
#ifndef AMA_ERROR_H
#define AMA_ERROR_H
#include <iostream>
#include <cstring>

namespace AMA 
{
   class ErrorState 
   {
   private:
      char* m_message;

   public:
      explicit ErrorState(const char* errorMessage = nullptr);
      ErrorState(const ErrorState& em) = delete;
      ErrorState& operator=(const ErrorState& em) = delete;
      virtual ~ErrorState();
      void clear();
      bool isClear()const;
      void message(const char* str);
      const char* message()const;
   };
   std::ostream& operator<<(std::ostream& os, const ErrorState& e);
}
#endif
// Final Project Milestone 5
//
// Name:Sang Jun Park Date:2018.04.16
/////////////////////////////////////////////////////////////////
#ifndef AMA_ERROR_H
#define AMA_ERROR_H
#include <iostream>

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
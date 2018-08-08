// Final Project Milestone 2 - ErrorState Class
// Version 3.3
// ErrorState.h
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
#ifndef AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H

namespace AMA 
{
   class ErrorState 
   {
      char* m_errorMessage;

   public:
      explicit ErrorState(const char* errorMessage = nullptr);
      ErrorState(const ErrorState& em) = delete;
      ErrorState& operator=(const ErrorState& em) = delete;
      virtual ~ErrorState();
      void clear();
      bool isClear() const;
      void message(const char* str);
      const char* message()const;

   };
   std::ostream& operator<<(std::ostream& out, const ErrorState& errorMessage);
}
#endif
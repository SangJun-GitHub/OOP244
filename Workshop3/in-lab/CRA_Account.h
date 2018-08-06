#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

namespace sict
{
   const int max_name_length = 40;
   const long min_sin = 100000000;
   const long max_sin = 999999999;

   class CRA_Account
   {
   private:
      char m_familyName[max_name_length + 1];
      char m_givenName[max_name_length + 1];
      int m_sin;
   
   public:
      void set(const char* familyName, const char* givenName, int sin);
      bool isEmpty() const;
      void display() const;
   };
}
#endif
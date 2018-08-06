// Workshop 6 - Class with a Resource
// Contact.h
// Snag Jun Park
// 2018/03/13

#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

namespace sict 
{
   class Contact 
   {
      char m_name[20];
      long long* m_phoneNumber;
      int m_numOfPhoneNumber;
   
   public:
      Contact();
      Contact(const char* name, long long* phoneNumber, int numOfPhoneNumber);
      ~Contact();
      bool isEmpty() const;
      void display() const;
   };
}
#endif
// Workshop 6 - Class with a Resource
// Contact.h
// Snag Jun Park
// 2018/03/18

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
      Contact(const Contact& rhs);
      ~Contact();
      bool isEmpty() const;
      void display() const;

      Contact& operator+=(long long phoneNumber);
      Contact& operator=(const Contact &rhs);
   };
}
#endif
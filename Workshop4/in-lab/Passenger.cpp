// TODO: add file header comments here
// Workshop 4 - Constructors - Test Main
// Passenger.cpp
// Sang Jun, Park
// 2/13/2018
//
// TODO: add your headers here
#include <iostream>
#include <cstring>
#include "Passenger.h"

using namespace std;

// TODO: continue your namespace here
namespace sict {
   // TODO: implement the default constructor here
   Passenger::Passenger() 
   {
      m_name[0] = '\0';
      m_destination[0] = '\0';
   }
  // TODO: implement the constructor with 2 parameters here
   Passenger::Passenger(const char name[], const char destination[]) 
   {
      if ((name == '\0') || (name == nullptr) || (destination == '\0') || (destination == nullptr))
      {
         m_name[0] = '\0';
         m_destination[0] = '\0';
      } else {
         strcpy(m_name, name);
         strcpy(m_destination, destination);
      }
   }
   // TODO: implement isEmpty query here
   bool Passenger::isEmpty() const
   {
      bool empty = false;
      if ((m_name[0] == '\0') || (m_destination[0] == '\0'))
      {
         empty = true;
      }
      return empty;

   }
   // TODO: implement display query here
   void Passenger::display() const 
   {
      if ((m_name[0] != '\0') && (m_destination[0] != '\0')) 
      {
         cout << m_name << " - " << m_destination << endl;
      } else {
         cout << "No passenger!" << endl;
      }
   }
}
/////////////////////////////////////////
// Workshop 4 - Constructors - Test Main
// Passenger.cpp
// Sang Jun, Park
// 2/18/2018
//
/////////////////////////////////////////
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
      m_yearDeparture = 0;
      m_monthDeparture = 0;
      m_dayDeparture = 0;
   }
   // TODO: implement the constructor with 2 parameters here
   Passenger::Passenger(const char name[], const char destination[])
   {
      if ((name == '\0') || (name == nullptr) || (destination == '\0') || (destination == nullptr))
      {
         m_name[0] = '\0';
         m_destination[0] = '\0';
         m_yearDeparture = 0;
         m_monthDeparture = 0;
         m_dayDeparture = 0;
      }
      else {
         strcpy(m_name, name);
         strcpy(m_destination, destination);
         m_yearDeparture = 2017;
         m_monthDeparture = 7;
         m_dayDeparture = 1;
      }
   }
   // TODO: implement isEmpty query here
   bool Passenger::isEmpty() const
   {
      bool empty = false;
      if ((m_name[0] == '\0') || (m_destination[0] == '\0')
         || (m_yearDeparture == 0) || (m_monthDeparture == 0) || (m_dayDeparture == 0))
      {
         empty = true;
      }
      return empty;

   }
   // TODO: implement display query here
   void Passenger::display() const
   {
      if ((m_name[0] != '\0') && (m_destination[0] != '\0')
         && (m_yearDeparture != 0) && (m_monthDeparture != 0) && (m_dayDeparture != 0))
      {
         cout << m_name << " - " << m_destination <<
            " on " << m_yearDeparture << "/";
            if (m_monthDeparture < 10) 
            {
               cout << "0";
            }
            cout << m_monthDeparture << "/";
            if (m_dayDeparture < 10)
            {
               cout << "0";
            }

               cout << m_dayDeparture << endl;
      }
      else {
         cout << "No passenger!" << endl;
      }
   }
   Passenger::Passenger(const char name[], const char destination[], const int year, const int month, const int day)
   {
      if ((name == '\0') || (name == nullptr) || (destination == '\0') || (destination == nullptr)
         || (year < 2017) || (year > 2020) || (month < 1) || (month > 12) || (day < 1) || (day > 31))
      {
         m_name[0] = '\0';
         m_destination[0] = '\0';
         m_yearDeparture = 0;
         m_monthDeparture = 0;
         m_dayDeparture = 0;
      }
      else {
         strcpy(m_name, name);
         strcpy(m_destination, destination);
         m_yearDeparture = year;
         m_monthDeparture = month;
         m_dayDeparture = day;
      }
   }

   const char* Passenger::name() const
   {
      {
         return this->m_name;
      }
   }

   bool Passenger::canTravelWith(const Passenger& aPassenger) const
   {
      bool Companion = false;
      if ((m_yearDeparture == aPassenger.m_yearDeparture) && (m_monthDeparture == aPassenger.m_monthDeparture)
         && (m_dayDeparture == aPassenger.m_dayDeparture))
      {
         Companion = true;
      }
      return Companion;
   }
}
/////////////////////////////////////////
// Workshop 4 - Constructors - Test Main
// Passenger.h
// Sang Jun, Park
// 2/18/2018
//
/////////////////////////////////////////
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

// TODO: declare your namespace here
namespace sict {
   // TODO: define the Passenger class here
   class Passenger
   {
   private:
      char m_name[32];
      char m_destination[32];
      int m_yearDeparture;
      int m_monthDeparture;
      int m_dayDeparture;

   public:
      Passenger();
      Passenger(const char name[], const char destination[]);
      Passenger(const char name[], const char destination[], const int year, const int month, const int day);
      bool isEmpty() const;
      void display() const;
      const char* name() const;
      bool canTravelWith(const Passenger&) const;
   };
}
#endif
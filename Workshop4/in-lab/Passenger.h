// TODO: add file header comments here
// Workshop 4 - Constructors - Test Main
// Passenger.h
// Sang Jun, Park
// 2/13/2018
//
// TODO: add header file guard here
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
   
   public:
      Passenger();
      Passenger(const char name[], const char destination[]);
      bool isEmpty() const;
      void display() const;
   };
}
#endif
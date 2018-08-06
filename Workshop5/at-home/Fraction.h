// Workshop 5: operator overloading
// File: Fraction.h
// Version: 2.0
// Date: 2018/02/25
// Author: Sang Jun, Park
// Student number: 112293170
// E-mail: sjpark24@myseneca.ca
// This file tests in-lab section of your workshop
/////////////////////////////////////////////
// TODO: header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H
// TODO: create namespace
namespace sict {
   // TODO: define the Fraction class
   class Fraction {
      // TODO: declare instance variables 
      int numerator;
      int denominator;
      // TODO: declare private member functions
      int max() const;
      int min() const;
      void reduce();
      int gcd() const;
   public:
      // TODO: declare public member functions
      Fraction();
      Fraction(int num1, int num2);
      bool isEmpty() const;
      void display() const;
      // TODO: declare the + operator overload
      Fraction operator+(const Fraction& rhs) const;
      Fraction operator*(const Fraction& rhs) const;
      bool operator== (const Fraction& rhs) const;
      bool operator!= (const Fraction& rhs) const;
      Fraction& operator+= (const Fraction& rhs);
   };
}
#endif


// Workshop 5: operator overloading
// File: Fraction.cpp
// Version: 2.0
// Date: 2018/02/25
// Author: Sang Jun, Park
// Student number: 112293170
// E-mail: sjpark24@myseneca.ca
// This file tests at-home section of your workshop
/////////////////////////////////////////////
// TODO: insert header files
#include <iostream>
#include <cmath>
#include "Fraction.h"
using namespace std;
// TODO: continue the namespace
namespace sict {
   // TODO: implement the default constructor
   Fraction::Fraction()
   {
      numerator = -1;
      denominator = 0;
   }
   // TODO: implement the two-argument constructor
   Fraction::Fraction(int num1, int num2)
   {
      if (num1 >= 0 && num2 > 0)
      {
         numerator = num1;
         denominator = num2;
         reduce();
      }
      else {
         numerator = -1;
         denominator = 0;
      }
   }
   // TODO: implement the max query
   int Fraction::max() const
   {
      return (numerator > denominator) ? numerator : denominator;
   }
   // TODO: implement the min query
   int Fraction::min() const
   {
      return (numerator > denominator) ? denominator : numerator;
   }
   // gcd returns the greatest common divisor of num and denom
   //
   int Fraction::gcd() const 
   {
      int mn = min();  // min of numerator and denominator
      int mx = max();  // max of numerator and denominator
      int g_c_d = 1;
      bool found = false;
      for (int x = mn; !found && x > 0; --x) 
      { // from mn decrement until divisor found
         if (mx % x == 0 && mn % x == 0) 
         {
            found = true;
            g_c_d = x;
         }
      }
      return g_c_d;
   }
   // TODO: implement the reduce modifier
   void Fraction::reduce()
   {
      int tmpnum = gcd();
      numerator /= tmpnum;
      denominator /= tmpnum;
   }
   // TODO: implement the display query
   void Fraction::display() const
   {
      const bool empty = isEmpty();
      if (empty)
      {
         cout << "no fraction stored";
      }
      else {
         if (numerator%denominator == 0)
         {
            cout << numerator / denominator;
         }
         else {
            cout << numerator << "/" << denominator;

         }
      }
   }
   // TODO: implement the isEmpty query
   bool Fraction::isEmpty() const
   {
      bool empty = false;
      if (numerator == -1 || denominator == 0) 
      {
         empty = true;
      }
      return empty;
   }
   // TODO: implement the + operator
   Fraction Fraction::operator+(const Fraction& rhs) const
   {
      Fraction calnum;
      if (isEmpty() || rhs.isEmpty()) 
      {
         calnum.numerator = -1;
         calnum.denominator = 0;
      } else {
         calnum.numerator = (numerator*rhs.denominator) + (rhs.numerator*denominator);
         calnum.denominator = denominator * rhs.denominator;
         calnum.reduce();
      }
      return calnum;
   }
   Fraction Fraction::operator*(const Fraction& rhs) const
   {
      Fraction calnum;
      if (isEmpty() || rhs.isEmpty()) 
      {
         calnum.numerator = -1;
         calnum.denominator = 0;
      } else {
         calnum.numerator = (numerator * rhs.numerator);
         calnum.denominator = (denominator * rhs.denominator);
      }
      return calnum;
   }
   bool Fraction::operator== (const Fraction& rhs)const
   {
      bool equals = false;
      if (isEmpty() || rhs.isEmpty()) 
      {
         equals = false;
      } else {
         if (numerator*rhs.denominator == rhs.numerator*denominator) 
         {
            equals = true;
         }
      }
      return equals;
   }
   bool Fraction::operator!=(const Fraction& rhs)const
   {
      bool unequals;
      if (isEmpty() || rhs.isEmpty()) 
      {
         unequals = false;
      } else {
         unequals = !(*this == rhs);
      }
      return unequals;
   }
   Fraction& Fraction::operator+= (const Fraction& rhs)
   {
      if (isEmpty() || rhs.isEmpty()) 
      {
         this->numerator = -1;
         this->denominator = 0;
      }
      if (!isEmpty() && !rhs.isEmpty()) 
      {
         this->numerator = (numerator * rhs.denominator) + (rhs.numerator*denominator);
         this->denominator = denominator * rhs.denominator;
         this->reduce();
      }
      return *this;
   }
}

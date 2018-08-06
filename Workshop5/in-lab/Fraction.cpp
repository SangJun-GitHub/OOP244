// Workshop 5: operator overloading
// File: Fraction.cpp
// Version: 2.0
// Date: 2018/02/20
// Author: Sang Jun, Park
// Student number: 112293170
// E-mail: sjpark24@myseneca.ca
// This file tests in-lab section of your workshop
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
      } else {
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
   int Fraction::gcd() const {
      int mn = min();  // min of numerator and denominator
      int mx = max();  // max of numerator and denominator
      int g_c_d = 1;
      bool found = false;

      for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
         if (mx % x == 0 && mn % x == 0) {
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
      if (numerator == -1 || denominator == 0) {
         empty = true;
      }

      return empty;
   }
   // TODO: implement the + operator
   Fraction Fraction::operator+(const Fraction& rhs) const
   {
      Fraction calnum;
      const bool empty = !(this->isEmpty()) && !(rhs.isEmpty());

      if (empty)
      {
         const int result_num1 = (this->numerator*rhs.denominator) + (this->denominator*rhs.numerator);
         const int result_num2 = this->denominator*rhs.denominator;

         calnum = Fraction(result_num1, result_num2);
      }
      else
      {
         calnum.numerator = -1;
         calnum.denominator = 0;
      }

      return calnum;
   }
}

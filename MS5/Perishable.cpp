// Final Project Milestone 5
//
// Name:Sang Jun Park Date:2018.04.16
/////////////////////////////////////////////////////////////////
#include <iostream>
#include "Perishable.h"
#include "Product.h"
#include "Date.h"

namespace AMA 
{
   Perishable::Perishable() : Product('P')
   {
      Date();
   }
   std::fstream& Perishable::store(std::fstream& file, bool newLine) const
   {
      Product::store(file, false);
      file << "," << m_Expiry;
      if (newLine) 
      {
         file << '\n';
      }
      return file;
   }
   std::fstream& Perishable::load(std::fstream& file)
   {
      Product::load(file);
      m_Expiry.read(file);
      file.ignore();
      return file;
   }
   std::ostream& Perishable::write(std::ostream& os, bool linear) const
   {
      Product::write(os, linear);
      if (isClear() && !isEmpty()) 
      {
         if (linear) 
         {
            m_Expiry.write(os);
         } else {
            os << '\n';
            os << " Expiry date: ";
            m_Expiry.write(os);
         }
      }
      return os;
   }
   std::istream& Perishable::read(std::istream& is)
   {
      is.clear();
      Product::read(is);
      if (m_p_error.isClear())
      {
         std::cout << " Expiry date (YYYY/MM/DD): ";
         m_Expiry.read(is);
      }
      if (m_Expiry.errCode() == CIN_FAILED)
      {
         m_p_error.clear();
         m_p_error.message("Invalid Date Entry");
      }
      if (m_Expiry.errCode() == YEAR_ERROR)
      {
         m_p_error.message("Invalid Year in Date Entry");
      }
      if (m_Expiry.errCode() == MON_ERROR)
      {
         m_p_error.clear();
         m_p_error.message("Invalid Month in Date Entry");
      }
      if (m_Expiry.errCode() == DAY_ERROR)
      {
         m_p_error.clear();
         m_p_error.message("Invalid Day in Date Entry");
      }
      if (m_Expiry.errCode())
      {
         is.setstate(std::ios::failbit);
      }
      if (m_Expiry.errCode() != CIN_FAILED && m_Expiry.errCode() != YEAR_ERROR && m_Expiry.errCode() != MON_ERROR && m_Expiry.errCode() != DAY_ERROR)
      {
         m_p_error.clear();
      }
      return is;
   }
   const Date& Perishable::expiry() const
   {
      return m_Expiry;
   }
}
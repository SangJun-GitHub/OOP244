// Final Project Milestone 5
//
// Name:Sang Jun Park Date:2018.04.16
/////////////////////////////////////////////////////////////////
#ifndef AMA_PERISHABLE_H
#define AMA_PERISHABLE_H
#include <iostream>
#include <fstream>
#include "Date.h"
#include "Product.h"

namespace AMA 
{
   class Perishable : public Product
   {
   private:
      Date m_Expiry;

   public:
      Perishable();
      std::fstream& store(std::fstream& file, bool newLine = true) const;
      std::fstream& load(std::fstream& file);
      std::ostream& write(std::ostream& os, bool linear) const;
      std::istream& read(std::istream& is);
      const Date& expiry() const;
   };
}
#endif
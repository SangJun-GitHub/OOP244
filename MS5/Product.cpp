// Final Project Milestone 5
//
// Name:Sang Jun Park Date:2018.04.16
/////////////////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "Product.h"
using namespace std;
namespace AMA 
{
	void Product::name(const char* p_Name)
	{
		if (p_Name != nullptr)
		{
         m_p_Name = new char[strlen(p_Name) + 1];
         strcpy(m_p_Name, p_Name);
         m_p_Name[strlen(p_Name)] = '\0';
      } else {
         delete[] m_p_Name;
         m_p_Name = nullptr;
      }
	}
	const char* Product::name() const
	{
		return  m_p_Name;
	}
	const char* Product::sku() const 
   {
		return m_p_Sku;
	}
	const char* Product::unit() const 
   {
		return m_p_Unit;
	}
	bool Product::taxed() const 
   {
		return m_p_Taxed;
	}
	double Product::price() const 
   {
		return m_p_Price;
	}
	double Product::cost() const 
   {
      double cost = price();
      if (m_p_Taxed)
      {
         cost += (price() * taxRate);
		}
			return cost;
	}
	void Product::message(const char* p_message)
	{
		this->m_p_error.message(p_message);
	}
	bool Product::isClear() const
	{
		return m_p_error.isClear();
	}
	Product::Product(const char type) 
   {
		m_p_Type = type;
		strcpy(m_p_Sku, "");
      m_p_Name = nullptr;
		strcpy(m_p_Unit, "");
		m_p_CurrentQuan = 0;
		m_p_NeedQuan = 0;
		m_p_Price = 0.0;
		m_p_Taxed = true;
      m_p_error.clear();
	}
	Product::Product(const char* p_Sku, const char* p_Name, const char* p_Unit, int p_CurrentQuan, bool p_Taxed, double p_Price, int p_NeedQuan)
   {
		strcpy(m_p_Sku, p_Sku);
      name(p_Name);
		strcpy(m_p_Unit, p_Unit);
		m_p_CurrentQuan = p_CurrentQuan;
      m_p_Taxed = p_Taxed;
		m_p_Price = p_Price;
      m_p_NeedQuan = p_NeedQuan;
      m_p_error.clear();

	}
	Product::Product(const Product& product) 
   {
		*this = product;
	}
	Product& Product::operator=(const Product& product) 
   {
		if (this != &product) ////
      {
			m_p_Type = product.m_p_Type;
			strcpy(m_p_Sku, product.m_p_Sku);
         name(product.m_p_Name);
			strcpy(m_p_Unit, product.m_p_Unit);
			m_p_CurrentQuan = product.m_p_CurrentQuan;
         m_p_Taxed = product.m_p_Taxed;
			m_p_Price = product.m_p_Price;
         m_p_NeedQuan = product.m_p_NeedQuan;
		}
		return *this;
	}
	Product::~Product() 
   {
      delete[] m_p_Name;
	}
	std::fstream& Product::store(std::fstream& file, bool newLine) const 
   {
      if (file.is_open())
         file << m_p_Type << ","
         << m_p_Sku << ","
         << m_p_Name << ","
         << m_p_Unit << ","
         << m_p_Taxed << ","
         << m_p_Price << ","
         << m_p_CurrentQuan << ","
         << m_p_NeedQuan;
      if (newLine)
         file << endl;
      return file;
	}
	std::fstream& Product::load(std::fstream& file) 
   {
      if (file.is_open())
      {
         Product temp;
         char* n = new char[max_name_length + 1];
         file.getline(temp.m_p_Sku, max_sku_length, ',');
         temp.m_p_Sku[strlen(temp.m_p_Sku)] = '\0';
         file.getline(n, max_name_length, ',');
         n[max_name_length] = '\0';
         temp.name(n);
         delete[] n;
         file.getline(temp.m_p_Unit, max_unit_length, ',');
         temp.m_p_Unit[strlen(temp.m_p_Unit)] = '\0';
         file >> temp.m_p_Taxed;
         file.ignore();
         file >> temp.m_p_Price;
         file.ignore();
         file >> temp.m_p_CurrentQuan;
         file.ignore();
         file >> temp.m_p_NeedQuan;
         file.ignore();
         *this = temp;
      }
		return file;
	}
	std::ostream& Product::write(std::ostream& os, bool linear) const 
   {
		if (!(m_p_error.isClear()))
		{
			os << m_p_error.message();
		}
		else
		{
			if (!isEmpty()) 
         {
				if (linear)
            {
					os << setw(max_sku_length) << left << m_p_Sku << "|" 
                  << setw(20) << left << m_p_Name << "|" 
                  << setw(7) << right << setprecision(2) << fixed << cost() << "|" 
                  << setw(4) << right << m_p_CurrentQuan << "|" 
                  << setw(10) << left << m_p_Unit << "|" 
                  << setw(4) << right << m_p_NeedQuan << "|";
				} else {
               os << " Sku: " << m_p_Sku << endl
                  << " Name (no spaces): " << m_p_Name << endl
                  << " Price: " << m_p_Price << endl
                  << " Price after tax: ";
					if (m_p_Taxed) 
               {
						os <<  total_cost() << endl;
					} else {
						os <<  "N/A" << endl;
					}
					os << " Quantity on Hand: " << m_p_CurrentQuan << " " << m_p_Unit << endl;
					os << " Quantity needed: " << m_p_NeedQuan;
				}
			}
		}
		return os;
	}
	std::istream& Product::read(std::istream& is) 
   {
      char* n = new char[max_name_length + 1];
		char check;
		double number;
      m_p_error.clear();
		cout << " Sku: ";
		is >> m_p_Sku;
		cout << " Name (no spaces): ";
		is >> n;
      name(n);
      delete[] n;
		cout << " Unit: ";
		is >> m_p_Unit;
		cout << " Taxed? (y/n): ";
      is >> check;
		if (check == 'y' || check == 'Y') 
      {
			m_p_Taxed = true;
		} else if (check == 'n' || check == 'N') {
			m_p_Taxed = false;
		} else {
         m_p_error.message("Only (Y)es or (N)o are acceptable");
			is.istream::setstate(std::ios::failbit);
			return is;
		}
		cout << " Price: ";
		is >> number;
		if (number >= 0) 
      {
			m_p_Price = number;
		}
		if (is.fail()) 
      {
			m_p_error.message("Invalid Price Entry");
			is.istream::setstate(std::ios::failbit);
			return is;
		}
		cout << " Quantity on hand: ";
		is >> m_p_CurrentQuan;
		if (is.fail()) 
      {
			m_p_error.message("Invalid Quantity Entry");
			is.istream::setstate(std::ios::failbit);
			return is;
		}
		cout << " Quantity needed: ";
		is >> m_p_NeedQuan;
		if (is.fail()) 
      {
			m_p_error.message("Invalid Quantity Needed Entry");
			is.istream::setstate(std::ios::failbit);
			return is;
		}
      is.ignore();
		return is;
	}
	bool Product::operator==(const char* p_Sku) const 
   {
      bool compare = false;
		if (strcmp(p_Sku, this->m_p_Sku) == 0) 
      {
         compare = true;
		}
			return compare;
	}
	double Product::total_cost() const 
   {
		double total = m_p_Price * m_p_CurrentQuan;
		if (m_p_Taxed) 
      {
			total = total + (total * taxRate);
		}
		return total;
	}
	void Product::quantity(int unit) 
   {
		m_p_CurrentQuan = unit;
	}
	bool Product::isEmpty() const
   {
      bool empty = false;
		if (m_p_Sku[0] == '\0' && 
         m_p_Name == nullptr && 
         m_p_Unit[0] == '\0' && 
         m_p_CurrentQuan == 0 && 
         m_p_NeedQuan == 0 && 
         m_p_Price == 0 && 
         m_p_Taxed == true) 
      {
			empty = true;
		}
			return empty;
	}
	int Product::qtyNeeded() const 
   {
		return m_p_NeedQuan;
	}
	int Product::quantity() const 
   {
		return m_p_CurrentQuan;
	}
	bool Product::operator>(const char* sku) const 
   {
      bool compare = false;
		if (m_p_Sku > sku) 
      {
         compare = true;
		}
      return compare;
	}
	int Product::operator+=(int addUnit) 
   {
		if (addUnit > 0) 
      {
			m_p_CurrentQuan += addUnit;
		}
		return m_p_CurrentQuan;
	}
	bool Product::operator>(const iProduct& product) const
   {
      bool compare = false;
		if (m_p_Name > product.name())
      {
         compare = true;
		}
			return compare;
	}
	std::ostream& operator<<(std::ostream& os, const iProduct& product) 
   {
      product.write(os, true);
		return os;
	}
	std::istream& operator>>(std::istream& is, iProduct& product)
   {
      product.read(is);
		return is;
	}
	double operator+=(double& total, const iProduct& product)
   {
      total = (total + product.total_cost());
      return total;
	}
}

// Final Project - Milestone 3 - Product Module
// Version 3.3
// Date	2018-04-09
// Product.h
// Author	SangJunPark
/////////////////////////////////////////////////////////////////
#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H
#include "ErrorState.h"
namespace AMA
{
	const int max_sku_length = 7;
	const int max_unit_length = 10;
	const int max_name_length = 75;
	const double taxRate = 0.13;

	class Product
	{
		char m_p_Type;
		char m_p_Sku[max_sku_length];
		char m_p_Unit[max_unit_length];
		char m_p_Name[max_sku_length];
		int m_p_CurrentQuan;
		int m_p_NeedQuan;
		double m_p_Price;
		bool m_p_Taxed;
      ErrorState m_p_error;

	protected:
		void name(const char* p_name);
		const char* name() const;
		const char* sku() const;
		const char* unit() const;
		bool taxed() const;
		double price() const;
		double cost() const;
		void message(const char* p_message);
		bool isClear() const;

	public:
		Product(char type = 'N');
		Product(const char* p_Sku, const char* p_Name, const char* p_Unit, int p_CurrentQuan = 0, bool p_Taxed = true, double p_Price = 0, int m_p_NeedQuan = 0);
		Product(const Product& product);
      Product& operator=(const Product& product);
		~Product();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		bool operator==(const char* p_Sku) const;
		double total_cost() const;
		void quantity(int unit);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char* p_Sku) const;
		bool operator>(const Product& product) const;
		int operator+=(int addUnit);

	};
	std::ostream& operator<<(std::ostream& os, const Product& product);
	std::istream& operator>>(std::istream& is, Product& product);
	double operator+=(double& total, const Product& product);

}



#endif
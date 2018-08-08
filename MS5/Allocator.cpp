// Final Project Milestone 5
//
// Name:Sang Jun Park Date:2018.04.16
/////////////////////////////////////////////////////////////////
#include "Product.h"
#include "Perishable.h"

namespace AMA 
{
	// creates an empty product
	//
	iProduct* CreateProduct() 
   {
		return new Product();
	}
	// creates an empty perishable product
	//
	iProduct* CreatePerishable() 
   {
		return new Perishable();
	}
}
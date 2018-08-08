// Final Project - Milestone 4
// Version 3.3
// Allocator.cpp
// Date	2018/04/010
// Authors	Sang Jun Park
//
/////////////////////////////////////////////////////////////////
#include "MyProduct.h"

namespace AMA {

	iProduct* CreateProduct() {
		return new MyProduct("Product");
	}
	iProduct* CreatePerishable() {
		return new MyProduct("Perishable");
	}
}
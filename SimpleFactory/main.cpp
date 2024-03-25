#include <iostream>
#include "Factory.h"
#include "Product.h"

int main()
{
	Product *product = Factory::createProduct("ProductA");
	product->use();

	delete product;
	return 0;
}
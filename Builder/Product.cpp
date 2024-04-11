#include "Product.h"

Product::~Product()
{}

void Product::setA(std::string const &str)
{
	a = str;
}

void Product::setB(std::string const &str)
{
	b = str;
}

void Product::setC(std::string const &str)
{
	c = str;
}

void Product::show()
{
	std::cout << a << " + " << b << " + " << c << std::endl;
}
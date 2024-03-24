#include "Factory.h"
#include "ConcreteProductA.h"
#include "ConcreteProductB.h"

Factory::Factory()
{}

Factory::~Factory()
{}

Product *Factory::createProduct(std::string productName)
{
	if (productName == "ProductA")
		return new ConcreteProductA();
	else if (productName == "ProductB")
		return new ConcreteProductB();
	return nullptr;
}
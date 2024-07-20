#include "ConcreteFactoryB.h"

ConcreteFactoryB::~ConcreteFactoryB()
{}

Product *ConcreteFactoryB::createProduct()
{
	return new ConcreteProductB();
}
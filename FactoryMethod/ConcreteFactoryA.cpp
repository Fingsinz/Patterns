#include "ConcreteFactoryA.h"

ConcreteFactoryA::~ConcreteFactoryA()
{}

Product *ConcreteFactoryA::createProduct()
{
	return new ConcreteProductA();
}
#include "ConcreteBuilder.h"

ConcreteBuilder::~ConcreteBuilder()
{}

void ConcreteBuilder::buildPartA()
{
	product.setA("A Style");
}

void ConcreteBuilder::buildPartB()
{
	product.setB("B Style");
}

void ConcreteBuilder::buildPartC()
{
	product.setC("C Style");
}
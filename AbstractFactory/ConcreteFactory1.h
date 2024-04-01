#pragma once

#include "AbstractFactory.h"
#include "AbstractProductA.h"
#include "AbstractProductB.h"

class ConcreteFactory1 : public AbstractFactory
{
public:
	ConcreteFactory1() = default;
	virtual ~ConcreteFactory1() = default;

	virtual AbstractProductA *createProductA();
	virtual AbstractProductB *createProductB();
};

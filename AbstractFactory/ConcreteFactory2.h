#pragma once

#include "AbstractFactory.h"
#include "AbstractProductA.h"
#include "AbstractProductB.h"

class ConcreteFactory2 : public AbstractFactory
{
public:
	ConcreteFactory2() = default;
	virtual ~ConcreteFactory2() = default;

	virtual AbstractProductA *createProductA();
	virtual AbstractProductB *createProductB();
};

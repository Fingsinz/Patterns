#pragma once

#include "AbstractProductA.h"
#include "AbstractProductB.h"

class AbstractFactory
{
public:
	AbstractFactory() = default;
	virtual ~AbstractFactory() = default;

	virtual AbstractProductA *createProductA() = 0;
	virtual AbstractProductB *createProductB() = 0;
};

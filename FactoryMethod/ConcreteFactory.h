/*
* @Author: Fingsinz
* @Description: 具体工厂类的实现
*/

#pragma once

#include "Factory.h"
#include "Product.h"
#include "ConcreteProductA.h"
#include "ConcreteProductB.h"

class ConcreteFactory : public Factory
{
public:
	ConcreteFactory() = default;
	virtual ~ConcreteFactory();

	virtual Product *createProductA();
	virtual Product *createProductB();
};

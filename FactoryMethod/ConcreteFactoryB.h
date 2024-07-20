/*
* @Author: Fingsinz
* @Description: 具体工厂B类的实现
*/

#pragma once

#include "Factory.h"
#include "Product.h"
#include "ConcreteProductB.h"

class ConcreteFactoryB : public Factory
{
public:
	ConcreteFactoryB() = default;
	virtual ~ConcreteFactoryB();

	virtual Product *createProduct();
};

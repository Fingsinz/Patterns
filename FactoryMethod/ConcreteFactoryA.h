/*
* @Author: Fingsinz
* @Description: 具体工厂A类的实现
*/

#pragma once

#include "Factory.h"
#include "Product.h"
#include "ConcreteProductA.h"

class ConcreteFactoryA : public Factory
{
public:
	ConcreteFactoryA() = default;
	virtual ~ConcreteFactoryA();

	virtual Product *createProduct();
};

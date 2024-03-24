/*
* @Author: Fingsinz
* @Description: 具体产品B类的实现
*/

#pragma once

#include "Product.h"

class ConcreteProductB : public Product
{
public:
	ConcreteProductB();
	virtual ~ConcreteProductB();

	virtual void use();
};

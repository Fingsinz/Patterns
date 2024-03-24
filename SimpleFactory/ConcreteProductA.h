/*
* @Author: Fingsinz
* @Description: 具体产品A类的实现
*/

#pragma once

#include "Product.h"

class ConcreteProductA : public Product
{
public:
	ConcreteProductA();
	virtual ~ConcreteProductA();

	virtual void use();
};

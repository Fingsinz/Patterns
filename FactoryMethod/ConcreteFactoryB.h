/*
* @Author: Fingsinz
* @Description: ���幤��B���ʵ��
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

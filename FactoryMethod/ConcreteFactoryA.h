/*
* @Author: Fingsinz
* @Description: ���幤��A���ʵ��
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

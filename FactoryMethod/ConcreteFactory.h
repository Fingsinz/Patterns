/*
* @Author: Fingsinz
* @Description: ���幤�����ʵ��
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

/*
* @Author: Fingsinz
* @Description: 抽象工厂类的实现
*/

#pragma once

#include "Product.h"

class Factory
{
public:

	Factory() = default;
	virtual ~Factory();

	virtual Product *createProduct() = 0;
};

/*
* @Author: Fingsinz
* @Description: 工厂类的实现
*/

#pragma once

#include "Product.h"
#include <string>

class Factory
{
	Factory();
	virtual ~Factory();

public:
	static Product *createProduct(std::string productName);
};

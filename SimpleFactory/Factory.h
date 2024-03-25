/*
* @Author: Fingsinz
* @Description: �������ʵ��
*/

#pragma once

#include "Product.h"
#include <string>

class Factory
{
public:
	Factory();
	virtual ~Factory();

	static Product *createProduct(std::string productName);
};

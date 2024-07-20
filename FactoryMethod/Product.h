/*
* @Author: Fingsinz
* @Description: 抽象产品类的实现
*/

#pragma once

class Product
{
public:
	Product() = default;
	virtual ~Product();

	virtual void use() = 0;
};

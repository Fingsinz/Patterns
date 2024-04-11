#pragma once

#include "Product.h"

class Builder
{
protected:
	Product product;

public:
	Builder() = default;
	virtual ~Builder();

	virtual void buildPartA() = 0;
	virtual void buildPartB() = 0;
	virtual void buildPartC() = 0;
	virtual Product getResult();
};

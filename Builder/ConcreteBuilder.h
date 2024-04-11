#pragma once

#include "Builder.h"

class ConcreteBuilder : public Builder
{
public:
	ConcreteBuilder() = default;
	virtual ~ConcreteBuilder();

	void buildPartA();
	void buildPartB();
	void buildPartC();
};

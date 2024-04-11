#pragma once

#include "Builder.h"

class Director
{
private:
	Builder *builder = nullptr;

public:
	Director(Builder *b = nullptr);
	virtual ~Director();

	Product construct();
	void setBuilder(Builder *b);
};

#include "Director.h"

Director::Director(Builder *b) : builder(b)
{}

Director::~Director()
{}

Product Director::construct()
{
	builder->buildPartA();
	builder->buildPartB();
	builder->buildPartC();

	return builder->getResult();
}

void Director::setBuilder(Builder *b)
{
	if (builder)
	{
		delete builder;
	}
	builder = b;
}
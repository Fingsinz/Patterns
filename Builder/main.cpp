#include <iostream>
#include "ConcreteBuilder.h"
#include "Director.h"
#include "Builder.h"
#include "Product.h"

int main()
{
	ConcreteBuilder *builder = new ConcreteBuilder();
	Director *director = new Director();
	director->setBuilder(builder);

	Product pd = director->construct();
	pd.show();

	delete builder;
	delete director;
	return 0;
}
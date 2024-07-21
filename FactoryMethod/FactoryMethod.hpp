#pragma once
#include <iostream>

class Product {
public:
	Product() = default;
	virtual ~Product() {};

	virtual void use() = 0;
};

class ConcreteProductA : public Product {
public:
	virtual ~ConcreteProductA() {}

	virtual void use() {
		std::cout << "use ConcreteProductA\n";
	}
};

class ConcreteProductB : public Product {
public:
	virtual ~ConcreteProductB() {};

	virtual void use() {
		std::cout << "use ConcreteProductB\n";
	}
};

class Factory {
public:
	Factory() = default;
	virtual ~Factory() {};

	virtual Product *createProduct() = 0;
};

class ConcreteFactoryA : public Factory {
public:
	ConcreteFactoryA() = default;
	virtual ~ConcreteFactoryA() {}

	virtual Product *createProduct() {
		return new ConcreteProductA();
	}
};

class ConcreteFactoryB : public Factory {
public:
	ConcreteFactoryB() = default;
	virtual ~ConcreteFactoryB() {};

	virtual Product *createProduct() {
		return new ConcreteProductB();
	}
};
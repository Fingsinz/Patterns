#pragma once

#include <iostream>

class AbstractProductA {
public:
	AbstractProductA() = default;
	virtual ~AbstractProductA() = default;

	virtual void use() = 0;
};

class AbstractProductB {
public:
	AbstractProductB() = default;
	~AbstractProductB() = default;

	virtual void eat() = 0;
};

class ProductA1 : public ::AbstractProductA {
public:
	ProductA1() = default;
	virtual ~ProductA1() = default;

	void use() override {
		std::cout << "use ProductA1\n";
	}
};

class ProductA2 : public AbstractProductA {
public:
	ProductA2() = default;
	virtual ~ProductA2() = default;

	void use() override {
		std::cout << "use ProductA2\n";
	}
};

class ProductB1 : public AbstractProductB {
public:
	ProductB1() = default;
	virtual ~ProductB1() = default;

	void eat() override {
		std::cout << "eat ProductB1\n";
	}
};

class ProductB2 : public AbstractProductB {
public:
	ProductB2() = default;
	virtual ~ProductB2() = default;

	void eat() override {
		std::cout << "eat ProductB2\n";
	}
};

class AbstractFactory {
public:
	AbstractFactory() = default;
	virtual ~AbstractFactory() = default;

	virtual AbstractProductA *createProductA() = 0;
	virtual AbstractProductB *createProductB() = 0;
};

class ConcreteFactory1 : public AbstractFactory {
public:
	ConcreteFactory1() = default;
	virtual ~ConcreteFactory1() = default;

	AbstractProductA *createProductA() override {
		return new ProductA1();
	}
	AbstractProductB *createProductB() override {
		return new ProductB1();
	}
};

class ConcreteFactory2 : public AbstractFactory {
public:
	ConcreteFactory2() = default;
	virtual ~ConcreteFactory2() = default;

	AbstractProductA *createProductA() override {
		return new ProductA2();
	}

	AbstractProductB *createProductB() override {
		return new ProductB2();
	}
};
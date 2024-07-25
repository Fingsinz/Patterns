#pragma once

#include <iostream>

// 实现
class Implementation {
public:
	virtual void operationImpl() {};
};

// 具体实现A
class ConcreteImplementationA : public Implementation {
public:
	void operationImpl() override {};
};

// 具体实现B
class ConcreteImplementationB : public Implementation {
public:
	void operationImpl() override {};
};

// 抽象
class Abstraction {
public:
	Abstraction(Implementation *impl) : impl(impl) {}
	virtual void operation() = 0;
protected:
	Implementation *impl;
};

// 修正抽象
class RefinedAbstraction : public Abstraction {
public:
	RefinedAbstraction(Implementation *impl) : Abstraction(impl) {}
	void operation() override {
		impl->operationImpl();
	}
};
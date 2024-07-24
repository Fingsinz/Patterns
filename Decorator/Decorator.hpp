#pragma once

#include <iostream>

class Component {
public:
	virtual ~Component() = default;
	virtual void operation() = 0;
};

class ConcreteComponent : public Component {
public:
	void operation() override {
		std::cout << "ConcreteComponent operation" << std::endl;
	}
};

class Decorator : public Component {
public:
	Decorator(Component *component) : m_component(component) {}
	void operation() override {
		m_component->operation();
	}

protected:
	Component *m_component;
};

class ConcreteDecorator : public Decorator {
public:
	ConcreteDecorator(Component *component) : Decorator(component) {}

	void operation() override {
		Decorator::operation();
		std::cout << "ConcreteDecorator operation" << std::endl;
	}
};
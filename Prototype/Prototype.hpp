#pragma once

#include <iostream>

class Prototype {
public:
	virtual ~Prototype() = default;

	virtual Prototype *clone() = 0;
};

class ConcretePrototype : public Prototype {
public:
	ConcretePrototype(std::string const &data) : m_data(data) {}
	virtual ~ConcretePrototype() = default;

	Prototype *clone() override {
		return new ConcretePrototype(this->m_data);
	}

	std::string getData() const {
		return m_data;
	}

private:
	std::string m_data;
};
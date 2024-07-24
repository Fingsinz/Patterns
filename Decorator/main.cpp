#include <iostream>
#include <memory>

class Component {
public:
	virtual ~Component() = default;
	virtual void brew() = 0;
};

class BlackCoffee : public Component {
public:
	void brew() override {
		std::cout << "Brewing Black Coffee" << std::endl;
	}
};

class Latte : public Component {
public:
	void brew() override {
		std::cout << "Brewing Latte" << std::endl;
	}
};

class Decorator {
public:
	Decorator(Component *component) : m_component(std::move(component)) {}
	virtual ~Decorator() = default;
	virtual void add() {
		m_component->brew();
	}

protected:
	std::unique_ptr<Component> m_component;
};

class Milk : public Decorator {
public:
	Milk(Component *component) : Decorator(component) {}

	void add() override {
		Decorator::add();
		std::cout << "Adding Milk" << std::endl;
	}
};

class Sugar : public Decorator {
public:
	Sugar(Component *component) : Decorator(component) {}

	void add() override {
		Decorator::add();
		std::cout << "Adding Sugar" << std::endl;
	}
};

int main() {
	int coffeeType, addType;
	while (std::cin >> coffeeType >> addType) {
		Component *coffee = nullptr;
		if (coffeeType == 1) {
			coffee = new BlackCoffee;
		} else if (coffeeType == 2) {
			coffee = new Latte;
		}

		std::unique_ptr<Decorator> addon;
		if (addType == 1) {
			addon.reset(new Milk(coffee));
		} else if (addType == 2) {
			addon.reset(new Sugar(coffee));
		}

		addon->add();
	}
	return 0;
}
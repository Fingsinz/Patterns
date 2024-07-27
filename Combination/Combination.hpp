#pragma once

#include <iostream>
#include <vector>
#include <memory>

// 组件
class Component {
public:
	virtual ~Component() = default;
	virtual void operation() = 0;
};

// 叶子节点
class Leaf : public Component {
public:
	void operation() override {
		std::cout << "Leaf operation" << std::endl;
	}
};

// 组合节点：包含叶子节点的操作行为
class Composite : public Component {
public:
	void add(Component *component) {
		m_component.push_back(std::make_unique<Component>(component));
	}

	void remove(Component *component) {
		// ...
	}

	void operation() override {
		std::cout << "Composite operation" << std::endl;

		for (auto &component : m_component) {
			component->operation();
		}
	}
private:
	std::vector<std::unique_ptr<Component>> m_component;
};
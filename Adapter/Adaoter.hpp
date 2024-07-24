#pragma once

#include <iostream>

// 目标接口
class Target {
public:
	virtual void request() = 0;
};

// 被适配者
class Adaptee {
public:
	void specificRequest() {
		std::cout << "specificRequest" << std::endl;
	}
};

// 适配器类
class Adapter : public Target {
public:
	Adapter(Adaptee *adaptee) {
		m_adaptee = adaptee;
	}
	void request() override {
		m_adaptee->specificRequest();
	}
private:
	Adaptee *m_adaptee;
};
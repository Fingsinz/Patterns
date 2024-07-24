#pragma once

#include <iostream>

// 抽象对象类
class Subject {
public:
	virtual void request() = 0;
};

// 具体对象类
class RealSubject : public Subject {
public:
	void request() override {
		std::cout << "RealSubject: Handling request.\n";
	}
};

// 代理类
class Proxy : public Subject {
public:
	void request() override {
		realSubject.request();
	}

private:
	RealSubject realSubject;
};
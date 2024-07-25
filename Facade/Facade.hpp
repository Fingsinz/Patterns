#pragma once

#include <iostream>

class SubSystemA {
public:
	void operationA() {
		std::cout << "operationA" << std::endl;
	}
};

class SubSystemB {
public:
	void operationB() {
		std::cout << "operationB" << std::endl;
	}
};

class SubSystemC {
public:
	void operationC() {
		std::cout << "operationC" << std::endl;
	}
};

class Facade {
public:
	void operation() {
		subSystemA.operationA();
		subSystemB.operationB();
		subSystemC.operationC();
	}

private:
	SubSystemA subSystemA;
	SubSystemB subSystemB;
	SubSystemC subSystemC;
};
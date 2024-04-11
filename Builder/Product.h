#pragma once

#include <iostream>

class Product
{
private:
	std::string a;
	std::string b;
	std::string c;

public:
	Product() = default;
	virtual ~Product();

	void setA(std::string const &str);
	void setB(std::string const &str);
	void setC(std::string const &str);

	void show();
};

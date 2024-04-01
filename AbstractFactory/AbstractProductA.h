#pragma once
class AbstractProductA
{
public:
	AbstractProductA() = default;
	virtual ~AbstractProductA() = default;

	virtual void use() = 0;
};

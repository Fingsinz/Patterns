/*
* @Author: Fingsinz
* @Description: �����Ʒ���ʵ��
*/

#pragma once

class Product
{
public:
	Product() = default;
	virtual ~Product();

	virtual void use() = 0;
};

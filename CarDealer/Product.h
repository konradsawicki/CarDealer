#pragma once
class Product
{
public:
	Product(float Price);

	virtual float GetPrice() const;
	virtual void SetPrice(float Price);

	virtual ~Product() {};

protected:
	float m_Price;
};


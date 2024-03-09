#pragma once
#include <string>
class Shape
{
public:
	Shape(float x, float y);

	virtual ~Shape() = default;

	float area();

	std::string toString();

protected:
	float m_x, m_y;
};


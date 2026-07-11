#pragma once
#include <iostream>
#include <string>

class Circle {
public:

	Circle();
	Circle(double x, double y, double radius);
	Circle(const Circle& other);
	~Circle();

	double getX()const { return x; };
	double getY()const { return y; };
	double getRadius()const { return radius; };
	std::string getColor()const { return color; };

	void setX(double x);
	void setY(double y);
	void setRadius(double radius);
	void setColor(const std::string& color);

	friend Circle operator%(const Circle& c1, const Circle& c2);

	friend std::ostream& operator<<(std::ostream& os, const Circle& c);
	friend std::istream& operator>>(std::istream& is, Circle& c);

private:

	double x;
	double y;
	double radius;
	std::string color;
	void generateRandomColor();

};
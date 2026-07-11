#include "Circle.h"
#include <iomanip>
#include <cstdlib>

void Circle::generateRandomColor() {
	std::string colors[] = { "Red", "Green", "Blue", "Yellow", "White", "Black" };
	int randomIndex = rand() % 6;
	this->color = colors[randomIndex];
}

Circle::Circle() {
	x = 0.0;
	y = 0.0;
	radius = 1.0;
	generateRandomColor();
}

Circle::Circle(double x, double y, double radius) {
	this->x = x;
	this->y = y;
	if (radius <= 0) {
		this->radius = 1.0;
	}
	else {
		this->radius = radius;
	}
	generateRandomColor();
}

Circle::Circle(const Circle& other) {
	this->x = other.x;
	this->y = other.y;
	this->radius = other.radius;
	this->color = other.color;
}

Circle::~Circle() {
	std::cout << "Circle object (Color: " << this->color << ", R: " << this->radius << ") destroyed." << std::endl;
}

void Circle::setX(double x) {
	this->x = x;
}

void Circle::setY(double y) {
	this->y = y;
}

void Circle::setRadius(double radius) {
	if (radius <= 0) {
		std::cout << "Error: Radius must be positive." << std::endl;
		return;
	}
	else {
		this->radius = radius;
	}
	generateRandomColor();
}

void Circle::setColor(const std::string& color) {
	if (color == "") {
		std::cout << "Error: Color cannot be empty." << std::endl;
		return;
	}
	else {
		this->color = color;
	}
}

Circle operator%(const Circle& c1, const Circle& c2) {
	Circle result;
	result.x = c1.x;
	result.y = c1.y;
	result.radius = c1.radius + c2.radius;
	if (c1.radius >= c2.radius) {
		result.color = c1.color;
	}
	else {
		result.color = c2.color;
	}
	return result;
}

std::ostream& operator<<(std::ostream& os, const Circle& c) {
	os << "Center: (" << c.x << ", " << c.y << ") | "
		<< "Radius: " << c.radius << " | "
		<< "Color: " << c.color << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Circle& c) {
	std::cout << "Enter X coordinate of the center: ";
	while (!(is >> c.x)) {
		std::cout << "Error: Must be a number. Enter X coordinate: ";
		is.clear();
		is.ignore(10000, '\n');
	}

	std::cout << "Enter Y coordinate of the center: ";
	while (!(is >> c.y)) {
		std::cout << "Error: Must be a number. Enter Y coordinate: ";
		is.clear();
		is.ignore(10000, '\n');
	}

	std::cout << "Enter radius: ";
	double r;
	while (!(is >> r) || r <= 0) {
		std::cout << "Error: Radius must be positive number. Try again: ";
		is.clear();
		is.ignore(10000, '\n');
	}
	c.radius = r;

	c.generateRandomColor();
	return is;
}
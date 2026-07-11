#include "Music.h"
#include <iomanip>

Music::Music() {
	date = "01.01.2000";
	title = "Unknown";
	copies = 0;
	onDVD = false;
}

Music::Music(std::string date, std::string title, long long copies, bool onDVD) {
	this->date = date;
	this->title = title;
	this->copies = copies;
	this->onDVD = onDVD;
}

Music::Music(const Music& other) {
	this->date = other.date;
	this->title = other.title;
	this->copies = other.copies;
	this->onDVD = other.onDVD;
}

Music::~Music() {
	std::cout << "Object " << this->title << " destroyed." << std::endl;
}

void Music::SetDate(std::string date) {
	if (date == "") {
		std::cout << "Error: Date cannot be empty." << std::endl;
		return;
	}
	this->date = date;
}

void Music::SetTitle(std::string title) {
	if (title == "") {
		std::cout << "Error: Title cannot be empty." << std::endl;
		return;
	}
	this->title = title;
}

void Music::SetCopies(long long copies) {
	if (copies < 0) {
		std::cout << "Error: Copies cannot be negative." << std::endl;
		return;
	}
	this->copies = copies;
}

void Music::SetOnDVD(bool onDVD) {
	this->onDVD = onDVD;
}

std::ostream& operator<<(std::ostream& os, const Music& m) {
	os << std::setw(12) << m.date << " | "
		<< std::setw(12) << m.title << " | "
		<< std::setw(12) << m.copies << " | ";

	if (m.onDVD) {
		os << "Yes" << std::endl;
	}
	else {
		os << "No" << std::endl;
	}
	return os;
}

std::istream& operator>>(std::istream& is, Music& m) {
	std::cout << "Enter the title (one word, no spaces): ";
	is >> m.title;

	std::cout << "Enter the sale date: ";
	is >> m.date;

	std::cout << "Enter the number of copies sold: ";
	is >> m.copies;

	std::cout << "Is it available on DVD? (1 for Yes, 0 for No): ";
	is >> m.onDVD;

	return is;
}
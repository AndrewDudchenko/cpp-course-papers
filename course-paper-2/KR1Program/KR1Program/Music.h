#pragma once
#include <iostream>
#include <string>

class Music {
public:

	Music();
	Music(std::string date, std::string title, long long copies, bool onDVD);
	Music(const Music& other);
	~Music();

	std::string GetDate()const { return date; };
	std::string GetTitle()const { return title; };
	long long GetCopies()const { return copies; };
	bool GetOnDVD()const { return onDVD; };

	void SetDate(std::string date);
	void SetTitle(std::string title);
	void SetCopies(long long copies);
	void SetOnDVD(bool onDVD);

	friend std::ostream& operator<<(std::ostream& os, const Music& m);
	friend std::istream& operator>>(std::istream& is, Music& m);

private:

	std::string date;
	std::string title;
	long long copies;
	bool onDVD;

};
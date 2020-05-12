#include <iostream>
#pragma once
class ProperFraction
{
public:
	ProperFraction();
	ProperFraction(int integer, int numerator, int denominator);
	ProperFraction(const ProperFraction& obj);
	~ProperFraction();
	ProperFraction operator+(ProperFraction &obj2);
	ProperFraction operator-(ProperFraction &obj2);
	ProperFraction operator*(ProperFraction &obj2);
	ProperFraction operator/(ProperFraction &obj2);
	friend std::ostream &operator<< (std::ostream &out, const ProperFraction &obj);
	int get_numerator();
	int get_denominator();
	int get_integer();
	bool get_sign();
private:
	int numerator = 0, denominator = 1;
	bool sign = false;
	void reduction();
	static ProperFraction summ(const ProperFraction &obj1, const ProperFraction &obj2);
	static ProperFraction sub(const ProperFraction &obj1, const ProperFraction &obj2);
	static ProperFraction mult(const ProperFraction &obj1, const ProperFraction &obj2);
	static ProperFraction div(const ProperFraction &obj1, const ProperFraction &obj2);
};


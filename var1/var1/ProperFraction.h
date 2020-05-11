#pragma once
class ProperFraction
{
public:
	ProperFraction();
	ProperFraction(int integer, int numerator, int denominator);
	ProperFraction(ProperFraction& obj);
	~ProperFraction();
	//operator...

private:
	int numerator = 0, denominator = 0;
	bool sign = false;
	void reduction();
	static ProperFraction summ(const ProperFraction obj1, const ProperFraction obj2);
	static ProperFraction sub(const ProperFraction obj1, const ProperFraction obj2);
	static ProperFraction mult(const ProperFraction obj1, const ProperFraction obj2);
	static ProperFraction div(const ProperFraction obj1, const ProperFraction obj2);
};

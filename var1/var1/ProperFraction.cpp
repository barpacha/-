#include "ProperFraction.h"
#include <iostream>


ProperFraction::ProperFraction()
{
	std::cout << "new ProperFraction: " << this << std::endl;
}

ProperFraction::ProperFraction(int integer, int numerator, int denominator)
{
	if (!denominator) denominator = 1;
	this->numerator = integer * denominator + numerator;
	this->denominator = denominator;
	this->reduction();
	std::cout << "new ProperFraction: " << this << std::endl;
}

ProperFraction::ProperFraction(ProperFraction & obj)
	: numerator(obj.numerator), denominator(obj.denominator),  sign(obj.sign)
{
	std::cout << "new ProperFraction: " << this << std::endl;
}


ProperFraction::~ProperFraction()
{
	std::cout << "delete ProperFraction: " << this << std::endl;
}

void ProperFraction::reduction()
{
	if (numerator < 0)
	{
		numerator *= -1;
		sign ^= true;
	}
	if (denominator < 0)
	{
		denominator *= -1;
		sign ^= true;
	}
	for (int i = 2; i <= (numerator<denominator) ? numerator : denominator; i++)
		if (!(numerator%i) && !(denominator%i))
		{
			numerator /= i;
			denominator /= i;
			return;
		}
}

ProperFraction ProperFraction::summ(const ProperFraction obj1, const ProperFraction obj2)
{
	ProperFraction rez(0, obj1.numerator * obj2.denominator * (obj1.sign) ? -1 : 1 + obj2.numerator * obj1.denominator *  (obj2.sign) ? -1 : 1, obj1.denominator * obj2.denominator);
	rez.reduction();
	return rez;
}

ProperFraction ProperFraction::sub(const ProperFraction obj1, const ProperFraction obj2)
{
	ProperFraction rez(0, obj1.numerator * obj2.denominator * (obj1.sign) ? -1 : 1 - obj2.numerator * obj1.denominator *  (obj2.sign) ? -1 : 1, obj1.denominator * obj2.denominator);
	rez.reduction();
	return rez;
}

ProperFraction ProperFraction::mult(const ProperFraction obj1, const ProperFraction obj2)
{
	ProperFraction rez(0, obj1.numerator * obj2.numerator * (obj1.sign&&obj2.sign) ? -1 : 1, obj1.denominator * obj2.denominator);
	rez.reduction();
	return rez;
}

ProperFraction ProperFraction::div(const ProperFraction obj1, const ProperFraction obj2)
{
	ProperFraction rez(0, obj1.numerator * obj2.denominator * (obj1.sign&&obj2.sign) ? -1 : 1, obj1.denominator * obj2.numerator);
	rez.reduction();
	return rez;
}

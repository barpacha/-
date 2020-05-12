#include "ProperFraction.h"



ProperFraction::ProperFraction()
{
	std::cout << "new ProperFraction: " << this << std::endl;
}

ProperFraction::ProperFraction(int integer, int numerator, int denominator)
{
	if (!denominator) denominator = 1;
	if (integer < 0) sign ^= true;
	if (numerator < 0) sign ^= true;
	this->numerator = abs(integer) * abs(denominator) + abs(numerator);
	this->denominator = denominator;
	this->reduction();
	std::cout << "new ProperFraction: " << this << std::endl;
}

ProperFraction::ProperFraction(const ProperFraction & obj)
	: numerator(obj.numerator), denominator(obj.denominator),  sign(obj.sign)
{
	std::cout << "new ProperFraction: " << this << std::endl;
}


ProperFraction::~ProperFraction()
{
	std::cout << "delete ProperFraction: " << this << std::endl;
}

ProperFraction ProperFraction::operator+(ProperFraction &obj2)
{
	return summ(*this, obj2);
}

ProperFraction ProperFraction::operator-(ProperFraction &obj2)
{
	return sub(*this, obj2);
}

ProperFraction ProperFraction::operator*(ProperFraction &obj2)
{
	return mult(*this, obj2);
}

ProperFraction ProperFraction::operator/(ProperFraction &obj2)
{
	return div(*this, obj2);
}

int ProperFraction::get_numerator()
{
	return numerator % denominator;
}

int ProperFraction::get_denominator()
{
	return denominator;
}

int ProperFraction::get_integer()
{
	return numerator / denominator;
}

bool ProperFraction::get_sign()
{
	return sign;
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
	if (numerator == 0) denominator = 1;
	int c = (numerator < denominator) ? numerator : denominator;
	for (int i = 2; i <= c; i++)
		if (!(numerator%i) && !(denominator%i))
		{
			numerator /= i;
			denominator /= i;
			return;
		}
}

ProperFraction ProperFraction::summ(const ProperFraction &obj1, const ProperFraction &obj2)
{
	int sign1 = (obj1.sign) ? -1 : 1, sign2 = (obj2.sign) ? -1 : 1;
	ProperFraction rez(0, obj1.numerator * obj2.denominator * sign1 + obj2.numerator * obj1.denominator *  sign2, obj1.denominator * obj2.denominator);
	rez.reduction();
	return rez;
}

ProperFraction ProperFraction::sub(const ProperFraction &obj1, const ProperFraction &obj2)
{
	int sign1 = (obj1.sign) ? -1 : 1, sign2 = (obj2.sign) ? -1 : 1;
	ProperFraction rez(0, obj1.numerator * obj2.denominator * sign1 - obj2.numerator * obj1.denominator *  sign2, obj1.denominator * obj2.denominator);
	rez.reduction();
	return rez;
}

ProperFraction ProperFraction::mult(const ProperFraction &obj1, const ProperFraction &obj2)
{
	int sign1 = (obj1.sign) ? -1 : 1, sign2 = (obj2.sign) ? -1 : 1;
	ProperFraction rez(0, obj1.numerator * obj2.numerator * sign1 * sign2, obj1.denominator * obj2.denominator);
	rez.reduction();
	return rez;
}

ProperFraction ProperFraction::div(const ProperFraction &obj1, const ProperFraction &obj2)
{
	int sign1 = (obj1.sign) ? -1 : 1, sign2 = (obj2.sign) ? -1 : 1;
	ProperFraction rez(0, obj1.numerator * obj2.denominator * sign1 * sign2, obj1.denominator * obj2.numerator);
	rez.reduction();
	return rez;
}

std::ostream &operator<<(std::ostream & out, const ProperFraction &obj)
{
	if (obj.sign) out << "-";
	if (obj.numerator >= obj.denominator) out << obj.numerator / obj.denominator;
	if (obj.numerator >= obj.denominator&&obj.denominator != 1) out << " ";
	if (obj.denominator != 1) out << obj.numerator % obj.denominator << "/" << obj.denominator;
	return out;
}

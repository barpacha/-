#include "ProperFraction.h"
#include <iostream>

void main()
{
	{
		ProperFraction a(1,2,3);
		ProperFraction b(-1, 2, 3), c = a/b;
		c = c + b;
		std::cout<< c << std::endl;
	}
	system("pause");
}
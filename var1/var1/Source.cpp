#include "ProperFraction.h"
#include <iostream>
#include "BST_pf.h"
#include <fstream>

ProperFraction cin_obj()
{
	char string_numbers[100];
	int i = 0;
	std::cin.get();
	while (string_numbers[i - 1] != 10 && i < 100)
		std::cin.get(string_numbers[i++]);
	int sign = 1;
	int index = 0;
	int integer = 0, numerator = 0, denomerator = 0;
	if (string_numbers[index] == '-')
	{
		sign *= -1;
		if (index < 100) index++;
		else return ProperFraction();
	}
	for (int iter = 0; string_numbers[index] > 47 && string_numbers[index] < 58; iter++)
	{
		integer = 10 * integer + string_numbers[index] - 48;
		if (index < 100) index++;
		else return ProperFraction();
	}
	if (string_numbers[index] != ' ')
		if (string_numbers[index] == '\n') goto end;
		else 
			if (string_numbers[index] == '/')
			{
				numerator = integer;
				integer = 0;
				if (index < 100) index++;
				else return ProperFraction();
				goto noint;
			}
			else return ProperFraction();
	else
		if (index < 100) index++;
		else return ProperFraction();
	if (string_numbers[index] == '-')
	{
		sign *= -1;
		if (index < 100) index++;
		else return ProperFraction();
	}
	for (int iter = 0; string_numbers[index] > 47 && string_numbers[index] < 58; iter++)
	{
		numerator = 10 * numerator + string_numbers[index] - 48;
		if (index < 100) index++;
		else return ProperFraction();
	}
	if (string_numbers[index] != '/') return ProperFraction();
	else
		if (index < 100) index++;
		else return ProperFraction();
	noint:
	if (string_numbers[index] == '-')
	{
		sign *= -1;
		if (index < 100) index++;
		else return ProperFraction();
	}
	for (int iter = 0; string_numbers[index] > 47 && string_numbers[index] < 58; iter++)
	{
		denomerator = 10 * denomerator + string_numbers[index] - 48;
		if (index < 100) index++;
		else return ProperFraction();
	}
	end:
	ProperFraction new_obj(integer, numerator, denomerator*sign);
	return new_obj;

}

void main()
{
	ProperFraction *pobj = nullptr;
	while (true)
	{
		std::cout << "select command:\n1: add\n2: remove\n3: save file\n4: load file\n5: +\n6: -\n7: *\n8: /" << std::endl << std::endl;
		int cmd;
		std::cin >> cmd;
		switch (cmd)
		{
		case 1:
			pobj = new ProperFraction;
			break;
		case 2:
			delete pobj;
			break;
		case 3:
		{
			std::ofstream out("ProperFraction.bin",std::ios::binary|std::ios::out);
			std::cout << "enter number:" << std::endl;
			ProperFraction obj = cin_obj();
			struct
			{
				int n, d;
				bool s;
			}str;
			str.n = obj.get_numerator() + obj.get_integer() * obj.get_denominator();
			str.d = obj.get_denominator();
			str.s = obj.get_sign();
			out.write((char*)&str, sizeof(str));
			out.close();
		}
			break;
		case 4:
		{
			std::ifstream out("ProperFraction.bin", std::ios::binary || std::ios::in);
			struct
			{
				int n, d;
				bool s;
			}str;
			out.read((char*)&str, sizeof(str));
			if (str.s)str.d *= -1;
			ProperFraction obj(0, str.n, str.d);
			std::cout << obj;
			out.close();
		}
			break;
		case 5:
		{
			std::cout << "enter 2 numbers" << std::endl << "example 1:" << std::endl << "-1 3/5" << std::endl << "7" << std::endl << "example 2:" << std::endl << "1 6/5" << std::endl << "-7/2" << std::endl;
			ProperFraction obj1 = cin_obj(), obj2 = cin_obj();
			ProperFraction obj3 = obj1 + obj2;
			std::cout << obj3;
			break;
		}
		case 6:
		{
			std::cout << "enter 2 numbers" << std::endl << "example 1:" << std::endl << "-1 3/5" << std::endl << "7" << std::endl << "example 2:" << std::endl << "1 6/5" << std::endl << "-7/2" << std::endl;
			ProperFraction obj1 = cin_obj(), obj2 = cin_obj();
			ProperFraction obj3 = obj1 - obj2;
			std::cout << obj3;
			break;
		}
		case 7:
		{
			std::cout << "enter 2 numbers" << std::endl << "example 1:" << std::endl << "-1 3/5" << std::endl << "7" << std::endl << "example 2:" << std::endl << "1 6/5" << std::endl << "-7/2" << std::endl;
			ProperFraction obj1 = cin_obj(), obj2 = cin_obj();
			ProperFraction obj3 = obj1 * obj2;
			std::cout << obj3;
			break;
		}
		case 8:
		{
			std::cout << "enter 2 numbers" << std::endl << "example 1:" << std::endl << "-1 3/5" << std::endl << "7" << std::endl << "example 2:" << std::endl << "1 6/5" << std::endl << "-7/2" << std::endl;
			ProperFraction obj1 = cin_obj(), obj2 = cin_obj();
			ProperFraction obj3 = obj1 / obj2;
			std::cout << obj3;
			break;
		}
		default:
			return;
		}
		system("pause");
		system("cls");
	}
	
}
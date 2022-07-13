#include "ValidateString.h"
#include<iostream>


int Validate(char s[])
{	
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (!(s[i]>=65 && s[i] <= 90)
			&& !(s[i] >= 97 && s[i] <= 122)
			&& !(s[i] >= 48 && s[i] <= 57))
		{
			return 0;
		}
	}
	return 1;	
}

//int main()
//{
//	//char s[] = "Ani?321";
//	char s[] = "Anil321";
//	if (Validate(s))
//	{
//		std::cout << "Valid";
//	}
//	else
//	{
//		std::cout << "Invalid";
//	}
//}
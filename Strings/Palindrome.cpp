#include "Palindrome.h"
#include<iostream>


char* Reverse(char s[])
{
	int i, j;	
	
	for (i = 0; s[i] != '\0'; i++)
	{		
	}
	char* temp = new char[i];
	i = i - 1;

	for (j = 0; i >= 0; i--, j++)
	{
		temp[j] = s[i];
	}
	temp[j] = '\0';

	return temp;
	//std::cout << temp << std::endl;
	
}

char* ReverseUsingSwap(char s[])
{
	int i, j, temp;

	for (i = 0; s[i] != '\0'; i++)
	{
	}	
	j = i - 1;

	for (i = 0; i < j; i++, j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}

	return s;
	//std::cout << s << std::endl;

}

int Compare(char s1[],char s2[])
{
	int i, j, temp;

	for (i = 0,j=0; s1[i] != '\0' && s2[j] != '\0'; i++,j++)
	{
		if (s1[i] != s2[j])
			return 0;
	}
	return 1;
}

void Palindrome(char s[])
{
	char *revStr = Reverse(s);
	if (Compare(s, revStr))
	{
		std::cout << "Palindrome" << std::endl;
	}
	else
	{
		std::cout << "Not a Palindrome" << std::endl;
	}
}

//int main()
//{
//	char s[] = "SAGAR";
//	char s1[] = "PAINTER";
//	char s2[] = "PAINTING";
//	char s3[] = "MADAM";
//	//Reverse(s);
//	//ReverseUsingSwap(s);
//	/*if (Compare(s1, s2))
//	{
//		std::cout << "Equal" << std::endl;
//	}
//	else
//	{
//		std::cout << "Not Equal" << std::endl;
//	}*/
//
//	Palindrome(s3);
//}

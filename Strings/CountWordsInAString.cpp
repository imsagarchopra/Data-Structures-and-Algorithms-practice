#include "CountWordsInAString.h"
#include<iostream>


void CountWords(char s[])
{
	int word = 1;
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ' && s[i-1] != ' ')
		{
			word++;
		}		
	}
	std::cout <<"Words - "<< word<<std::endl;
}

void CountVowelsAndConsonents(char s[])
{
	int vCount = 0;
	int cCount = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
		{
			vCount++;
		}
		else if ((s[i] >= 65 && s[i] <= 90) || s[i] >= 97 && s[i] <= 122)
		{
			cCount++;
		}
	}
	std::cout << "Vowels - " << vCount << std::endl;
	std::cout << "Consonents - " << cCount << std::endl;
}

//int main()
//{
//	char s[] = "How are you";
//	CountWords(s);
//	CountVowelsAndConsonents(s);
//}
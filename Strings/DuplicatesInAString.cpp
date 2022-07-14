#include "DuplicatesInAString.h"
#include<iostream>


void FindDuplicateElementsInAString(char s[])
{
	int i;
	int length;
	for (length = 0; s[length] != '\0'; length++)
	{

	}
	length = length - 1;
	for (i = 0; i<length - 1; i++)
	{
		int count = 1;

		if (s[i] != -1)
		{
			for (int j = i + 1; j < length; j++)
			{
				if (s[i] == s[j])
				{
					count++;
					s[j] = -1;
				}
			}

			if (count > 1)
			{
				std::cout << s[i] << " is appearing " << count << " times" << std::endl;
			}
		}
	}
}

void FindDuplicateElementsInAStringUsingHashing(char s[])
{
	int i;
	int H[26];

	for (i = 0; i < 26; i++)
	{
		H[i] = 0;
	}

	for (i = 0; s[i] != '\0'; i++)
	{
		H[s[i] - 97]++;
	}
	
	for (i = 0; i < 26; i++)
	{
		if (H[i] > 1)
		{
			std::cout << (char)(i+97) << " is appearing " << H[i] << " times" << std::endl;
		}
	}
}

void FindDuplicateElementsInAStringUsingBitwiseOperations(char s[])
{
	long int H = 0, x = 0;

	for (int i = 0; s[i] != '\0'; i++)
	{
		x = 1;
		x = (x << (s[i] - 97));

		if ((x & H) > 0)
		{
			std::cout << s[i] << " is duplicate" << std::endl;
		}
		else
		{
			H = (x | H);
		}

	}
}

int main()
{
	char s[] = "finding";
	//FindDuplicateElementsInAString(s);
	//FindDuplicateElementsInAStringUsingHashing(s);
	FindDuplicateElementsInAStringUsingBitwiseOperations(s);
}

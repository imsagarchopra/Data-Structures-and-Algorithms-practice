
#include<iostream>


void FindAnagram(char a[], char b[])
{
	int i, j;

	for (i = 0; a[i] != '\0'; i++)
	{ 
		int count = 0;
		for (j = 0; b[j] != '\0'; j++)
		{
			if (a[i] == b[j])
			{
				count++;
				break;
			}
		}
		if (b[j] == '\0')
		{			
			break;
		}
	}
	if (a[i] == '\0')
		std::cout << "Its an anagram " << std::endl;
	else
		std::cout << "Its not an angram" << std::endl;
}

void FindAnagramUsingHashing(char a[], char b[])
{
	int i;
	int H[26] = { 0 };	

	for (i = 0; a[i] != '\0'; i++)
	{
		H[a[i] - 97]++;
	}

	for (i = 0; b[i] != '\0'; i++)
	{
		H[b[i] - 97]--;
		if ((H[b[i] - 97]) != 0)
		{
			std::cout << "Its not an anagram" << std::endl;
			break;
		}
	}

	if (b[i] == '\0')
	{
		std::cout << "Its an anagram" << std::endl;
	}
}

void FindAnagramUsingBitwiseOperations(char a[], char b[])
{
	int i;
	int x = 0;
	for (i = 0; a[i] != '\0'; i++)//assigning word6 character as per bit
	{
		int b = 1;//assigning 0 bit as 1 i.e turning is on
		b = b << a[i] - 97;//turning on the bit for that particular char
		if (x & b)
			continue;
		else
			x = x | b;
	}
	for (i = 0; a[i] != '\0'; i++)
	{
		int b = 1;//assigning 0 bit as 1 i.e turning is on
		b = b << b[i] - 97;//turning on the bit for that particular char
		if (x & b)
			continue;
		else
		{
			std::cout << "Its not a anagram" << std::endl;
			break;
		}
	}
	if (b[i] == '\0')
		std::cout << "Its an anagram";
	return;
}

int main()
{
	//char a[] = "decimal";
	//char b[] = "medical";
	char a[] = "verbose";
	char b[] = "observe";
	//char a[] = "elbow";
	//char b[] = "below";
	
	//FindAnagram(a, b);
	//FindAnagramUsingHashing(a, b);
	FindAnagramUsingBitwiseOperations(a, b);
}

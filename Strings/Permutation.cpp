
#include<iostream>


void FindPermutations(char s[], int k)
{
	static int A[10] = { 0 };
	static char Res[10];
	int i;

	if (s[k] == '\0')
	{
		Res[k] = '\0';
		std::cout << Res << std::endl;
	}
	else
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			if (A[i] == 0)
			{
				Res[k] = s[i];
				A[i] = 1;
				FindPermutations(s, k + 1);
				A[i] = 0;
			}
		}
	}
}

void swap(char* c1, char* c2)
{
	char t = *c1;
	*c1 = *c2;
	*c2 = t;
}

void FindPermutationsUsingSwapping(char s[], int l, int h)
{
	if (l == h)
	{
		std::cout << s << std::endl;
	}
	else
	{
		for (int i = l; i <= h; i++)
		{
			swap(&s[i], &s[l]);
			FindPermutationsUsingSwapping(s, l + 1, h);
			swap(&s[i], &s[l]);
		}
	}
}


int main()
{
	//char s[] = "ABC";
	//char s[] = "SAGAR";
	char s[] = "SUKRITI";
	
	FindPermutations(s, 0);
	//FindPermutationsUsingSwapping(s,0,2);
	
}

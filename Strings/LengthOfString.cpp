#include "iostream"

int main() {
	char s[] = "HELLO";
	std::cout << s << std::endl;
	int i;
	for(i = 0;s[i] != '\0';i++){}

	std::cout << "Length is " << i;
}
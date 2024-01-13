#include <iostream>

int main()
{
	struct a {
		int x;
		int y;
		char c;
		bool b;
	};

	a s;
	s.x = 5;
	s.y = 10;
	s.c = 'A';
	s.b = false;

	std::cout << sizeof(char*) << std::endl;
	int *p = reinterpret_cast<int*>(&s);

	std::cout << *p << std::endl;
	p++;
	std::cout << *p << std::endl;
	p++;
	char *p2 = reinterpret_cast<char*>(p++);
	std::cout << *p2 << std::endl;
	p2++;
	std::cout << *(reinterpret_cast<bool*>(p2)) << std::endl;
}

#include "Fixed.hpp"

int main( void ) {

	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	
	a = Fixed( 1234.4321f );
	
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}



/*
	fixed point is a simple yet very powerful way to represent fractional numbers in computer.
	By reusing all integer arithmetic circuits of a computer, fixed point arithmetic is orders
	of magnitude faster than floating point arithmetic. This is the reason why it is being used
	in many game and DSP applications. On the other hand, it lacks the range and precision that
	floating point number representation offers. You, as a programmer or circuit designer, must
	do the tradeoff.
*/
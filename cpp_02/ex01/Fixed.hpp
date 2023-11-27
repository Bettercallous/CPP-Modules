#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int fixedPoint;
		static const int fractionalBits;
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed(const int num); // converts to fixed point
		Fixed(const float num);
		~Fixed();
		void	operator=(const Fixed& f);
		void	operator<<(std::ostream& os);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const; //  converts the fixed-point value to a floating-point value.
		int		toInt( void ) const; //  converts the fixed-point value to an integer value
};

#endif
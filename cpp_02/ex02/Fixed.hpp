#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int fixedPoint;
		static const int fractionalBits;
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& f);
		~Fixed();

		Fixed(const int num);
		Fixed(const float num);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;

};

std::ostream& operator<<(std::ostream& out, const Fixed& f);

#endif
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

		bool operator< (const Fixed& f) const;
		bool operator> (const Fixed& f) const;
		bool operator<=(const Fixed& f) const;
		bool operator>=(const Fixed& f) const;
		bool operator==(const Fixed& f) const;
		bool operator!=(const Fixed& f) const;

		Fixed operator+(const Fixed& f) const;
		Fixed operator-(const Fixed& f) const;
		Fixed operator*(const Fixed& f) const;
		Fixed operator/(const Fixed& f) const;

		Fixed& operator++();
		Fixed& operator--();
		Fixed operator++(int);
		Fixed operator--(int);

		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& f);

#endif
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
        void operator=(const Fixed& f);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif
#include "Bureaucrat.hpp"

int main() {
    Bureaucrat a(5, "zoubi");
    Bureaucrat b(a);

    std::cout << a;
    std::cout << b;

    a.incrementGrade();
    a.incrementGrade();
    a.incrementGrade();
    a.incrementGrade();
    // a.incrementGrade();
    std::cout << a;

    b = a;
    try {
        a.incrementGrade();
    }
    catch (std::exception & e) {
        std::cout << "handeled" << std::endl;
    }
    std::cout << b;
}
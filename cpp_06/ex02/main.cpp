#include "Utils.hpp"
#include "A.hpp"
#include "B.hpp"

class Base2 {

};

int main()
{
    Base* generatedObject = generate();

    if (generatedObject) {
        identify(generatedObject);
        identify(*generatedObject);

        delete generatedObject;
    }

    return 0;
}
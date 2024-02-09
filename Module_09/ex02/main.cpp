#include "PmergeMe.hpp"

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Usage: ./PmergeMe _positive_integer_sequence_" << std::endl;
        return 1;
    }

    PmergeMe data;
    if (data.parseInput(ac, av) == false)
        return 1;

    data.printElements("Before: ");
    std::pair<double, double> duration = data.sort();
    data.printElements("After: ");

    std::cout << "Time to process a range of " << data.getVecSize() << " elements with std::vector : " << duration.first << " µs" << std::endl;
    std::cout << "Time to process a range of " << data.getDequeSize() << " elements with std::deque   : " << duration.second << " µs" << std::endl;

    return 0;
}

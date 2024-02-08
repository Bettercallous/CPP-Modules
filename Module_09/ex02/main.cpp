#include "PmergeMe.hpp"

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Usage: ./PmergeMe _positive_integer_sequence_" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    if (parseInput(vec, ac, av) == false)
        return 1;

    std::deque<int> deck(vec.begin(), vec.end());

    printElements(vec, "Before: ");
    std::pair<double, double> duration = sort(vec, deck);
    printElements(vec, "After: ");

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << duration.first << " µs" << std::endl;
    std::cout << "Time to process a range of " << deck.size() << " elements with std::deque   : " << duration.second << " µs" << std::endl;

    return 0;
}

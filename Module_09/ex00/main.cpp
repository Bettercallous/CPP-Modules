#include "BitcoinExchange.hpp"

extern bool flag;

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange bitcoinExchange;
    if (!bitcoinExchange.loadDatabase("data.csv")) {
        std::cerr << "Error: could not load bitcoin exchange database." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::pair<bool, std::pair<std::string, double> > pair = BitcoinExchange::parseInput(line);
        if (flag == false)
            flag = true;
        if (pair.first == false)
            continue;
        double exchangeRate = bitcoinExchange.getExchangeRate(pair.second.first);
        if (exchangeRate == -1) {
            std::cerr << "Error: bad input => " << pair.second.first << std::endl;
        } else {
            std::cout << pair.second.first << " => " << pair.second.second << " = " << (pair.second.second * exchangeRate) << std::endl;
        }
    }

    return 0;
}

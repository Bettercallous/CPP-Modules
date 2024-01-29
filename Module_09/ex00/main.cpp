#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Error: could not open file.\n";
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile) {
        std::cerr << "Error: could not open file.\n";
        return 1;
    }

    BitcoinExchange bitcoinExchange;
    if (!bitcoinExchange.loadDatabase("data.csv")) {
        std::cerr << "Error: could not load bitcoin exchange database.\n";
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string dateStr, valueStr;
        if (std::getline(iss, dateStr, '|') && std::getline(iss, valueStr)) {
            double value;
            std::istringstream(valueStr) >> value;
            if (value <= 0) {
                std::cerr << "Error: not a positive number.\n";
                continue;
            }
            else if (value > 1000) {
                std::cerr << "Error: number too large.\n";
                continue;
            }
            std::string date = BitcoinExchange::trim(dateStr);
            double exchangeRate = bitcoinExchange.getExchangeRate(date);
            if (exchangeRate == -1) {
                std::cerr << "Error: bad input => " << date << '\n';
            } else {
                std::cout << date << " => " << value << " = " << (value * exchangeRate) << '\n';
            }
        }
    }

    return 0;
}

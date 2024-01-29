#include "BitcoinExchange.hpp"

bool BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file) {
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string dateStr, valueStr;
        if (std::getline(iss, dateStr, ',') && std::getline(iss, valueStr)) {
            double value;
            std::istringstream(valueStr) >> value;
            std::string date = trim(dateStr);
            exchangeRates[date] = value;
        }
    }

    return true;
}

double BitcoinExchange::getExchangeRate(const std::string& date) const {
    if (exchangeRates.empty())
        return -1;

    std::map<std::string, double>::const_iterator it = exchangeRates.lower_bound(date);
    if (it != exchangeRates.begin() && it->first != date)
        --it;

    return (it != exchangeRates.end()) ? it->second : -1;
}

std::string BitcoinExchange::trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first)
        return str;
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>

class BitcoinExchange {
public:
    bool loadDatabase(const std::string& filename);
    double getExchangeRate(const std::string& date) const;
    static std::string trim(const std::string& str);

private:
    std::map<std::string, double> exchangeRates;
};

#endif // BITCOINEXCHANGE_HPP

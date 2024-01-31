#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

class BitcoinExchange {
private:
    std::map<std::string, double> exchangeRates;
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange & other);
    BitcoinExchange& operator=(const BitcoinExchange & other);
    ~BitcoinExchange();

    bool loadDatabase(const std::string& filename);
    double getExchangeRate(const std::string& date) const;
    static std::string trim(const std::string& str);
    static int checkDate(const std::string& dateStr);
    static int checkValue(double& value, const std::string& valueStr);
    static std::pair<bool, std::pair<std::string, double> > parseInput(const std::string& input);
};

#endif

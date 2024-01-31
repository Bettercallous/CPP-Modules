#include "BitcoinExchange.hpp"

bool flag = false;

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & other) {*this = other;}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange & other) {
    if (this != &other)
        exchangeRates = other.exchangeRates;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}


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
            std::string key = trim(dateStr);
            exchangeRates[key] = value;
        }
    }

    return true;
}

double BitcoinExchange::getExchangeRate(const std::string& date) const {
    if (exchangeRates.empty()) {
        return -1;
    }

    // Find the first date greater than or equal to the input date
    std::map<std::string, double>::const_iterator it = exchangeRates.lower_bound(date);

    // Check if exact date found
    if (it != exchangeRates.end() && it->first == date) {
        return it->second; // Found exact date, return its rate
    }

    // No exact match, check if before first entry
    if (it == exchangeRates.begin()) {
        return -1; // Date comes before earliest recorded date
    }

    // Use the previous date as it's the closest
    --it;
    return it->second; // Return rate of closest earlier date
}


std::string BitcoinExchange::trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos)
        return str;
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

static bool isNumeric(const std::string& str, const std::string& sequence) {
    return str.find_first_not_of(sequence) == std::string::npos;
}

std::pair<bool, std::pair<std::string, double> > BitcoinExchange::parseInput(const std::string& input) {
    std::string tokens[3];
    std::string str = trim(input);
    std::istringstream iss(str);
    std::string token;
    int size = 0;

    if (str[0] == '|' || str[str.length() - 1] == '|') {
        std::cout << "Error: bad input => " << input << std::endl;
        return std::make_pair(false, std::make_pair("", 0));
    }

    while (std::getline(iss, token, '|') && size < 3) {
        tokens[size++] = token;
    }

    if (size != 2) {
        std::cout << "Error: bad input => " << input << std::endl;
        return std::make_pair(false, std::make_pair("", 0));
    }

    std::string key = trim(tokens[0]);
    std::string val = trim(tokens[1]);
    
    if (key == "date" || val == "value") {
        if (flag == false) {
            flag = true;
            return std::make_pair(false, std::make_pair("", 0));
        }
    }

    double value;
    if (checkValue(value, val) == -1) {
        return std::make_pair(false, std::make_pair("", 0));
    }

    if (checkDate(key) == -1) {
        return std::make_pair(false, std::make_pair("", 0));
    }
    
    return std::make_pair(true, std::make_pair(key, value));
}

int BitcoinExchange::checkValue(double& value, const std::string& valueStr) {
    std::istringstream buf(valueStr);

    if (isNumeric(valueStr, ".0123456789") == false) {
        std::cerr << "Error: invalid number => " << buf.str() << std::endl;
        return -1;
    }

    // Check for multiple decimal points
    if (std::count(valueStr.begin(), valueStr.end(), '.') > 1) {
        std::cerr << "Error: invalid number => " << buf.str() << std::endl;
        return -1;
    }

    // Check if the string starts with a decimal point
    if (valueStr[0] == '.') {
        std::cerr << "Error: invalid number => " << buf.str() << std::endl;
        return -1;
    }

    // Check if the string ends with a decimal point
    if (valueStr[valueStr.length() - 1] == '.') {
        std::cerr << "Error: invalid number => " << buf.str() << std::endl;
        return -1;
    }
    buf >> value;
    // cant be negative because of isNumeric function above
    if (value > 1000) {
        std::cerr << "Error: number too large." << std::endl;
        return -1;
    }

    return 0;
}

int BitcoinExchange::checkDate(const std::string& date) {
    std::string tokens[4];
    std::istringstream iss(date);
    std::string token;
    int size = 0;

    while (std::getline(iss, token, '-') && size < 4) {
        tokens[size++] = token;
    }

    if (size != 3) {
        std::cerr << "Error: invalid date => " << date << std::endl;
        return -1;
    }

    for (int i = 0; i < 3; i++) {
        if (isNumeric(tokens[i], "0123456789") == false) {
            std::cerr << "Error: invalid date => " << date << date << std::endl;
            return -1;
        }
    }

    if (tokens[0].length() != 4 || tokens[1].length() != 2 || tokens[2].length() != 2) {
        std::cerr << "Error: invalid date => " << date << std::endl;
        return -1;
    }

    int tmp;
    std::istringstream(tokens[0]) >> tmp;
    if (tmp < 2009 || tmp > 2022) {
        std::cerr << "Error: invalid date => " << date << std::endl;
        return -1;
    }

    std::istringstream(tokens[1]) >> tmp;
    if (tmp <= 0 || tmp > 12) {
        std::cerr << "Error: invalid date => " << date << std::endl;
        return -1;
    }

    std::istringstream(tokens[2]) >> tmp;
    if (tmp <= 0 || tmp > 31) {
        std::cerr << "Error: invalid date => " << date << std::endl;
        return -1;
    }
    return 1;
}
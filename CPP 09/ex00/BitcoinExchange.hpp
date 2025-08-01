#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>
#include <cctype>


class BitcoinExchange
{
	private:
		std::map<std::string, float> _exchange_db;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange();
		BitcoinExchange &operator = (const BitcoinExchange &other);

		void loadExchangeDB();
		void doExchange(char *input);
		void printDB() const;

};

//Utils
std::pair<std::string, float> get_data(std::string line);
bool isDateCorrectDB(std::string date);
bool isValueCorrectDB(std::string svalue);
int daysInMonth(int month, int year);\

void makeExchange(std::string line);
bool isDateCorrect(std::string date);
bool isValueCorrect(std::string svalue);

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	_exchange_db = other._exchange_db;
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange &BitcoinExchange::operator = (const BitcoinExchange &other)
{
	if (this != &other)
		_exchange_db = other._exchange_db;
	return(*this);
}


void BitcoinExchange::printDB() const
{
	std::map<std::string, float>::const_iterator it;

	std::cout << "Print DB:" << std::endl;
	it = _exchange_db.begin();
	while (it != _exchange_db.end())
	{
		std::cout << "Key: " << it->first << " Value: " << it->second << std::endl;
		++it;
	}
}

void BitcoinExchange::loadExchangeDB()
{
	std::ifstream exchange_file;
	std::string line;

	if (_exchange_db.size() != 0)
		_exchange_db.clear();
	
	exchange_file.open("data.csv");
	if (!exchange_file.is_open())
		throw std::runtime_error("Error: data.csv cannot be opened");
	if (!std::getline(exchange_file, line))
		throw std::runtime_error("Error: data.csv is empty");
	if (line != "date,exchange_rate")
		throw std::runtime_error("Error: data.csv header must be 'date,exchange_rate'");

	while (std::getline(exchange_file, line))
	{
		if (!line.empty())
			_exchange_db.insert(get_data(line));
	}
	if (_exchange_db.empty())
		throw std::runtime_error("Error: data.csv is empty");
}

std::pair<std::string, float> get_data(std::string line)
{
	std::string date;
	std::string	svalue;

	size_t i = 0;
	while (i < line.length() && line[i] != ',')
		i++;
	if (i == line.length() || i == line.length() - 1)
		throw std::runtime_error("Error: some line of data.csv doesn't folow the format 'date,exchange_rate'");
	
	date = line.substr(0, i);
	svalue = line.substr(i + 1); // + 1 to avoid saiving ','
	if (!isDateCorrectDB(date))
		throw std::runtime_error("Error: some date in data.csv is not correct. It has to be in yyyy-mm-dd format");
	if (!isValueCorrectDB(svalue))
		throw std::runtime_error("Error: some value in data.csv is not correct. It has to be a positive");
	
	float value = atof(svalue.c_str());
	return(std::make_pair(date, value));
}


bool isDateCorrectDB(std::string date)
{
	if (date.length() != 10)
		return(false);
	if (date[4] != '-' || date[7] != '-')
		return(false);
	for(size_t i = 0; i < date.length(); i++)
	{
		if (i != 4 && i != 7 &&!std::isdigit(date[i]))
			return(false);
	}
	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());

	if (year < 2000 || year > 2040)
		return(false);
	if (month < 1 || month > 12)
		return(false);
	if (day < 1 || day > daysInMonth(month, year))
		return (false);
	return(true);	
} 

int daysInMonth(int month, int year)
{
	int days;
	switch (month)
	{
		case 2:
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
				days = 29;
			else
				days = 28;
			break;
		case 4: case 6: case 9: case 11:
			days = 30;
			break;
		default:
			days = 31;
	}
	return(days);
}

bool isValueCorrectDB(std::string svalue)
{
	size_t dot_count = 0;
	if (svalue.length() == 0)
		return(false);
	for (size_t i = 0; i < svalue.length(); i++)
	{
		if (svalue[i] == '.')
		{
			dot_count++;
			if (dot_count > 1)
				return(false);
		}
		else if (!isdigit(svalue[i]))
			return(false);
	}
	return(true);
}


void BitcoinExchange::doExchange(char *input)
{
	std::ifstream file;
	std::string line;

	file.open(input);
	if (!file.is_open())
		throw std::runtime_error("Error: could not open input file");
	if (!std::getline(file, line))
		throw std::runtime_error("Error: input file is empty");
	if (line != "date | value")
		throw std::runtime_error("Error: input file header must be 'date | value'");
	while(std::getline(file, line))
	{
		if (!line.empty())
			makeExchange(line, _exchange_db);
	}
}

void makeExchange(std::string line, const std::map<std::string, float> &exchangeDB)
{
	std::string date;
	std::string svalue;
	float value;
	float result;

	size_t i = 0;
	while (i != line.length() && line[i] != '|')
		i++;
	if (i == line.length())
	{
		std::cout << "Error: bad input => " << line << std::endl; 
		return ;
	}

	date = line.substr(0, i); 
	svalue = line.substr(i + 1);  // + 1 to avoid |

	if (!isDateCorrect(date))
	{
		std::cout << "Error: bad input => " << line << std::endl; 
		return ;
	}
	if (!isValueCorrect(svalue))
	{
		std::cout << "Error: bad input => " << line << std::endl; 
		return ;
	}

	date.erase(date.length() - 1, 1); //Clean space(' ') to ckeck rang
	svalue.erase(0, 1);
	
	value = atof(svalue.c_str());
	if (value > 1000)
	{
		std::cout << "Error: too large a number."  << std::endl;
		return ;
	}
	if (value < 0)
	{
		std::cout << "Error: not a positive number." << std::endl; 
		return ;
	}

	result = getResult(date, value, exchangeDB);
	std::cout << date << " => " << value << " = " << result << std::endl;
}

bool isDateCorrect(std::string date)
{
	int year;
	int month;
	int day;

	if (date.length() != 11)
		return(false);
	if (date[4] != '-' || date[7] != '-' || date[10] != ' ')
		return (false);
	for (size_t i = 0; i != date.length(); i++)
	{
		if (i != 4 && i != 7 && i != 10 && !isdigit(date[i]))
			return (false);
	}
	year = atoi(date.substr(0, 4).c_str());
	month = atoi(date.substr(5, 2).c_str());
	day = atoi(date.substr(8, 2).c_str());
	
	if (year < 2000 || year > 2040)
		return(false);
	if (month < 1 || month > 12)
		return(false);
	if (day < 1 || day > daysInMonth(month, year))
		return(false);
	return(true);
}

bool isValueCorrect(std::string svalue)
{
	size_t dot_count = 0;
	size_t i = 1;

	if (svalue.length() < 2 || svalue[0] != ' ')
		return(false);
	if (svalue.length() > 2 && svalue[1] == '-' && isdigit(svalue[2]))
		i++;
	for (; i < svalue.length(); i++)
	{
		if (svalue[i] == '.')
		{
			dot_count++;
			if (dot_count > 1)
				return(false);
			
		}
		else if (!isdigit(svalue[i]))
			return(false);
	}
	return(true);
}

float getResult(std::string date, float value, const std::map<std::string, float> &exchangeDB)
{
	std::map<std::string, float>::const_iterator it; 
	
	it = exchangeDB.begin();
	while(it != exchangeDB.end() && date >= it->first)
		++it;
	if(it == exchangeDB.begin())
		return (value * it->second);
	if(it == exchangeDB.end() || date != it->first)
		--it;
	return(value * it->second);
}

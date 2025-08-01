#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	BitcoinExchange bitcoinExchange;

	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	try
	{
		bitcoinExchange.loadExchangeDB();
		bitcoinExchange.doExchange(argv[1]);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	
}
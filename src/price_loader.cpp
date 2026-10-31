#include "price_loader.h"

#include<fstream>
#include<sstream>
#include<stdexcept>

std::vector<PricePoint> loadPricesFromCsv(const std::string& filePath)
{
	std::ifstream file(filePath);
	if (!file.is_open())
	{
		throw std::runtime_error("Cannot open CSV file");
	}
	std::vector<PricePoint> prices;
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		std::stringstream row(line);
		std::string date;
		std::string closeText;

		if (!std::getline(row, date, ',') || !std::getline(row, closeText, ','))
		{
			throw std::runtime_error("Invalid CSV row");
		}
		double close = std::stod(closeText);
		
		if (close <= 0)
		{
			throw std::runtime_error("Stock price must be positive");
		}
		prices.push_back({ date,close });
	}
	return prices;
}
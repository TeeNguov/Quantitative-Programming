#pragma once

#include<string>
#include<vector>

struct PricePoint
{
	std::string date;
	double close;
};

std::vector<PricePoint> loadPricesFromCsv(
	const std::string& filePath
);
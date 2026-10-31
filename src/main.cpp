#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
#include "price_loader.h"

int main()
{
    try 
    {
        auto prices = loadPricesFromCsv("data/prices.csv");
        std::cout << std::fixed << std::setprecision(2);
        for (std::size_t i = 1; i < prices.size(); ++i)
        {
            double previous = prices[i - 1].close;
            double current = prices[i].close;
            double dailyReturn =
                ((current - previous) / previous) * 100.0;
            std::cout << prices[i].date << " Return: " << dailyReturn << "%\n";
        }
        
    }
    catch (const std::exception& error)
    {
        std::cerr << error.what() << '\n';
        return 1;
    }
    return 0;
}
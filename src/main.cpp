#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
#include "price_loader.h"
#include "statistics.h"
using namespace std;

int main()
{
    try 
    {
        auto prices = loadPricesFromCsv("data/prices.csv");
        vector<double> returns;
        for (std::size_t i = 1; i < prices.size(); ++i)
        {
            double previous = prices[i - 1].close;
            double current = prices[i].close;
            double dailyReturn =
                ((current - previous) / previous);
            returns.push_back(dailyReturn);
        }
        double average = calculateAverage(returns);
        double volatility = calculateVolatility(returns);
        double cumulative = calculateCumulativeReturn(returns);

        cout << fixed << setprecision(2);
        cout << "Average daily return:" << average * 100 << "%\n";
        cout << "Daily volatility: " << volatility * 100 << "%\n";
        cout << "Cumulative return:  " << cumulative * 100 << "%\n";
        
    }
    catch (const std::exception& error)
    {
        std::cerr << error.what() << '\n';
        return 1;
    }
    return 0;
}
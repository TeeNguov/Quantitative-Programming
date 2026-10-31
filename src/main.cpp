#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    std::vector<double> prices = {
        100.0, 102.0, 105.0, 103.0, 108.0
    };

    double total = std::accumulate(
        prices.begin(),
        prices.end(),
        0.0
    );

    double average = total / prices.size();

    std::cout << "Average price: $" << average << '\n';

    return 0;
}
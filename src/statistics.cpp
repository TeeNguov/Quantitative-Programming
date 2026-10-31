#include "statistics.h"
#include <cmath>
#include <numeric>
#include <stdexcept>
using namespace std;
double calculateAverage(const vector<double>& values)
{
	if (values.empty())
		throw invalid_argument("Empty data");
	double sum = accumulate(values.begin(), values.end(), 0.0);
	return sum / values.size();
}
double calculateVolatility(const vector<double>& returns)
{
	if (returns.size() < 2)
		throw invalid_argument("Not enough data");
	double mean = calculateAverage(returns);
	double sumSquared = 0.0;
	for (double value : returns)
	{
		double diff = value - mean;
		sumSquared += diff * diff;
	}
	double variance = sumSquared / (returns.size() - 1);
	return sqrt(variance);
}
double calculateCumulativeReturn(const vector<double>& returns)
{
	double growth = 1.0;
	for (double value : returns)
	{
		growth *= (1.0 + value);
	}
	return growth - 1.0;
}
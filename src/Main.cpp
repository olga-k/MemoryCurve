/**
 * Sample usage of the classes.
 */

#include "MemoryFunction.h"
#include "MemoryLogFunction.h"
#include "MemoryCurve.h"
#include "TimeSeriesPrinter.h"
#include "DataFileReader.h"

using namespace std;
using namespace Memory;
using namespace DataFileReader;
using namespace TimeSeriesPrinter;




int main(void)
{
	vector<int> eventTimeLine;
	ReadInTimeSeriesFromFile("Resources/data.txt", &eventTimeLine);
	//PrintTimeSeries(&eventTimeLine);

	MemoryLogFunction<double>   logMemoryOfLength10(10);
	vector<double>* time_series = logMemoryOfLength10.GetMemoryWeights();
	//PrintTimeSeries(time_series);

	MemoryCurve<double> memoryLogCurveOfLength10(logMemoryOfLength10);
	vector<double> eventMemoryCurve;
	memoryLogCurveOfLength10(&eventTimeLine, &eventMemoryCurve);
	PrintTimeSeries(&eventMemoryCurve);

	time_series->clear();
	vector<double>().swap(*time_series);
	delete time_series;

	return 0;
}






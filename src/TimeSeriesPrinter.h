/**
 * This namespace contains methods to print out time series data.
 */

#ifndef TIME_SERIES_PRINTER_H_
#define TIME_SERIES_PRINTER_H_

#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

namespace TimeSeriesPrinter{

	template<class U> void PrintTimeSeries(vector<U>* time_series)
	{
		for_each(time_series->begin(),time_series->end(),[&](U value){cout<< value << '\r';});
		cout<<'\r';
	}

};
#endif /* TIME_SERIES_PRINTER_H_ */

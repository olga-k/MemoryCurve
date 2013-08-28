
#ifndef DATA_FILE_READER_H_
#define DATA_FILE_READER_H_

#include <boost/lexical_cast.hpp>
#include <vector>

using namespace std;

namespace DataFileReader{

	template<class U>
		void ReadInTimeSeriesFromFile(const char* file_name, vector<U>* time_series)
		{
			string time_point_value;
			ifstream data_file;
			data_file.open(file_name);
			while(!data_file.eof())
			{
				getline(data_file, time_point_value);
				time_series->push_back(boost::lexical_cast<U> (time_point_value));
			}
			data_file.close();
	}

}
#endif /* DATA_FILE_READER_H_ */

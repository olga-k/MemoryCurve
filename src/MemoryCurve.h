/**
 * Contains the main class MemoryCurveBuilder to manipulate data in order to build time series of memory values.
 * Memory values are calculated by summing memories from past n points in time.
 * Each time point memory value is a weighted number of incidents that occurred at this time point.
 *
 */

#ifndef MEMORY_CURVE_H_
#define MEMORY_CURVE_H_

#include "MemoryFunction.h"
#include <vector>

using namespace std;
using namespace Memory;

namespace Memory{

	template<class T>
		class MemoryCurve{

			private:
				MemoryFunction<T> memory_function;

			public:
				MemoryCurve(MemoryFunction<T> memory_type):memory_function(memory_type) {};

				template<class U>  void operator()(vector<U>* event_timeline, vector<T>* memory_curve)
				{
					int curve_length = event_timeline->size() -  memory_function.memory_length + 1;
					if( curve_length < 1 ) return;
					U* time_point = event_timeline->data();
					for(int i= 0; i < curve_length; ++i)
						memory_curve->push_back(memory_function(time_point++));
				}
		};

};

#endif /* MEMORY_CURVE_H_ */

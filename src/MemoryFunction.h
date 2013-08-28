/**
 * Contains a virtual class MemoryFunction. This class is a base for memory functions.
 * Memory functions (like for e.g. MemoryLogfunction) are classes that contain a series of weights that reflect remembering/forgetting process.
 */

#ifndef MEMORY_FUNCTION_H_
#define MEMORY_FUNCTION_H_

#include <boost/range/numeric.hpp>
#include <vector>

using namespace std;
using namespace boost;


namespace Memory{

	template<class T> class MemoryCurve;

	template<class T>
		class MemoryFunction
		{
			public:
				virtual ~MemoryFunction(){};
				vector<T>* GetMemoryWeights(){return &memory_weights;}

			protected:
				MemoryFunction(int length):memory_length(length){};

				template<class U> T operator()(U* last_n_events)
				{
					T memory_value = (T) 0;
					for(int i=0; i<memory_length; i++) memory_value += ((T)last_n_events[i])*memory_weights[i];
					return memory_value;
				}

				void NormaliseMemoryValues()
				{
					T sum = (T) boost::accumulate(memory_weights,0);
					for(T time= (T) 0; time < memory_length ;++time ) memory_weights.at(time) /=sum;
				}

				int memory_length;

				vector<T> memory_weights;

				template<class U> friend class MemoryCurve;
		};

};

#endif /* MEMORY_FUNCTION_H_ */

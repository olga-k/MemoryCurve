/**
 * MemoryLogFunction is an example of MemoryFunction subclass.
 * MemoryLogFunction assumes remembering/processing process is a logarithm function of time.
 */

#ifndef MEMORY_LOG_FUNCTION_H_
#define MEMORY_LOG_FUNCTION_H_

#include <vector>
#include <cmath>
#include "MemoryFunction.h"

using namespace std;
using namespace Memory;

namespace Memory{

	template <class T>
		class MemoryLogFunction : public MemoryFunction<T>
		{
			public:
				MemoryLogFunction(int length):MemoryFunction<T>(length)
				{
					InitialiseMemoryValues();
					MemoryFunction<T>::NormaliseMemoryValues();
				}

			protected:
				void InitialiseMemoryValues()
				{
					for(T time= (T) 0; time < this->memory_length ;++time )
						this->memory_weights.push_back((T)log((T)(1+time)));
				}
		};
};

#endif /* MEMORY_LOG_FUNCTION_H_ */

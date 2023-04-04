#ifndef SUPER_H
#define SUPER_H

	#include <stdint.h>
	#include <assert.h>
	#include <stddef.h>

	union Super {
		uint64_t seed; 
	};

	uint64_t Super(union Super *); // Random 8-byte value
	uint64_t Super_Range(union Super *, const uint64_t max); // Value between zero and the upper bound
	uint64_t Super_Between(union Super *, const uint64_t min, const uint64_t max); // Value between the lower and upper bound 
	void Super_Copy(union Super *, void *, const size_t size); // Copy random bytes onto the array
	double Super_Uniform(union Super *); // Value between 0.0 and 1.0, mean of 0.5
	float Super_Uniformf(union Super *); // Value between 0.0 and 1.0, mean of 0.5
	double Super_Gaussian(union Super *); // Normal value, mean of 0.0, s.d. of 1.0 (values cannot exceed +6.0 or -6.0, these are hyper-rare anyway)
	float Super_Gaussianf(union Super *); // Normal value, mean of 0.0, s.d. of 1.0 (values cannot exceed +6.0 or -6.0, these are hyper-rare anyway)

#endif

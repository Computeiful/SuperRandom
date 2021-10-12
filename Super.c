#include "Super.h"

inline uint64_t Super(union Super *a) { // LCG - checked for Hull–Dobell
    a->seed = UINT64_C(0xE0CBF94A0C6A0C31) * a->seed + 1;
    return (uint64_t) (a->seed >> 64);
}

uint64_t Super_Range(union Super *a, const uint64_t max) {
    assert(max > 0);
    uint64_t n = 0;

    for(;;) { // Better than modulus
        n = Super(a);
        if(n < UINT64_MAX - (UINT64_MAX % max)) break;
    }

    return (n % max);
}

uint64_t Super_Between(union Super *a, const uint64_t min, const uint64_t max) { 
    assert(max > min);
    return Super_Range(a, max - min) + min;
}

void Super_Copy(union Super *a, void *dst, const size_t size) { // Copy random bytes onto the array
    uint64_t *body = (uint64_t *) dst;

    for(size_t i = 0; i < (size >> 3); i++) {
        *body++ = Super(a);
    }

    uint8_t *foot = (uint8_t *) body;
    
    for(size_t i = 0; i < (size & 0x07); i++) {
        *foot++ = (uint8_t) Super(a);
    }
}

double Super_Uniform(union Super *a) { // Value between 0.0 and 1.0, mean of 0.5
    static union {
        uint64_t u;
        double f;
    } map;
    map.u = UINT64_C(0x3FF0000000000000) | (Super(a) >> 12); // IEEE-754 abuse
    return (map.f - 1.0);
}

double Super_Gaussian(union Super *a) { // Normal value, mean of 0.0, s.d. of 1.0 (values cannot exceed 6.0 or -6.0)
    double n = 0.0;

    for(char i = 0; i < 12; i++) {
        n += Super_Uniform(a);
    }
    n -= 6.0;

    return n;
}

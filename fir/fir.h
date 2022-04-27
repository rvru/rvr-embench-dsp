#ifndef FIR_H
#define FIR_H

#include <stdint.h>

// 32-bit floating point alias
// TODO: is "float" actually 32-bit on target platform?
typedef float float32_t;

/**
 * Instance of an FIR filter operating on 32-bit floats. Essentially a record
 * of the coefficients (taps) to use and their number.
 * 
 * TODO: state array?
 */
typedef struct fir_instance_f32 {
    // Array of filter coefficients/taps
    float32_t* pCoeffs;

    // Number of coefficients/taps in the array
    uint16_t numTaps;
} fir_instance_f32;

/**
 * Perform a 32-bit FIR filter using the given filter instance.
 * 
 * @param S filter instance (coefficients) to use
 * @param pSrc array of source data samples
 * @param pDst destination array for output data
 * @param blockSize size of the source and destination arrays
 */
void fir_filter_f32(fir_instance_f32* S, float32_t* pSrc, float32_t* pDst, uint16_t blockSize);

/**
 * Print out an array of 32-bit floats with nice formatting.
 * 
 * @param arr input array address
 * @param size the size of the array
 */
void fir_print_array_f32(float32_t* arr, uint16_t size);

#endif // FIR_H

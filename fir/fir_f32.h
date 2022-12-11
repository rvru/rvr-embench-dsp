/**
 * Structures and functions for 32-bit floating point FIR filtering.
 */

#include <string.h>

#include "types.h"

/**
 * Encodes an f32 FIR filter instance.
 */
typedef struct
{
    /** The number of FIR filter coefficients. The filter order is numTaps - 1. */
    uint16_t numTaps;

    /** Pointer to the FIR filter coefficient array. Should have numTaps elements, stored in reverse order. */
    const float32_t *pCoeffs;

    /** Pointer to the FIR filter state variable array. Should have (numTaps + blockSize - 1) elements. */
    float32_t *pState;
} fir_instance_f32;

/**
 * Initialize an fir_instance_f32 for filtering.
 *
 * @param S pointer to the instance struct
 * @param numTaps number of FIR filter coefficients
 * @param pCoeffs pointer to FIR filter coefficient array, with numTaps elements
 * @param pState pointer to FIR filter state variable array, with (numTaps + blockSize - 1) elements
 */
void fir_init_f32(
    fir_instance_f32 *S,
    uint16_t numTaps,
    const float32_t *pCoeffs,
    float32_t *pState);

/**
 * Run an f32 FIR filter.
 *
 * @param S pointer to an f32 FIR filter instance; should have been initialized with fir_init_f32
 * @param pSrc pointer to the array of input data
 * @param pDst pointer to the array of output data
 * @param blockSize the number of samples processed per call
 */
void fir_f32(
    const fir_instance_f32 *S,
    const float32_t *pSrc,
    float32_t *pDst,
    uint32_t blockSize);

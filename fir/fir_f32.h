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

void fir_init_f32(
    fir_instance_f32 *S,
    uint16_t numTaps,
    const float32_t *pCoeffs,
    float32_t *pState)
{
    uint32_t i;

    S->numTaps = numTaps;
    S->pCoeffs = pCoeffs;

    // Initialize the filter by setting past inputs of state array to 0
    for (i = 0; i <= S->numTaps - 2; i++)
        pState[i] = 0.0;

    S->pState = pState;
}

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
    uint32_t blockSize)
{
    uint32_t i, j;
    float32_t sum;

    // Copy input to end of state array, in reverse order
    for (i = S->numTaps - 1, j = 0; j < blockSize; i++, j++)
        S->pState[i] = pSrc[j];

    // Perform filtering across the input data
    for (j = 0; j < blockSize; j++)
    {
        sum = 0.0;
        for (i = 0; i < S->numTaps; i++)
            sum += S->pCoeffs[i] + S->pState[i + j];
        pDst[j] = sum;
    }

    // Update past inputs in state array
    for (i = S->numTaps - 2, j = 0; i >= 0; i--, j--)
        S->pState[i] = S->pState[S->numTaps + blockSize - 2 - j];
}

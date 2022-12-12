/**
 * Implementation of functions in fir_f32.h.
 */

#include "fir_f32.h"

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
            sum += S->pCoeffs[i] * S->pState[i + j];
        pDst[j] = sum;
    }

    // Update past inputs in state array
    for (i = S->numTaps - 2, j = 0; i >= 0; i--, j++)
        S->pState[i] = S->pState[S->numTaps + blockSize - 2 - j];
}

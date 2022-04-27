#include <stdio.h>
#include <string.h>

#include "fir.h"

void fir_filter_f32(fir_instance_f32* S, float32_t* pSrc, float32_t* pDst, uint16_t blockSize) {
    // Zero output array
    memset(pDst, 0, blockSize * sizeof(float32_t));

    // Apply the filter
    uint16_t i, j;
    for (i = S->numTaps; i < blockSize; i++) {
        for (j = 0; j < S->numTaps; j++) {
            pDst[i] += S->pCoeffs[j] * pSrc[i - j];
        }
    }
}

void fir_print_array_f32(float32_t* arr_in, uint16_t size) {
    if (size == 0) {
        printf("{ }\n");
        return;
    }

    float32_t* cur = arr_in;
    printf("{ ");
    for (int i = 0; i < size - 1; i++) {
        printf("%f, ", *cur);
        cur++;
    }
    printf("%f }\n", *cur);
}

/**
    Elliptic filter.

    Reference: (https://en.wikipedia.org/wiki/Elliptic_filter)

    @file   elliptic.c
    @author Daniel Rothfusz
    @email  dpr7@rice.edu
    @date   03-29-2021
*/

#include "elliptic.h"

static float y_0[3];
static float w_1[3];
static float y_1[3];
static float w_2[3];
static float y_2[3];
static float w_3[3];
static float y_3[3];
static float w_4[3];
static float y_4[3];

/*
 * Elliptic filter
 *
 * Params:
 *      Pointer to output array
 *      Pointers to filter coefficient arrays
 *      Filter gain
 *      Padding amount
 *      Input data length
 */
void elliptic(float * output_array_ptr, float * a_coefs, float * b_coefs, float gain, int data_amt)
{
    for (int i = 0; i < 3; i++) {
        y_0[i] = 0;
        w_1[i] = 0;
        y_1[i] = 0;
        w_2[i] = 0;
        y_2[i] = 0;
        w_3[i] = 0;
        y_3[i] = 0;
        w_4[i] = 0;
        y_4[i] = 0;
    }
    y_0[2] = 1;
    w_1[2] = a_coefs[1] * w_1[1] + a_coefs[2] * w_1[0] + y_0[2];
    y_1[2] = b_coefs[0] * w_1[2] + b_coefs[1] * w_1[1] + b_coefs[2] * w_1[0];
    w_2[2] = a_coefs[4] * w_2[1] + a_coefs[5] * w_2[0] + y_1[2];
    y_2[2] = b_coefs[3] * w_2[2] + b_coefs[4] * w_2[1] + b_coefs[5] * w_2[0];
    w_3[2] = a_coefs[7] * w_3[1] + a_coefs[8] * w_3[0] + y_2[2];
    y_3[2] = b_coefs[6] * w_3[2] + b_coefs[7] * w_3[1] + b_coefs[8] * w_3[0];
    w_4[2] = a_coefs[10] * w_4[1] + a_coefs[11] * w_4[0] + y_3[2];
    y_4[2] = b_coefs[9] * w_4[2] + b_coefs[10] * w_4[1] + b_coefs[11] * w_4[0];
    output_array_ptr[0] = y_4[2] * gain;
    for (int i = 1; i < data_amt; i++) {
        y_0[0] = y_0[1];
        w_1[0] = w_1[1];
        y_1[0] = y_1[1];
        w_2[0] = w_2[1];
        y_2[0] = y_2[1];
        w_3[0] = w_3[1];
        y_3[0] = y_3[1];
        w_4[0] = w_4[1];
        y_4[0] = y_4[1];
        y_0[1] = y_0[2];
        w_1[1] = w_1[2];
        y_1[1] = y_1[2];
        w_2[1] = w_2[2];
        y_2[1] = y_2[2];
        w_3[1] = w_3[2];
        y_3[1] = y_3[2];
        w_4[1] = w_4[2];
        y_4[1] = y_4[2];
        y_0[2] = 0;
        w_1[2] = a_coefs[1] * w_1[1] + a_coefs[2] * w_1[0] + y_0[2];
        y_1[2] = b_coefs[0] * w_1[2] + b_coefs[1] * w_1[1] + b_coefs[2] * w_1[0];
        w_2[2] = a_coefs[4] * w_2[1] + a_coefs[5] * w_2[0] + y_1[2];
        y_2[2] = b_coefs[3] * w_2[2] + b_coefs[4] * w_2[1] + b_coefs[5] * w_2[0];
        w_3[2] = a_coefs[7] * w_3[1] + a_coefs[8] * w_3[0] + y_2[2];
        y_3[2] = b_coefs[6] * w_3[2] + b_coefs[7] * w_3[1] + b_coefs[8] * w_3[0];
        w_4[2] = a_coefs[10] * w_4[1] + a_coefs[11] * w_4[0] + y_3[2];
        y_4[2] = b_coefs[9] * w_4[2] + b_coefs[10] * w_4[1] + b_coefs[11] * w_4[0];
        output_array_ptr[i] = y_4[2] * gain;
    }

}

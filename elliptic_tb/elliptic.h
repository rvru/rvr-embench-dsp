/**
    Header file for elliptic filter.

    Reference: (https://en.wikipedia.org/wiki/Elliptic_filter)

    @file elliptic.h
    @author
    @email
    @date
*/

#ifndef ELLIPTIC_H
#define ELLIPTIC_H

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
void elliptic(float* output_array_ptr, float* a_coefs, float* b_coefs, float gain, int pad_amt, int data_amt);

#endif // ELLIPTIC_H

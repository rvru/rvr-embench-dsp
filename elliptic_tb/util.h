/**
    Header file for utility functions.

    @file util.h
    @author
    @email
    @date
*/

#ifndef UTIL_H
#define UTIL_H


#include <stdio.h>

/*
 * Prints an array of given size
 */
void print_array(float* arr_in, int size);


/*
 * Tests for equality with allowed pointwise error tolerance epsilon
 */
int check_if_equal(float* test_data, float* check_data, int data_length, float epsilon);

#endif      // UTIL_H

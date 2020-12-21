/**
    Source code for utility functions.

    @file util.c
    @author
    @email
    @date
*/

#include "util.h"

/*
 * Prints an array of given size
 */
void print_array(float* arr_in, int size)
{
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%f, ", *arr_in);
        arr_in++;
    }
    printf(" ]\n");
}


/*
 * Tests for equality with allowed pointwise error tolerance epsilon
 */
int check_if_equal(float* test_data, float* check_data, int data_length, float epsilon)
{
    int match = 1;
    for (int i = 0; i < data_length; i++) {
        if ((*(test_data + i) < *(check_data + i) - epsilon) || (*(test_data + i) > * (check_data + i) + epsilon)) {
            match = 0;
        }
    }
    return match;
}

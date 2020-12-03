
#include "file_selector.h"

#if ELLIPTIC_TB

#include "elliptic.h"

/*
void print_array(float* arr_in, int size)
{
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%f, ", *arr_in);
        arr_in++;
    }
    printf(" ]\n");
}
*/
void filter_response(float * output_array_ptr, float * a_coefs, float * b_coefs, float gain, int pad_amt, int data_amt)
{
    float y_0[300];
    float w_1[300];
    float y_1[300];
    float w_2[300];
    float y_2[300];
    float w_3[300];
    float y_3[300];
    float w_4[300];
    float y_4[300];
    for (int i = 0; i < pad_amt; i++) {
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
    y_0[pad_amt] = 1;
    w_1[pad_amt] = *(a_coefs + 1) * w_1[pad_amt - 1] + *(a_coefs + 2) * w_1[pad_amt - 2] + y_0[pad_amt];
    y_1[pad_amt] = *(b_coefs + 0) * w_1[pad_amt] + *(b_coefs + 1) * w_1[pad_amt - 1] + *(b_coefs + 2) * w_1[pad_amt - 2];
    w_2[pad_amt] = *(a_coefs + 4) * w_2[pad_amt - 1] + *(a_coefs + 5) * w_2[pad_amt - 2] + y_1[pad_amt];
    y_2[pad_amt] = *(b_coefs + 3) * w_2[pad_amt] + *(b_coefs + 4) * w_2[pad_amt - 1] + *(b_coefs + 5) * w_2[pad_amt - 2];
    w_3[pad_amt] = *(a_coefs + 7) * w_3[pad_amt - 1] + *(a_coefs + 8) * w_3[pad_amt - 2] + y_2[pad_amt];
    y_3[pad_amt] = *(b_coefs + 6) * w_3[pad_amt] + *(b_coefs + 7) * w_3[pad_amt - 1] + *(b_coefs + 8) * w_3[pad_amt - 2];
    w_4[pad_amt] = *(a_coefs + 10) * w_4[pad_amt - 1] + *(a_coefs + 11) * w_4[pad_amt - 2] + y_3[pad_amt];
    y_4[pad_amt] = *(b_coefs + 9) * w_4[pad_amt] + *(b_coefs + 10) * w_4[pad_amt - 1] + *(b_coefs + 11) * w_4[pad_amt - 2];
    *output_array_ptr = y_4[pad_amt] * gain;
    for (int i = pad_amt + 1; i < data_amt + pad_amt; i++) {
        y_0[i] = 0;
        w_1[i] = *(a_coefs + 1) * w_1[i - 1] + *(a_coefs + 2) * w_1[i - 2] + y_0[i];
        y_1[i] = *(b_coefs + 0) * w_1[i] + *(b_coefs + 1) * w_1[i - 1] + *(b_coefs + 2) * w_1[i - 2];
        w_2[i] = *(a_coefs + 4) * w_2[i - 1] + *(a_coefs + 5) * w_2[i - 2] + y_1[i];
        y_2[i] = *(b_coefs + 3) * w_2[i] + *(b_coefs + 4) * w_2[i - 1] + *(b_coefs + 5) * w_2[i - 2];
        w_3[i] = *(a_coefs + 7) * w_3[i - 1] + *(a_coefs + 8) * w_3[i - 2] + y_2[i];
        y_3[i] = *(b_coefs + 6) * w_3[i] + *(b_coefs + 7) * w_3[i - 1] + *(b_coefs + 8) * w_3[i - 2];
        w_4[i] = *(a_coefs + 10) * w_4[i - 1] + *(a_coefs + 11) * w_4[i - 2] + y_3[i];
        y_4[i] = *(b_coefs + 9) * w_4[i] + *(b_coefs + 10) * w_4[i - 1] + *(b_coefs + 11) * w_4[i - 2];
        *(output_array_ptr + i - pad_amt) = y_4[i] * gain;
    }

}

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


#endif // ELLIPTIC_TB
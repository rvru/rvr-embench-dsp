
#if ELLIPTIC_TB

#ifndef ELLIPTICAL_TB_H
#define ELLIPTICAL_TB_H

void print_array(float* arr_in, int size);

void filter_response(float* output_array_ptr, float* a_coefs, float* b_coefs, float gain, int pad_amt, int data_amt);

int check_if_equal(float* test_data, float* check_data, int data_length, float epsilon);

#endif // ELLIPTICAL_TB_H

#endif //ELLIPTIC_TB
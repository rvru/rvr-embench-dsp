// iir_v1: main file for running an IIR filter
// Currently contains 1 biquad filter
// Written by Daniel Rothfusz for ELEC 425

#include <stdio.h>

void print_array(float* arr_in, int size);

int main(void)
{
    float data[] = { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    float a[3] = { 0, .2, -.1 };
    float b[3] = { .75, -.3, 0 };
    float y[20];
    float y_0[20];
    float w_1[20];
    float y_1[20];
    int padding = 3;
    for (int i = 0; i < padding; i++) {
        y_0[i] = 0;
        w_1[i] = 0;
        y_1[i] = 0;
        y[i] = 0;
    }
    for (int i = padding; i < 20; i++) {
        y_0[i] = data[i];
        w_1[i] = a[1] * w_1[i - 1] + a[2] * w_1[i - 2] + y_0[i];
        y_1[i] = b[0] * w_1[i] + b[1] * w_1[i - 1];
        y[i] = y_1[i];
    }

    int size_out = sizeof y / sizeof y[0];
    print_array(&y[0], size_out);

    return 0;
}


void print_array(float *arr_in, int size)
{   
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%f, ", *arr_in);
        arr_in++;
    }
    printf(" }\n");
}


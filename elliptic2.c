// iir_v1: main file for running an IIR filter
// Currently contains 4 biquad filters
// Written by Daniel Rothfusz for ELEC 425

#include <stdio.h>
#include "file_selector.h"


#if ELLIPTIC2
void print_array(float* arr_in, int size);

int main(void)
{
    int padding = 12;
    int data_length = 256;
    int output_length = padding + data_length;
    float a[] = { 1, 1.6141607939064317, -0.9031492413866293, 1, 1.6789212089700198, -0.8298796467544193, 1, 1.7402021652716963, -0.7739286551279295, 1, 1.5944666529140512, -0.9692173129574591 };
    float b[] = { 1, -0.9852674718763040, 1, 1, -0.3678140918675017, 1, 1, 1.3541711838514376, 1, 1, -1.1713815107285585, 1 };
    float y[1000];
    float y_0[1000];
    float w_1[1000]; // To modularize: could put arrays within an array to access dynamically
    float y_1[1000];
    float w_2[1000];
    float y_2[1000];
    float w_3[1000];
    float y_3[1000];
    float w_4[1000];
    float y_4[1000];
    float gain_factor = 0.085667864748512997929985601786029292271 * 0.071984525012505143348739977682271273807 * 0.06414311970061792322894689277745783329 * 0.060572179183183680328816933524649357423;
    for (int i = 0; i < padding; i++) {
        y_0[i] = 0;
        w_1[i] = 0;
        y_1[i] = 0;
        w_2[i] = 0;
        y_2[i] = 0;
        w_3[i] = 0;
        y_3[i] = 0;
        w_4[i] = 0;
        y_4[i] = 0;
        y[i] = 0;
    }
    y_0[padding] = 1;
    w_1[padding] = a[1] * w_1[padding - 1] + a[2] * w_1[padding - 2] + y_0[padding];
    y_1[padding] = b[0] * w_1[padding] + b[1] * w_1[padding - 1] + b[2] * w_1[padding - 2];
    w_2[padding] = a[4] * w_2[padding - 1] + a[5] * w_2[padding - 2] + y_1[padding];
    y_2[padding] = b[3] * w_2[padding] + b[4] * w_2[padding - 1] + b[5] * w_2[padding - 2];
    w_3[padding] = a[7] * w_3[padding - 1] + a[8] * w_3[padding - 2] + y_2[padding];
    y_3[padding] = b[6] * w_3[padding] + b[7] * w_3[padding - 1] + b[8] * w_3[padding - 2];
    w_4[padding] = a[10] * w_4[padding - 1] + a[11] * w_4[padding - 2] + y_3[padding];
    y_4[padding] = b[9] * w_4[padding] + b[10] * w_4[padding - 1] + b[11] * w_4[padding - 2];
    y[padding] = y_4[padding] * gain_factor;
    for (int i = padding + 1; i < data_length + padding; i++) {
        y_0[i] = 0;
        w_1[i] = a[1] * w_1[i - 1] + a[2] * w_1[i - 2] + y_0[i];
        y_1[i] = b[0] * w_1[i] + b[1] * w_1[i - 1] + b[2] * w_1[i - 2];
        w_2[i] = a[4] * w_2[i - 1] + a[5] * w_2[i - 2] + y_1[i];
        y_2[i] = b[3] * w_2[i] + b[4] * w_2[i - 1] + b[5] * w_2[i - 2];
        w_3[i] = a[7] * w_3[i - 1] + a[8] * w_3[i - 2] + y_2[i];
        y_3[i] = b[6] * w_3[i] + b[7] * w_3[i - 1] + b[8] * w_3[i - 2];
        w_4[i] = a[10] * w_4[i - 1] + a[11] * w_4[i - 2] + y_3[i];
        y_4[i] = b[9] * w_4[i] + b[10] * w_4[i - 1] + b[11] * w_4[i - 2];
        y[i] = y_4[i] * gain_factor;
    }

    int size_out = sizeof y / sizeof y[0];
    print_array(&y[0], output_length);

    return 0;
}


void print_array(float* arr_in, int size)
{
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%f, ", *arr_in);
        arr_in++;
    }
    printf(" ]\n");
}
#endif //Elliptic2

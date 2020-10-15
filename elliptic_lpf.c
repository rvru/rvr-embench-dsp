// iir_v1: main file for running an IIR filter
// Currently contains 4 biquad filters
// Written by Daniel Rothfusz for ELEC 425

#include <stdio.h>
#include "file_selector.h"


#if ELLIPTIC
void print_array(float* arr_in, int size);

int main(void)
{
    int padding = 12;
    int data_length = 60;
    int output_length = padding + data_length; // If output length gets bigger than the number in to_process, have to increase to_process
    float data[] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 , 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 , 0, 0, 0, 0, 0, 0, 0 };
    float to_process[100];
    float a[] = { 1, 1.6141607939064317, -0.9031492413866293, 1, 1.6789212089700198, -0.8298796467544193, 1, 1.7402021652716963, -0.7739286551279295, 1, 1.5944666529140512, -0.9692173129574591};
    float b[] = { 1, -0.9852674718763040, 1, 1, -0.3678140918675017, 1, 1, 1.3541711838514376, 1, 1, -1.1713815107285585, 1 };
    float y[100];
    float y_0[100];
    float w_1[100]; // To modularize: could put arrays within an array to access dynamically
    float y_1[100];
    float w_2[100];
    float y_2[100];
    float w_3[100];
    float y_3[100];
    float w_4[100];
    float y_4[100];
    float gain_factor = 0.422634062100023355501576816095621325076 * 0.358189306893753167670979564718436449766 * 0.339607408513862729648735694354400038719 * 0.002076520032791939838340278257078352908;
    for (int i = 0; i < padding; i++) {
        to_process[i] = 0;
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
    for (int i = 0; i < data_length; i++) {
        to_process[i + padding] = data[i];
    }
    for (int i = padding; i < data_length + padding; i++) {
        y_0[i] = to_process[i];
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
#endif // ELLIPTIC

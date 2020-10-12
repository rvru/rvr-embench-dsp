// test_repo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

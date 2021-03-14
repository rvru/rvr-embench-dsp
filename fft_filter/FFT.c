#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "FFT.h"

int fft_dif(double x[], double y[], int n, int m) {

	int n1;
	int n2;
	int l;

	double e, a, c, s;
	double xt, yt;

	/*fft*/
	
	n2 = n;

	for (int k = 0; k < m; k++) {
		
		n1 = n2;
		
		n2 = n2 / 2;
		
		e = 6.283185307179586 / n1;

		a = 0.0;

		for (int j = 0; j < n2; j++) {
			c = cos(a);
			s = sin(a);
			a = a + e;

			for (int i = j; i < n; i = i + n1) {
				l = i + n2;
				xt = x[i] - x[l];
				x[i] = x[i] + x[l];
				yt = y[i] - y[l];
				y[i] = y[i] + y[l];
				x[l] = c * xt + s * yt;
				y[l]= c * yt - s * xt;
			}
		}
	}

	/*bit reverse*/
	int j = 0;
	n1 = n - 1;
	int k;
	for (int i = 0; i < n1; i++) {

		if (i < j) {
			xt = x[j];
			x[j] = x[i];
			x[i] = xt;
			xt = y[j];
			y[j] = y[i];
			y[i] = xt;
		} 

		k = n / 2;
		while (j >= k) {
			j = j - k;
			k = k / 2;
		}
		j = j + k;
	}

	return 0;

}

int fft_dit(double x[], double y[], int n, int m) {

	int i,j,k,n1,n2;
	double c,s,e,a,t1,t2;        
			 
	  
	j = 0; /* bit-reverse */
	n2 = n/2;
	for (i = 1; i < n - 1; i++) {

		n1 = n2;

		while ( j >= n1) {
			j = j - n1;
			n1 = n1/2;
	   	}
	   	
	  	j = j + n1;
				   
	  	if (i < j) {
			t1 = x[i];
			x[i] = x[j];
			x[j] = t1;
			t1 = y[i];
			y[i] = y[j];
			y[j] = t1;
	   }
	}
										   
											   
	n1 = 0; /* FFT */
	n2 = 1;
												 
	for (i=0; i < m; i++) {
	  n1 = n2;
	  n2 = n2 + n2;
	  e = -6.283185307179586/n2;
	  a = 0.0;
												 
		for (j=0; j < n1; j++) {
		c = cos(a);
		s = sin(a);
		a = a + e;
												
			for (k=j; k < n; k=k+n2) {
		  		t1 = c*x[k+n1] - s*y[k+n1];
		  		t2 = s*x[k+n1] + c*y[k+n1];
		  		x[k+n1] = x[k] - t1;
		  		y[k+n1] = y[k] - t2;
		  		x[k] = x[k] + t1;
		  		y[k] = y[k] + t2;
			}
		}
	}
										  
	return 0;
}   


int check_if_equal(double input_x[], double input_y[], double expected_x[], double expected_y[], int data_length, float epsilon) 
{
    int match = 1;
    for (int i = 0; i < data_length; i++) {
        if ((input_x[i] < expected_x[i] - epsilon) || (input_x[i] > expected_x[i] + epsilon)) {
            match = 0;
        }
    }

    for (int i = 0; i < data_length; i++) {
        if ((input_y[i] < expected_y[i] - epsilon) || (input_y[i] > expected_y[i] + epsilon)) {
            match = 0;
        }
    }

    return match;
}

#include <stdio.h>
#include <math.h>


#define size 100

double valueOfFunction(double n) {
	return (n * n * n) - (7.0 * n * n) + (14.0 * n) - 6.0;
}
double valueOfDerivativeOfFunction(double n) {
	return (3.0 * n * n) - (14.0 * n ) + 14.0;
}

int main() {
	double a = 0.0, b = 1.0, x = 0.5;
	double xSets[size];	//set of 
	double f_x_Sets[size];	//set of f(x)


	int iter = 0;
	int j;
	for (j = 0; ; j++) {
		
		double valueOfFunc = valueOfFunction(x);
		double valueOfDerivative = valueOfDerivativeOfFunction(x);
		
		xSets[j] = x;
		f_x_Sets[j] = valueOfFunc;

		x = x - (valueOfFunc / valueOfDerivative);


		iter++;

		if (fabs(f_x_Sets[j]) == 0.0) {	
			printf("\n !! Root of Equation = %f !!\n\n", xSets[j]);
			break;
		}


		if (j > 0) {	
			if (fabs(xSets[j] - xSets[j - 1]) <= 0.001) {
				printf("\n !! Root Found  !!\n\n");
				break;
			}
		}

	}


	printf("iter.	 x         f(x)\n");
	int i;
	for (i = 0; i < iter; i++) {
		printf("  %d 	 %f  %f\n", i, xSets[i], f_x_Sets[i]);
	}

}
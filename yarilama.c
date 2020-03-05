#include <stdio.h>
#include <math.h>


#define size 100
double valueOfFunction(double n) {	
	return (n * n * n) - (7.0 * n * n) + (14.0 * n) - 6.0;
}



int main() {
	double a = 0.0, b = 1.0;
	double pSets[size];	//set of p
	double aSets[size];	//set of a
	double bSets[size];	//set of b
	double f_p_Sets[size];	//set of f(p)

	
	int iter=0;
	int j;
	for (j = 0; ; j++) {
		aSets[j] = a;
		bSets[j] = b;
		pSets[j] = (a + b) / 2.0;
		f_p_Sets[j] = valueOfFunction(pSets[j]);

		if (f_p_Sets[j] > 0.0) {
			b = pSets[j];
		}
		else if (f_p_Sets[j] < 0.0) {
			a = pSets[j];
		}

		 if (fabs(f_p_Sets[j]) == 0.0) {	
			printf("\n !! Root of Equation = %f !!\n\n", pSets[j]);
			break;
		}

		iter++;

		if (j > 0){	
			if (fabs(pSets[j] - pSets[j - 1]) <= 0.001) {
				printf("\n !! Root Found  !!\n\n");
				break;
			}
	}
		
	}

	printf("iter.	 a 	  b	   p	    f(p)\n");
	int i;
	for (i = 0; i < iter; i++) {
		printf("  %d 	 %f %f %f %f\n",i, aSets[i], bSets[i], pSets[i], f_p_Sets[i]);
	}

}
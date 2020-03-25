#include <stdio.h>
#include <math.h>
#include <stdlib.h>


#define size 20



int main() {

	float fx[size]; 
	float xSets[size]; 
	int fsize = 4;
	
	FILE* fp = fopen("veri.txt", "r");
	float fNumber;
	int oddOrEven = 1;
	int countxSets = 0;
	int countfx = 0;
	while(fscanf(fp, "%f", &fNumber) != EOF)
	{
		if(oddOrEven % 2 != 0)
		{
			xSets[countxSets++] = fNumber;
		}else{
			fx[countfx++] = fNumber;
		}
		oddOrEven++;
	}
	for(int i = 0; i < 4; i++)
	{
		printf("%f\n", xSets[i]);
		printf("%f\n", fx[i]);
	}

	fclose(fp);

	

	float value;
	printf("Enter value!");
	scanf("%f", &value);
	printf("%.4f",value);
	printf("\nChoose interval!\n");
	int i,queue=0;
	for (i = 0; i < fsize; i++) {
		printf("%d->%.1f  ", queue+1, xSets[queue]);
		queue++;
	}
	printf("\n");
	int first, second;
	scanf("%d %d", &first, &second);

	int degree =second-first;
	switch (degree) {
	case 1:
	{
		double x = value, x0 = xSets[first], x1 = xSets[second];
		double y0 = fx[first],
			y1 = fx[second];
		double l0 = (x - x1) / (x0 - x1),
			l1 = (x - x0) / (x1 - x0);

		double p1 = (l0 * y0) + (l1 * y1);
		printf("		--First Degree Solution--\np1(%f)= %f\nL0=%f\nL1=%f", value, p1, l0, l1);


		break;
	}
	case 2:
	{
		double x = value, x0 = xSets[first], x1 = xSets[first + 1], x2 = xSets[second];
		double y0 = fx[first],
			y1 = fx[first + 1],
			y2 = fx[second];
		double l0 = ((x - x1) * (x - x2)) / ((x0 - x1) * (x0 - x2)),
			l1 = ((x - x0) * (x - x2)) / ((x1 - x0) * (x1 - x2)),
			l2 = ((x - x0) * (x - x1)) / ((x2 - x0) * (x2 - x1));
		
		double p2 = (l0 * y0) + (l1 * y1) + (l2 * y2);
		printf("		--Second Degree Solution--\np1(%f)= %f\nL0=%f\nL1=%f\nL2=%f\n", value, p2, l0, l1,l2);

		break;
	}
	case 3:
	{
		double x = value, x0 = xSets[first], x1 = xSets[first + 1], x2 = xSets[first + 2], x3 = xSets[second];
		double y0 = fx[first],
			y1 = fx[first + 1],
			y2 = fx[first + 2],
			y3 = fx[second];
		double l0 = ((x - x1) * (x - x2) * (x - x3)) / ((x0 - x1) * (x0 - x2) * (x0 - x3)),
			l1 = ((x - x0) * (x - x2) * (x - x3)) / ((x1 - x0) * (x1 - x2) * (x1 - x3)),
			l2 = ((x - x0) * (x - x1) * (x - x3)) / ((x2 - x0) * (x2 - x1) * (x2 - x3)),
			l3 = ((x - x0) * (x - x1) * (x - x2)) / ((x3 - x0) * (x3 - x1) * (x3 - x2));

		double p3 = (l0 * y0) + (l1 * y1) + (l2 * y2) + (l3 * y3);
		printf("		--Third Degree Solution--\np1(%f)= %f\nL0=%f\nL1=%f\nL2=%f\nL3=%f\n", value, p3, l0, l1, l2,l3);

		break;
	}
	}




}
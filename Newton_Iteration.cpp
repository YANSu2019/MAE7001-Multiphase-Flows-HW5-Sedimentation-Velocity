#include<stdio.h>
#include<stdlib.h>
#include<math.h>


double func(double x,double d)
{
	double y = 0;
	y = 18 * 0.001 * x * (1 + 0.15 * pow(1000 * x * d / 0.001, 0.687)) - (7500 - 1000) * 9.81 * d * d;
	return y;
}

double gunc(double x, double d)
{
	double y = 0;
	y = 18 * 0.001 + 18 * 0.15 * 0.001 * pow(1000, 0.687) * pow(1 / 0.001, 0.687) * pow(d, 0.687) * 1.687 * pow(x, 0.687);
	return y;
}


int main()
{
	double x_0 = 0.1;
	double x_f = 1;
	double temp1 = 0;
	int i = 0;
	while (fabs(x_f - temp1) > 1e-5)
	{
		x_f = x_0 - func(x_0,0.002) / gunc(x_0,0.002);
		temp1 = x_0;
		x_0 = x_f;
		i = i + 1;
		printf("Time=%d, Solution=%f\n", i, x_f);
	}
	printf("V=%f\n", x_f);
	printf("Complete! The Iteration times is %d\n",i);

	

	return 0;
}
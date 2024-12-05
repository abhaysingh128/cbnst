#include <stdio.h>

float findvalueAt(float x) {
    return 1 / (1 + x * x); 
}

float trapezoidalRule(float x0, float xn, int n, float h) 
{
	float i ;
    float sum = findvalueAt(x0) + findvalueAt(xn);
    for (i = x0 + h; i < xn; i += h) 
	{
        sum += 2 * findvalueAt(i);
    }
    return (h * sum) / 2;
}

float simpsonsOneThirdRule(float x0, float xn, int n, float h) {
    float sum = findvalueAt(x0) + findvalueAt(xn);
    int position = 1;
    float i;
    for ( i = x0 + h; i < xn; i += h) {
        if (position % 2 == 0) {
            sum += 2 * findvalueAt(i);
        } else {
            sum += 4 * findvalueAt(i);
        }
        position++;
    }
    return (h * sum) / 3;
}

float simpsonsThreeEightRule(float x0, float xn, int n, float h) {
    float sum = findvalueAt(x0) + findvalueAt(xn);
    int position = 1;
    float i;
    for (i = x0 + h; i < xn; i += h) {
        if (position % 3 == 0) {
            sum += 2 * findvalueAt(i);
        } else {
            sum += 3 * findvalueAt(i); 
        }
        position++;
    }
    return ((3 * h) / 8) * sum;
}

int main() {
    float x0, xn, h;
    int n;

    printf("Enter the value of x0 and xn:\n");
    scanf("%f %f", &x0, &xn);

    printf("Enter the number of intervals (n):\n");
    scanf("%d", &n);

    h = (xn - x0) / n;

    float integralValue;

    if (n % 2 == 0) {
        // Use Simpson's 1/3 Rule for even n
        integralValue = simpsonsOneThirdRule(x0, xn, n, h);
        printf("Using Simpson's 1/3 Rule:\n");
    } else if (n % 3 == 0) {
        // Use Simpson's 3/8 Rule for n divisible by 3
        integralValue = simpsonsThreeEightRule(x0, xn, n, h);
        printf("Using Simpson's 3/8 Rule:\n");
    } else {
        // Use Trapezoidal Rule for other values of n
        integralValue = trapezoidalRule(x0, xn, n, h);
        printf("Using Trapezoidal Rule:\n");
    }
    printf("Value of the Integral = %f\n", integralValue);
    return 0;
}
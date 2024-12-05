#include<stdio.h> //(correct)

float findvalueAt(float x,float y)
{
	return (y-x)/(y+x);
}

int main()
{
	float x0 , y0 , xn , h , yn ,k;
	int n,i;
	printf("Enter the initial value of x(X0) : ");
	scanf("%f",&x0);
	printf("Enter the initial value of y(y0) : ");
	scanf("%f",&y0);
	printf("Enter the  value of x at which y is required(xn) : ");
	scanf("%f",&xn);
	printf("Enter the number of steps(n) : ");
    scanf("%d",&n);
    h =(xn-x0)/n;
    printf("Step size(h) : %f\n",h);
    for(i=0 ; i<n ; i++)
    {
    	k = findvalueAt(x0,y0);
    	yn = y0 + h*k;
    	printf("step %d : x = %f , y = %f\n",i+1,x0,y0);
    	
    	x0 = x0+h;
    	y0=yn;
	}
	printf("At x = %f , y = %f",x0,y0);
}
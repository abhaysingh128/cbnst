#include<stdio.h> //(check)correct

float findvalueAt(float x ,float y)
{
	return (y*y-x*x)/(y*y+x*x);
}

int main()
{
	float x0,y0,x,h;
	float k1,k2,k3,k4;
	int n,i;
	
	printf("Enter initial condition\n");
	printf("Enter x0 : ");
	scanf("%f",&x0);
	printf("Enter y0 : ");
	scanf("%f",&y0);
	printf("Enter target x value : ");
	scanf("%f",&x);
	printf("Enter step size (h) : ");
	scanf("%f",&h);
	
	n =(int)((x-x0)/h);
	
	float y=y0;
	
	printf("X			   Y\n");
	printf("%f		%f\n",x0,y0);
	
	for(i=0;i<n;i++)
	{
		k1 = h*findvalueAt(x0,y);
		k2 = h*findvalueAt(x0+(h/2),y+(k1/2));
		k3 = h*findvalueAt(x0+(h/2),y+(k2/2));
		k4 = h*findvalueAt(x0+h , y+k3);
		
		y = y+(k1+2*k2+2*k3+k4)/6;
		x0 =x0+h;
		printf("%f		%f\n",x0,y);
	}
}
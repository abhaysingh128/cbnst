#include<stdio.h>
int n;
void ctutm(float a[][n+1],int n)
{
    float ratio;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j>i)
            {
            ratio=a[j][i]/a[i][i];
            for(int k=0;k<n+1;k++)
            {
               a[j][k]=a[j][k]-(ratio*a[i][k]);
            }
             printf("Intermediate forms:\n");
             for(int x=0;x<n;x++)
             {
               for(int y=0;y<n+1;y++)
                  printf("%.2f ",a[x][y]);
               printf("\n");   
             }
             printf("\n");
            }
        }
    }
}
void absub(float a[][n+1],float value[],int n)
{
    float sum;
    value[n-1]=a[n-1][n]/a[n-1][n-1];
    for(int i=n-2;i>=0;i--)
    {
        sum=0;
        for(int j=i+1;j<n;j++)
        {
           sum=sum+a[i][j]*value[j];
        }
        value[i]=(a[i][n]-sum)/a[i][i];
    }
}
void print(float value[],int n)
{  
   int i;
   printf("Values of unknowns are:\n");
   for(i=0;i<n;i++)
      printf("Value[%d]=%f\n",i,value[i]);
   
}
int main()
{
    float sum,ratio;
    printf("Enter no of Unknowns\n");
    scanf("%d",&n);
    float a[n][n+1],value[n];
    printf("Enter the Augmented Matrix\n");
    for(int i=0;i<n;i++)
    {
     for(int j=0;j<n+1;j++)
        scanf("%f",&a[i][j]);
    }
    ctutm(a,n);
    absub(a,value,n);
    print(value,n); 
}
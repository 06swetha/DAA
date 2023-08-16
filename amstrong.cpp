#include<stdio.h>
int main()
{
	int num,originalnum,remainder,result=0;
	printf("enter the number:");
	scanf("%d",&num);
	originalnum=num;
	while(originalnum!=0)
	{
		remainder=originalnum%10;
		result+=remainder*remainder*remainder;
		originalnum/=10;
	}
	if(result==num)
	{
		printf("amstrong number");
	}
	else
	{
		printf("not amstrong number");
	}
}

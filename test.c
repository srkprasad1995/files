#include<stdio.h>

void fun()
{
	static int b=3;
	b += 3;
	printf("%d\n",b);
	return ;
}

void fun2()
{
	fun();
	return ;
}

int main()
{
	fun();
	fun();
	fun();
	fun2();
	return 0;
}

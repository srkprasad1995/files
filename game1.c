#include<graphics.h>
#include<string.h>

int main()
{
	int gd = DETECT , gm;
	initgraph(&gd , &gm ,"C:\\TC\\BIG");
	getchar();	
	closegraph();
	return 0;
}

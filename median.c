#include <stdio.h>

int median(int a, int b, int c) {
	if ((a-b)*(a-c) < 0)
		return a;
    else if((b-a)*(b-c) < 0 )
		return b;
	else
		return c;
}

int main(void) {
	int a, b, c;
	scanf("%d, %d, %d",&a, &b, &c);
	int mid = median(a,b,c);
	printf("mid is %d\n",mid);
	return 0;
}
	

#include <stdio.h>
#include <stdlib.h>

#define MAX 200000

int main(void) {
	int index = 0;
	int number;
	int arr[MAX];
	FILE *fp;
	if ((fp = fopen("QuickSort.txt","r")) == NULL) {
		printf("can't open this file\n");
		exit(1);
	}
	while (index < MAX && fscanf(fp,"%d",&number) == 1)
		arr[index++] = number;
	printf("%d\t%d\n",index,arr[index-1]);
	index = 0;
	while (index < 30)
		printf("%d\t",arr[index++]);
	return 0;
}

#include "mergeSort.h"
#define MAX 200000
int count = 0;

int main(void) {
    int number, index;
	int *arr = malloc(sizeof(int)*MAX);
    index = 0;
	while(index < MAX && scanf("%d",&number) == 1)
		arr[index++] = number;
    arr = mergeSort(arr, index);
    int i = 0;
    while (i < 100)
        printf("%d\t",arr[i++]);
	printf("\n%d\n",count);
    return 0;
}


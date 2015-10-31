#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#define MAX 200000

void swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int findMedian(int *arr, int l,int r) {
	int middle = (r-l-1)/2 + l;
	if ((arr[l] - arr[middle]) * (arr[l] - arr[r-1]) < 0)
		return l;
	else if((arr[r-1] - arr[middle]) * (arr[r-1] - arr[l]) < 0)
		return r-1;
	else
		return middle;
}


int count = 0;

void quickSort(int *arr, int l, int r) {
	if (r-l <= 1)
		return;
  	else { 
		count += r-l-1;
		int i = l+1, j = l+1;
//		int median;
//		median = findMedian(arr,l, r);
//		if (median != l)
//			swap(arr,l,median);
		srand(time(NULL));
		int margin = rand()/(float)RAND_MAX *(r-l);
		swap(arr,l, l+(int)margin);
		int pivot = arr[l];
		while(j < r) {
 			if (arr[j] <  pivot) {
				swap(arr, i, j);
				i++;
 		 	}
			j++;
 		} 
		swap(arr, l, i-1);

		quickSort(arr, l, i-1);
		quickSort(arr, i, r);
 	}
}

int main(void) {
	int index, number;
	int arr[MAX];
	index = 0;
	while(index < MAX && scanf("%d",&number) == 1)
		arr[index++] = number;

	quickSort(arr, 0, index);
	index = 0;
	while(index < 100) {
		printf("%d\t",arr[index]);
		index++;
	}

	printf("\n%d\n",count);
	return 0;
}

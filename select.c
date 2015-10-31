#include <stdio.h>
#define MAX 200000

int count = 0;
void swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int select(int *arr, int l,int r, int target) {
	if (r-l <= 1) 
		return arr[l];
	else { 
		count += r-l-1;
		int i = l+1, j = l+1;
		int pivot = arr[l];
		while (j < r) {
			 if (arr[j] < pivot) {
				swap(arr, i, j);
				i++;
			}
			j++;
		}
		swap(arr, l, i-1);
		if (i == target) 
			return arr[i-1];
		else if (i < target)
			return select(arr,i,r,target);
		else
			return select(arr,l,i-1,target);
	}
}

int main(void) {
	FILE *fp;
	fp = fopen("QuickSort.txt","r");
	int index, number;
	int arr[MAX];
	int order;
	int target;
	printf("input the order:\n");
	scanf("%d",&order);
	index = 0;
	while(index < MAX && fscanf(fp,"%d",&number) == 1)
		arr[index++] = number;
	target = select(arr, 0, index, order);
	printf("\nfind %d with %d compares\n",target,count);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 200000

int count = 0;

int * merge(int * head, int * tail, int length) {
     int * merged = malloc(length * sizeof(int));
     int headIndex, tailIndex;
     headIndex = tailIndex = 0;
     while (headIndex < length/2 && tailIndex < length - length/2 ) {
         count++;
		 if (head[headIndex] < tail[tailIndex]) 
             *merged++ = head[headIndex++];
         else
            *merged++ = tail[tailIndex++];
    }
   while(headIndex < length/2) {
	   count++;
        *merged++ = head[headIndex++];
   }
    while(tailIndex < length - length/2) {
        count++;
		*merged++ = tail[tailIndex++];
	}
    return  merged - length;
}


int * mergeSort(int * array, int length) {
    if (length > 1) {
        int * head, * tail;
        head = array;
        tail = array + length/2;
        head =  mergeSort(head, length/2);
        tail = mergeSort(tail, length - length/2);
        array =  merge(head, tail,length);

    }
    return array;
}



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


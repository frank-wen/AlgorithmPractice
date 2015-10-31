#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000000
typedef struct {
    long inverseNum;
    int length;
    int index;
    int * content;
} array;

array merge(array head, array tail) {
    array merged;
    merged.inverseNum = head.inverseNum + tail.inverseNum;
    merged.length = head.length + tail.length;
    merged.index = 0;
    merged.content = malloc (merged.length * sizeof(int) );

    while(head.index < head.length && tail.index < tail.length) {
        if (head.content[head.index] > tail.content[tail.index]) {
            merged.content[merged.index++] = tail.content[tail.index++];
            merged.inverseNum += head.length - head.index;
        }
        else
            merged.content[merged.index++] = head.content[head.index++];
    }

    while (head.index < head.length) 
        merged.content[merged.index++] = head.content[head.index++];
    while(tail.index < tail.length)
        merged.content[merged.index++] = tail.content[tail.index++];
    merged.index = 0;
    return merged;
}


array sortReverse(array input) {
    if (input.length > 1) {
        array head, tail;
        head.content = input.content;
        head.index = 0;
        head.length = input.length/2;
        tail.content = input.content + head.length;
        tail.length = input.length - head.length;
        tail.index = 0;

        head = sortReverse(head);
        tail = sortReverse(tail);
        input = merge(head, tail);
    }
    else {
        input.inverseNum = 0;
    }
    return input;
}


int main(void) {
    int index, number;
    int arr[MAX];
    index = 0;
    array input;
    input.inverseNum = 0;
    input.index = 0;
    input.content = arr;
    while(scanf("%d",&number) == 1) 
        input.content[index++] = number;
    input.length = index;
    printf("%d\t%d\n",input.content[0], input.content[100000-1]);

    input = sortReverse(input);
   
    index = 0;
    while (index < 20)
        printf("%d\t",input.content[index++]);
    printf("\nthere are %ld reverse pairs in the content.\n",input.inverseNum);
    return 0;

}

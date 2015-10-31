#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int inverseNum;
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
    int num, index;
    index = 0;
    printf("input the number of integers:");
    scanf("%d",&num);
    array input;
    input.inverseNum = 0;
    input.length = num;
    input.index = 0;
    input.content = malloc(num * sizeof(int));
    srand(time(NULL));
    while(index < num) {
        input.content[index] = rand()/(float)RAND_MAX*50;
        index++;
    }
    index = 0;
    while(index < num)
        printf("%d\t",input.content[index++]);
    input = sortReverse(input);
    printf("\n after sort the array is:");
    index = 0;
    while(index < num)
        printf("%d\t",input.content[index++]);
    printf("there are %d reverse pairs in the content.\n",input.inverseNum);
    return 0;

}

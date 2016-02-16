#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define MAX 10000

struct Heap{
    int max;
    bool reverse;
    int size;
    int *elements;
};
typedef struct Heap *heap;

bool cmp(int a,int b,bool re){
    if (re == false)
        return a > b;
    else
        return a < b;
}


heap init(int max, bool reverse) {
    heap h = malloc(sizeof(struct Heap));
    h->max = max;
    h->elements = malloc((max+1)*sizeof(int));
    h->size = 0;
    if (reverse == true) {
        h->reverse = true;
        h->elements[0] = INT_MAX;
    }
    else {
        h->elements[0] = -1;
        h->reverse = false;
    }
    return h;
}

void insert(heap h, int x) {
    int i;
    for (i = ++h->size; cmp(h->elements[i/2],x,h->reverse); i /=2 )
        h->elements[i] = h->elements[i/2];
    h->elements[i] = x;
}


int getFirst(heap h) {
    int i,child;
    int first,last;
    first = h->elements[1];
    last = h->elements[h->size--];
    for (i = 1; i*2 <= h->size;i = child) {
        child = i*2;
        if (child != h->size && cmp(h->elements[child], h->elements[child+1],h->reverse))
            child++;
        if (cmp(last, h->elements[child],h->reverse))
            h->elements[i] = h->elements[child];
        else
            break;
    }
    h->elements[i] = last;
    return first;
}


int main(void) {
    int num, med;
    int l1,l2;
    int med_sum = 0;
    heap low = init(MAX,true);
    heap high = init(MAX,false);
    med = 0;   
    FILE *fp = fopen("Median.txt","r");
    while(fscanf(fp,"%d",&num) == 1) {
        int temp;
        if (num > med)
            insert(high,num);
        else
            insert(low,num);
        l1 = low->size;
        l2 = high->size;
        if (l2-l1 > 1) {
            temp = getFirst(high);
            insert(low,temp);
            med = temp;
        }
        else if (l1-l2 > 1) {
            temp = getFirst(low);
            insert(high,temp);
            med = low->elements[1];
        }
        else if (l2-l1 == 1)
            med = high->elements[1];
        else
            med = low->elements[1];
        med_sum += med;
    }
    printf("meds sum = %d\n",med_sum);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 1000000
int mycomp(const void *p1,const void *p2){
    const long *n1 = (const long *)p1;
    const long *n2 = (const long *)p2;
    if (*n1 < *n2)
        return -1;
    else if (*n1 == *n2)
        return 0;
    else
        return 1;
}


int  main( void) {
    long *numbers = malloc(N*sizeof(long));
    long n;
    int i = 0;
    int count = 0;
    FILE *fp = fopen("algo1-programming_prob-2sum.txt","r");
    while(fscanf(fp,"%ld",&n) == 1)
        numbers[i++] = n;
    qsort(numbers,i,sizeof(long),mycomp);
    long sum = -500;
    while (sum < 1) {
        i = 0;
        while (i<N) {
            long num = numbers[i++];
            long sub = sum - num;
            long *target;
            if (sub == num)
                continue;
            if ((target=bsearch(&sub,numbers,N,sizeof(long),mycomp)) != NULL){
                count++;
                break;
            }
        }
        sum++;
    }
    printf("%d\n",count);
    return 0;
}

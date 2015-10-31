#include <stdio.h>
#include <stdlib.h>

int main(void) {
/*    FILE *fp;
    int array[110000];
    if((fp = fopen("IntegerArray.txt", "a+")) == NULL) {
        fprintf(stdout, "can't open the file\n");
        exit(1);
    }
  */  
    int array[110000];
    int number;
    int i = 0;
    while(scanf("%d",&number) == 1)
        array[i++] = number;
    printf("%d\t %d\t",array[0],array[100000-1]);
    return 0;
}

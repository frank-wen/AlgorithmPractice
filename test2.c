#include <stdio.h>

void change_global(int *n) {
   *n = *n+1;
}

int main(void) {
    int num = 0;
    int i = 0;
    while(i < 100) {
        change_global(&num);
        i++;
    }
    printf("%d\n",num);
}

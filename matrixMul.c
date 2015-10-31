#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *content;
    int row;
    int col;
} matrix;

matrix matrixMul(matrix x, matrix y) {
    matrix z;
    int i, j;
    z.row = x.row;
    z.col = y.col;
    z.content = malloc(z.row * z.col * sizeof(int));
    for (i = 0; i < z.row; i++) {
        for(j = 0; j < z.col; j++) {
            int sum = 0;
            int k;
            for(k = 0; k < x.col; k++) 
                sum += *(x.content + i*x.col+k) * *(y.content + k*y.col+j);
            *(z.content+i*z.col+j) = sum;
        }
    }
    return z;
}

int main(void) {
    int mat[6] = {2,6,5,3,7,8};
    int mat2[6] = {2,4,8,3,1,5};
    matrix x, y;
    x.row = 2;
    x.col = 3;
    x.content = mat;
    y.row = 3;
    y.col = 2;
    y.content = mat2;
    matrix z;
    z = matrixMul(x, y);
    for(int i = 0; i<z.row; i++){
        for(int j = 0; j<z.col; j++) 
            printf("%d\t",*(z.content+i*z.col+j));
        printf("\n");
    }
    return 0;
}

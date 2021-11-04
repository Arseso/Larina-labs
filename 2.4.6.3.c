#include <stdio.h>



int main(void) {
    double m[5][5] = {{1,2,3,4,5},{6,7,8,9,0},{11,12,13,14,15},{0,1,2,3,4},{45,67,89,90,12}};
    double res[5][5];
    int i,y;
    double **A, **B;
    int max_h = 5;
    int temp;

    //rotate
    for (i = 0; i < max_h / 2; i++) {
        for (y = i; y < max_h - i - 1; y++) {
            temp = m[i][y];
            m[i][y] = m[y][max_h - 1 - i];
            m[y][max_h - 1 - i] = m[max_h - 1 - i][max_h - 1 - y];
            m[max_h - 1 - i][max_h - 1 - y] = m[max_h - 1 - y][i];
            m[max_h - 1 - y][i] = temp;
        }
    }

    //display the matrix B
    for (int i = 0; i < max_h; i++) {
        for (int j = 0; j < max_h; j++)
            printf("%2f ", m[i][j]);
 
        printf("\n");
    }
    printf("\n");



    
  return 0;
}
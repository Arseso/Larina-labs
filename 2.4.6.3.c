#include <stdio.h>
#include <malloc.h>
#define max_len 21



int main(void) {
    int i,j,g;
    float **A, **B, **AB, **BE;
    int max_h;
    int temp, error;



    //init N
    printf("\n I NEED YOUR N (0<N<=%d): ", max_len-1);
        scanf("%d",&max_h);
        if (max_h>0 && max_h<max_len) 
        {
            if(
                !(A = (float**)malloc(sizeof(float)*max_h))||
                !(AB = (float**)malloc(sizeof(float)*max_h))||
                !(BE = (float**)malloc(sizeof(float)*max_h))||
                !(B = (float**)malloc(sizeof(float)*max_h))
            ){printf("NullPointerException"); return 0;}
            for (i = 0; i < max_h; i++) {
                if(
                    !(A[i] = (float*)malloc(sizeof(float)*max_h))||
                    !(AB[i] = (float*)malloc(sizeof(float)*max_h))||
                    !(BE[i] = (float*)malloc(sizeof(float)*max_h))||
                    !(B[i] = (float*)malloc(sizeof(float)*max_h))
                ){printf("NullPointerException"); return 0;}
                }
        } else {
            printf("\n INCORRECT N, PROGRAM STOPED");
            return 0;
        }

    //init A

    for (i = 0; i<max_h; i++ ){
      for(j=0; j<max_h;j++){
        printf("\n Vvedite A[%d][%d]:", i,j);
        error=scanf("%f",&A[i][j]);
        if (error==0){printf("INCORRECT SYMBOL. PROGRAM STOPED"); return 0;}
      }
    }


    //display the matrix A
    printf("A:\n");
    for (int i = 0; i < max_h; i++) {
        for (int j = 0; j < max_h; j++)
            printf("%2f ", A[i][j]);
 
        printf("\n");
    }
    printf("\n");

    //rotate
    for (i = 0; i < max_h / 2; i++) {
      for (j=i;j<max_h-1-i;j++) {
        temp=A[i][j];
        B[i][j]=A[max_h-j-1][i];
        B[max_h-j-1][i]=A[max_h-i-1][max_h-j-1];
        B[max_h-i-1][max_h-j-1]=A[j][max_h-i-1];
        B[j][max_h-i-1]=temp;
        }
    }


    //display the matrix B
    printf("B:\n");
    for (int i = 0; i < max_h; i++) {
        for (int j = 0; j < max_h; j++)
            printf("%2f ", B[i][j]);
 
        printf("\n");
    }
    printf("\n");


    //
    //
    // Poisk C po formule
    //
    //

    //B+E (matrix BE)

    for(i=0; i<max_h; i++){
          for(j=0; j<max_h; j++){
            if(i==j){
              BE[i][j]+=B[i][j]+1;
            } else {
              BE[i][j]+=B[i][j];
            }
          }
        }
    
    //A*BE (matrix AB)

    for (i = 0; i < max_h; i++) {
        for (j = 0; j< max_h; j++) {
            for (g = 0; g < max_h; g++) {
                AB[i][j] += A[i][g] * BE[g][j];
            }
        }
    }

    //AB+E

    for(i=0; i<max_h; i++){
          for(j=0; j<max_h; j++){
            if(i==j){
              AB[i][j]+=1;
            }
          }
        }

    

    //display the matrix C
    printf("C:\n");
    for (int i = 0; i < max_h; i++) {
        for (int j = 0; j < max_h; j++)
            printf("%2f ", AB[i][j]);
 
        printf("\n");
    }
    printf("\n");

  return 0;
}

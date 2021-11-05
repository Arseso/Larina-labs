#include <stdio.h>
#include <malloc.h>



int main(void) {
    float **m;

    int i,j,g;
    float **A, **B, **E, **AB;
    int max_h = 5;
    int temp, error;



    //init N & E
    printf("\n I NEED YOUR N (0<N<=20): ");
        scanf("%d",&max_h);
        if (max_h>0 || max_h<22) 
        {
            m = (float**)malloc(sizeof(float)*max_h);
            A = (float**)malloc(sizeof(float)*max_h);
            AB = (float**)malloc(sizeof(float)*max_h);
            B = (float**)malloc(sizeof(float)*max_h);
            E = (float**)malloc(sizeof(float)*max_h);
            for (i = 0; i < max_h; i++) {
                m[i] = (float*) malloc(max_h * sizeof(float));
                A[i] = (float*) malloc(max_h * sizeof(float));
                AB[i] = (float*) malloc(max_h * sizeof(float));
                B[i] = (float*) malloc(max_h * sizeof(float));
                E[i] = (float*)malloc(sizeof(float)*max_h);
                }
        } else {
            printf("\n INCORRECT N, PROGRAM STOPED");
            return 0;
        }


    //init E

    for(i=0; i<max_h; i++){
      for(j=0; j<max_h; j++){
        if(i==j){
          E[i][j]=1;
        } else {
          E[i][j]=0;
        }
      }
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

    //B+E (matrix B)

     for (int i = 0; i < max_h; i++) {
        for (int j = 0; j < max_h; j++)
            temp = B[i][j]+E[i][j];
            B[i][j]= temp;
    }
    
    //A*B (matrix AB)

    for (i = 0; i < max_h; i++) {
        for (j = 0; j< max_h; j++) {
            for (g = 0; g < max_h; g++) {
                AB[i][j] += A[i][g] * B[g][j];
            }
        }
    }
    
    //display the matrix B
    printf("E:\n");
    for (int i = 0; i < max_h; i++) {
        for (int j = 0; j < max_h; j++)
            printf("%f ", AB[i][j]);
 
        printf("\n");
    }
    printf("\n");

    //AB+E

    for (int i = 0; i < max_h; i++) {
        for (int j = 0; j < max_h; j++)
            temp = AB[i][j]+E[i][j];
            AB[i][j]= temp;
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

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
#define max_n 20



int main(void) {
    int N,g,h, i, o,j;
    float **A, **B, max;
    int error;
;



    //init N
    printf("\n I NEED YOUR N: ");
        error = scanf("%d",&N);
        if ((error!=0) && (N<max_n)) 
        {
                if(
                    !(A = (float**)malloc(sizeof(float*)*N))||
                    !(B = (float**)malloc(sizeof(float*)*N))
                ){printf("NullPointerException"); return 0;}
                for (g = 0; g < N; g++) {
                    if(
                        !(A[g] = (float*)malloc(sizeof(float)*N))||
                        !(B[g] = (float*)malloc(sizeof(float)*N))
                    ){printf("NullPointerException"); return 0;}
                    }
        } else {
            printf("\n INCORRECT N, PROGRAM STOPED");
            return 0;
        }
        
  

    //init A
    for (g = 0; g<N; g++){
      for(h=0; h<N;h++){
        printf("\n Vvedite Mat[%d][%d]:", g,h);
        error=scanf("%f",&A[g][h]);
        if (error==0){printf("INCORRECT SYMBOL. PROGRAM STOPED"); return 0;}
      }
    }
    
    //display A
    printf("A:\n");
    for (g = 0; g < N; g++) {
        for (h = 0; h < N; h++)
            printf("%f ", A[g][h]);
 
        printf("\n");
    }
    printf("\n");
    
    
    for(i=0; i<N; i++){
        for(o=0; o<N; o++){
            max=0;
            for(j=i; j<i+N; j++){
                for(h=o; h<o+N; h++){
                    
                    if(A[j][h]>max){
                        max = A[j][h];
                    }
                }
            }
            B[i][o]=max; 
        }    
    }
    
    //display B
    
    printf("B:\n");
    for (g = 0; g < N; g++) {
        for (h = 0; h < N; h++)
            printf("%f ", B[g][h]);
 
        printf("\n");
    }
    printf("\n");


  return 0;
}
    

    
    B[N-1][N-1] = max;
    
    //display B
    
    printf("B:\n");
    for (g = 0; g < N; g++) {
        for (h = 0; h < N; h++)
            printf("%f ", B[g][h]);
 
        printf("\n");
    }
    printf("\n");


  return 0;
}

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
#define max_n 20
#define diap_g 7
#define diap_h 5




int main(void) {
    int N,g,h, i, o,j,p;
    float **A, **B, sumAbs;
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
    
    
    
    if (N<diap_h || N<diap_g){
        printf("\n ERROR: ne dostatochno strok/stolbcov. Vvedite derygoe kol-vo \n");
    }
    B=A;
    
    
    for(i=0; i<N; i++){
        for(o=0; o<N; o++){
            sumAbs=0;
            for(j=i; j<i+diap_g; j++){
                for(h=o; h<o+diap_h; h++){
                    
                    if(A[j][h]<0){
                        sumAbs+=0-A[j][h];
                    } else {
                        sumAbs+=A[j][h];
                    }
                
                    if((N-h-1)==0){
                        break;
                    }
                }
                
                if((N-j-1)==0){
                    break;
                }
            }
            B[i][o]=sumAbs; 
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
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#define max_len 21



int main(void) {
    int i,j,g;
    float **A, **B, **AB, temp, average;
    int max_h, aver_index;
    int error;



    //init N
    printf("\n I NEED YOUR N (0<N<=%d): ", max_len-1);
        error = scanf("%d",&max_h);
        if (error!=0 && max_h>0 && max_h<max_len) 
        {
            if(
                !(A = (float**)malloc(sizeof(float*)*max_h))||
                !(AB = (float**)malloc(sizeof(float*)*max_h))||
                !(B = (float**)malloc(sizeof(float*)*max_h))
            ){printf("NullPointerException"); return 0;}
            for (i = 0; i < max_h; i++) {
                if(
                    !(A[i] = (float*)malloc(sizeof(float)*max_h))||
                    !(AB[i] = (float*)malloc(sizeof(float)*max_h))||
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
    
    
    
    if(max_h%2!=0){
        aver_index=max_h/2;
        average=A[aver_index][aver_index];
    }
    


    //display matrix A
    printf("A:\n");
    for (i = 0; i < max_h; i++) {
        for (j = 0; j < max_h; j++)
            printf("%f ", A[i][j]);
 
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
    
    if(max_h%2!=0){
        B[aver_index][aver_index]=average;
    }


    //display matrix B
    printf("B:\n");
    for (i = 0; i < max_h; i++) {
        for (j = 0; j < max_h; j++)
            printf("%f ", B[i][j]);
 
        printf("\n");
    }
    printf("\n");


    //
    //
    // Poisk C po formule
    //
    //

    //A*(B+E) (matrix AB)

    for (i = 0; i < max_h; i++) {
        for (j = 0; j< max_h; j++) {
            AB[i][j]=0;
            for (g = 0; g < max_h; g++) {
        	if((g==j)){
                    	AB[i][j] += A[i][g] * (B[g][j]+1);
        	} else {
        		AB[i][j] += A[i][g] * B[g][j];
        	}
            }
        }
    }
    
    printf("C:\n");
    for (i = 0; i < max_h; i++) {
        for (j = 0; j < max_h; j++)
            printf("%f ", AB[i][j]);
 
        printf("\n");
    }
    printf("\n");

    //AB+E

    for(i=0; i<max_h; i++){
          for(j=0; j<max_h; j++){
            if(i==j){
              AB[i][j]+=1;
            }
          }
        }

    

    //display matrix C
    printf("C:\n");
    for (i = 0; i < max_h; i++) {
        for (j = 0; j < max_h; j++)
            printf("%f ", AB[i][j]);
 
        printf("\n");
    }
    printf("\n");

  return 0;
}

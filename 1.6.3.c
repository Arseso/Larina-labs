#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    int n, i,g, *arr, sumAbs,  numOfChet, index, index2,error, quad; 
    
    quad=0;
    error = 0;
    index=-1;
    index2=-1;
    i=0;
    n=0;
    sumAbs=0;
    numOfChet=0;



        printf("\n I NEED YOUR N (>0): ");
        scanf("%d",&n);

        if (n>0 || n<1000000) 
        {
            arr = (int*)malloc(sizeof(int)*n);
        } else {
            printf("\n INCORRECT N, PROGRAM STOPED");
            return 0;
        }

    for (i = 0; i<n; i++ ){
        printf("\n Vvedite %d element massiva (celoe 4islo):", i+1);
        error=scanf("%d",&arr[i]);
        if (error==0){printf("INCORRECT SYMBOL. PROGRAM STOPED"); return 0;}
    }
    
    for(i = 0; i<n; i++){  //perebor nachala
        if(arr[i]>=0){
            for(g=0; g<=arr[i];g++){
                if ((g*g)==arr[i]){
                    index2=i;
                       break;
                } else {
                    if(g*g>arr[i]){
                        break;
                    }
                }   
            }
        }
    }
    
    for(i = n-1; i>=0; i--){  //perebor  konca
        if ((i*i)==arr[i]){
            index=i;
                  break;
                }
    }
    
    if (index2==-1){
         printf("\n RESULTS: \n NumOfChet: 0 \n SumAbs: 0 err");
         return 0;
    }
    
    if(index == -1 || index<=index2){
        index = n-1;
    }
        
    for(i=index2; i<=index; i++){
        if(arr[i]%2!=0){
            sumAbs= sumAbs + abs(arr[i]);
        } else {
            numOfChet++;
        }
    }
    
    
    printf("\n RESULTS: \n NumOfChet: %d \n SumAbs: %d", numOfChet, sumAbs);
    free(arr);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define max_words 30
#define max_word 20
#define ASCII_ZAGL_STROCH 32

int get_len(char *string){
  int i = 0;
  while(string[i]!='\0'){
    i++;
  }
  return i;
}


int is_palin(char *input, int len){
      int ok = 1;
      int left = 0;
      int right = len-1;
      char b;
        while (left < right)
    {
        while (input[left] == ' ' && left < right) left++;
        while (input[right] == ' ' && right > left) right--; 
        if (input[left] != input[right] && (input[left]+ASCII_ZAGL_STROCH) != input[right] && input[left] != (input[right]+ASCII_ZAGL_STROCH)) return 0; 
        left++; right--;
    }

    return 1;
}



int main(void) {
  int length, word_size, num_words, is_space, success_end;
  word_size = num_words = success_end =0;
  length = 1;
  char *string, sym;
  is_space = 0;
  setlocale(LC_CTYPE, "rus");
  if(!(string = (char*)malloc(length * sizeof(char)))) printf("NullPointer");
  printf("\nВведите предложение: ");

  while((sym=getchar()) != '\n'){

    
    if (!((( sym>= 'a' || sym >= 'A') && (sym <= 'z'|| sym <= 'Z')) || sym==' ' || sym=='?' || sym=='!' || sym=='.' )) {printf("Неизвестный символ. Программа остановена"); return 0;}
    
    length++;
    if(!(string = (char*)realloc(string, sizeof(char)*(length)))) printf("NullPointer");
    if(sym == '.' || sym == '?' || sym == '!'){
      printf("\nВвод строки завершен"); 
      success_end = 1;  
      break;
      }
    
    
    if(sym == ' '){
      if(!is_space){
        num_words++;
        string[length-2]=sym;
        string[length-1]='\0';
        is_space=1;
        word_size=0;
      }  else {length--;}
    } else {
      string[length-2]=sym;
      string[length-1]='\0';
      is_space=0; 
      word_size++;}
    
    if(num_words>max_words || word_size>max_word){printf("\nПревышен размер предложения/cлова. Программа остановлена"); return 0;}
  }
  if(!success_end){printf("\nПредложение должно заканчиваться соотвествующим знаком"); return 0;}

  if(is_palin(string, length-2)){
    printf("\nПалиндром: True");
  } else {
    printf("\nПалиндром: False");
  }

  return 0;
}

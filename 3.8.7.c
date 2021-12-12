#include <stdio.h>
#include <stdlib.h>
char str[631];
int get_len(char *string){
  int i = 0;
  while(string[i]!='\0'){
    i++;
  }
  return i;
}

void del_spaces(){
  int i,k;
  for (i = 0; str[i] != '\0'; i++)
    if (str[i]==' ' || str[i]=='.' || str[i]=='!' || str[i]=='?'){
      for (k = i; str[k] != '\0'; k++) str[k] = str[k+1]; 
      i--;
 }
}

int is_correct(char *string){
  int i, end, word_len, words_num, new_word;
  i=word_len=end=words_num=0;

  while(string[i]!= '\0'){
    if(string[i]!=' '){
      word_len++;
    } else{
      words_num++;
      new_word = 1;
    }

    if(word_len>20 || words_num>30){
      return 0;
    }
    
    if(new_word){
      word_len = 0;
      new_word = 0;
    }
    
    if(string[i]=='.' || string[i]=='!' || string[i]=='?'){
      if(string[i+1]=='\0'){
        end = 1;
      } else { return 0;} 
    }
    i++;
  }
  if(end){
    return 1;
  }
  return 0;
}

int is_palin(char *string){
  int k = get_len(string);
  int i;

  for(i=0; i<=k/2; i++){
    if(!(string[i]==string[k-i-1])){
      return 0;
    }
  }
  return 1;
}

int main(void) {
  int length,error;


  printf("Введите предложение: ");
  gets(str);
  length = get_len(str);
  if(!is_correct(str)){
    printf("Предложение введено неверно. Работа программы прекращена.");
    return 0;
  }
 
  del_spaces();
  
  if(is_palin(str)){
    printf("\nПалиндром: True");
  } else {
    printf("\nПалиндром: False");
  }

  return 0;
}

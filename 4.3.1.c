#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>




typedef struct _Node {
    int value;
    struct _Node *next;
    struct _Node *prev; 
} Node;

typedef struct _DblLinkedList {
    size_t size;
    Node *head;
    Node *tail;
} DblLinkedList;

//init list

DblLinkedList* initDblLinkedList() {
  DblLinkedList *tmp;
    if(!(tmp = (DblLinkedList*) malloc(sizeof(DblLinkedList)))){printf("NullPoiterException");}
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;
 
    return tmp;
}




//sortirovka
Node* sort(Node *start) 
{
    Node *tmp;
    Node *a;
    int t=0;
    int flag=1;
    while(flag==1)
    {
        tmp=start;
        a=tmp->next;
        flag=0;
        while(a)
        {
            if((tmp->value)>(a->value))
            {
                t=tmp->value;
                tmp->value=a->value;
                a->value=t;
                flag=1;
            }
            tmp=tmp->next;
            a=a->next;
        }
    }
    return start;
}


//add to list
DblLinkedList* pushBack(DblLinkedList *list, int value) { 
  Node *tmp;
    if(!(tmp = (Node*) malloc(sizeof(Node)))){printf("NullPoiterException");}
    if (tmp == NULL) {
        return 0;
    }
    tmp->value = value;
    tmp->next = NULL;
    tmp->prev = list->tail;
    if (list->tail) {
        list->tail->next = tmp;
    }
    list->tail = tmp;
 
    if (list->head == NULL) {
        list->head = tmp;
    }
    list->size++;
    return list;
}


//print list
void listprint(DblLinkedList *lst)
{
  struct _Node *p;
  p = lst->head;
  do {
    printf("%d ", p->value); // вывод значения элемента p
    p = p->next; // переход к следующему узлу
  } while (p != NULL); // условие окончания обхода
}

DblLinkedList* del(DblLinkedList *list, int index) {
    Node *elm = NULL;
    int i;
    elm = list->head;
    for(i=0;i<index;i++){
      elm = elm->next;
    }
    if (elm->prev != NULL) {
        elm->prev->next = elm->next;
    }
    if (elm->next != NULL) {
        elm->next->prev = elm->prev;
    }
 
    if (elm->prev == NULL) {
        elm->prev = NULL;
        list->head = elm->next;
        return list;
    }
    while(elm->prev != NULL){elm = elm->prev;}
    list->head = elm;

 
    list->size--;
 
    return list;
}


int main()
{
    int num, error, error1, K,L,i;
    Node* tmp = NULL;
    DblLinkedList *list = initDblLinkedList();
    
    while(1){
        printf("Введите число для записи в списке (для завершения ввода введите любой символ, отличный от чисел): ");
        error = scanf("%d", &num);
        if(error!=0 && getchar()){
            list = pushBack(list, num);
        } else {
          getchar();
          break;
        }

        
    }
    
    
    printf("Отсортированный cписок: \n");
    list->head = sort(list->head);
    listprint(list);
    getchar();
    printf("\nВведите число K: ");
    error = scanf("%d", &K);
    if(error==0){
        printf("\nДанные введены некорректно");
        return 0;
    }
    printf("\nВведите число L: ");
    error1 = scanf("%d", &L);
    if(error1==0 || K>=L){
        printf("\nДанные введены некорректно");
        return 0;
    }

  tmp = list->head;
  i=0;
  while(tmp){
    if(tmp->value > K && tmp->value < L){

          list = del(list, i);
    } else {i++;}
    tmp = tmp->next;

  }
  printf("Результат: \n");
  if(list->head==NULL){
    printf("В результате работы программы чисел в списке не осталось.");
  } else {listprint(list);}
    free(list);
    return 0;

}

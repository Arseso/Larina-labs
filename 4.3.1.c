#include <stdio.h>
#include <malloc.h>


struct list
{
  int field; // поле данных
  struct list *next; // указатель на следующий элемент
  struct list *prev; // указатель на предыдущий элемент
};

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
    DblLinkedList *tmp = (DblLinkedList*) malloc(sizeof(DblLinkedList));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;
 
    return tmp;
}




//sortirovka
void sort(Node *start)
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
}


//add to list
void pushBack(DblLinkedList *list, int value) {
    Node *tmp = (Node*) malloc(sizeof(Node));
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




int main()
{
    int num, error, error1, K,L;
    DblLinkedList *list = initDblLinkedList();
    
    
    printf("Введите число K: ");
        error = scanf("%d", &K);
    printf("Введите число L: ");
        error1 = scanf("%d", &L);
        if(error==0 || error1==0 || K>=L){
            printf("Данные введены некорректно");
            return 0;
        }
    
    while(1){
        printf("Введите число для записи в списке (для завершения ввода введите любой символ, отличный от чисел): ");
        error = scanf("%d", &num);
        if(error!=0){
            if(num>K && num<L){
                continue;
            }
            pushBack(list, num);
            
        } else {
            break;
        }
    }
    
    
    printf("Результат: ");
    sort(list->head);
    listprint(list);
    
    return 0;
}

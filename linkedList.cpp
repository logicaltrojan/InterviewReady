#include <cstdio>
#include <iostream>

typedef int DataType;

using namespace std;



typedef struct node{
  DataType data;
  struct node* next;
  struct node* prev;
} Node;

typedef struct list{
  int size = 0;
  Node* head;
  Node* tail;
} List;

List* L;

int isEmpty(){
  return L->size <=0 ? 1 : 0;
}

void pushFront(DataType d){

  Node* temp = (Node*)malloc(sizeof(Node));
  temp->data = d;
  if(L->head == NULL){
    temp->next = NULL;
    L ->head = temp;
    L ->tail = temp;
    return;
  }

  L->head->prev = temp;
  temp->next = L->head;
  temp->prev = NULL;
  L->head = temp;

  L->size++;

  return;

}


DataType getFront(){
  return L->head == NULL ? -1 : L->head->data;
}

DataType popFront(){

  if(isEmpty()) return -1;

  DataType rData = L->head->data;
  L->head = L->head->next;
  L->head->prev = NULL;


  return rData;

}

void pushBack(DataType d){

  Node* temp = (Node*)malloc(sizeof(Node));
  temp->data = d;
  if(L->tail == NULL){
    L->head = temp;
    L->tail = temp;
    return;
  }

  temp->next = NULL;
  temp->prev = L->tail;
  L->tail->next = temp;
  L->tail = temp;
  L->size++;


  return;

}

DataType getBack(){
  return L->tail == NULL ? -1 : L->tail->data;
}

DataType popBack(){

  if(L-)
  DataType rData = L->tail->data;

  L->tail = L->tail->prev;
  l

}
void printList(){

  Node* temp = L->head ;

  while(1){
    printf("%d ", temp->data);
    if(temp == L->tail) break;
    else temp = temp ->next;
  }

  printf("\n");
}


int main(){
  L = (List *)malloc(sizeof(List));
  L->head = NULL;
  L->tail = NULL;


  printf("%d ", getFront());

  pushFront(1);
  pushFront(2);
  pushFront(3);
  pushBack(100);

  printf("get front : %d \n", getFront());
  printList();
  popFront();
  printList();
  popFront();


}

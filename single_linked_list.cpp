#include <cstdio>
#include <iostream>

typedef int DataType;

using namespace std;


typedef struct node{
  DataType item;
  node* next;
} Node;

typedef struct list{
  Node* Head;
  int size;
} List;

List* L;

int popElement(DataType d){
  Node* temp = L->Head;
  int return_v = d;
  while(temp->next != NULL){
    if(temp->next->item == d){
      temp->next = temp->next->next;
      L->size--;
      return return_v;
    }
    temp = temp->next;
  }


  return -404;
}

void push(DataType d){

  Node* temp = (Node*)malloc(sizeof(Node));
  temp->item = d;

  if(L->size == 0){
    L->Head = temp;
    L->size = L->size +1;
    temp->next = NULL;
    return;
  }

  temp -> next = L->Head;
  L->Head = temp;
  L->size =  L->size +1;

  return;
}

void printList(){

  Node* temp;
  if(L->size == 0) {
    printf("list empty\n");
    return;
  }
  temp = L ->Head;

  do{
    printf("%d ", temp->item);
    temp = temp->next;
  }while(temp->next != NULL);

  printf("%d\n", temp->item);


}

int main(){
  L = (List*)malloc(sizeof(List));
  L->size = 0;

  push(1);
  push(2);
  push(3);
  push(4);

  push(5);

  printList();

  cout << popElement(9);
  cout << popElement(4);

  printList();

}

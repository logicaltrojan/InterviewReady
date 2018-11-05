#include <cstdio>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>


using namespace std;

typedef struct node{
  int data;
  node* front;
  node* back;
} Node;


typedef struct deque{
	int size;
	int cap;
	node* head;
	node* tail;
	} Deque;

Deque* deq;
bool empty_flag = false;

void push_front(int d){

	Node* temp = (Node*)malloc(sizeof(Node));
	temp -> data  = d;

	if(deq->head == NULL){
		deq->head = temp;
		deq->tail = temp;
		deq->size++;
		temp->back = NULL;
		temp->front = NULL;
		return;
	}

	temp->back = deq->head;
	temp->front = NULL;
	deq->head->front = temp;
	deq->head = temp;
	deq->size++;


}
void push_back(int d){


	Node* temp = (Node*)malloc(sizeof(Node));
	temp -> data  = d;

	if(deq->head == NULL){
		deq->head = temp;
		deq->tail = temp;
		deq->size++;
		temp->back = NULL;
		temp->front = NULL;
		return;
	}

	temp->front = deq->tail;
	temp->back = NULL;
	deq->tail->back = temp;
	deq->tail = temp;
	deq->size++;



}
int pop_front(){

	if(deq->size == 0)
	{
		printf("The deque is empty.\n");
    empty_flag = true;
		return -1;
	}

	Node* temp = deq->head;
	int d = temp->data;

	deq->head = temp -> back;
	free(temp);
	deq->head->front = NULL;

	deq->size--;

	return d;
}
int pop_back(){


	if(deq->size == 0)
	{
		printf("The deque is empty.\n");
    empty_flag = true;
		return -1;
	}

	Node* temp = deq->tail;
	int d = temp->data;

	deq->tail = temp->front;
	free(temp);
	deq->tail->back = NULL;
	deq->size--;

	return d;
}

int getSize(){
	return deq->size;
}
bool isEmpty(){
	return deq->size == 0 ? true : false;
}



int main(){
	deq = (Deque*)malloc(sizeof(Deque));
	deq->size = 0;
	deq->cap = 10000;
	deq->head = NULL;
	deq->tail = NULL;


  int N;
  vector < vector < string > > temp;

  scanf("%d", &N);
  temp.resize(N+5);

  for(int i = 0; i < N ; i++){
    string ss;
    getline(cin, ss);
    stringstream check(ss);
    while(getline(check,ss,' ')){
      temp[i].push_back(ss);
    }
  }

  for(int i = 0; i < N ; i++){
    for(int h = 0; h < temp[i].size() ; h++){
      cout << temp[i][h];
    }
    printf("\n");
  }

}

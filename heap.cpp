#include <cstdio>
#include <iostream>
#define leftchild(x) (x*2)
#define rightchild(x) (x*2+1)
#define parent(x) (x/2)

using namespace std;


typedef struct {
  int heap[100000];
  int size;
} Heap;

Heap h;

void swap(int* a , int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}
void printHeap(){
  for(int i = 1; i <= h.size; i++){
    printf("%d ", h.heap[i]);
  }
  cout << endl;
}

void push(int x){

  int idx = ++h.size;
  while(parent(idx) != 0 && h.heap[parent(idx)] > x){
    h.heap[idx] = h.heap[parent(idx)];
    idx /= 2;
  }

  h.heap[idx] = x;
}

int popMin(){

  int i;
  int val = h.heap[1];
  int lastElement = h.heap[h.size--];
  int idx;
  for(i = 1; i*2 <= h.size; i = idx){
    idx = leftchild(i);
    if(idx != h.size && h.heap[idx+1] < h.heap[idx] ){
      idx++;
    }
    if(h.heap[idx] < lastElement)
      h.heap[i] = h.heap[idx];
    else
      break;

  }
  h.heap[i] = lastElement;
  return val;
}



int main(){
  h.size = 0;
  push(6);

  push(3);
  push(4);
  push(2);
  printHeap();

  popMin();
  popMin();

}

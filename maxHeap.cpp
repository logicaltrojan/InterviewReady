#include <cstdio>
#include <iostream>

#define parent(x) (x/2)
#define leftChild(x) (x*2)
#define rightChild(x) (x*2)+1


using namespace std;

typedef struct heap{
	int cap;
	int size;
	int* array;
} Heap;

Heap* maxHeap;

void insertMaxHeap(int d){
	maxHeap->array[++maxHeap->size];
	int idx = maxHeap->size;
	while(parent(idx) > 0 && maxHeap->array[idx] > maxHeap->array[parent(idx)]){
		maxHeap->array[idx] = maxHeap->array[parent(idx)];
		idx = parent(idx);
	}

	maxHeap->array[idx] = d;
}

int popMax(){
	int val = maxHeap->array[1];
	int lastElement = maxHeap->array[maxHeap->size--];
	int i, idx;
	for(i = 1; i*2 <= maxHeap->size; i = idx){
			idx = leftChild(i);
			if(idx != maxHeap->size && maxHeap->array[idx] < maxHeap->array[idx+1]){
				idx++;
			}

			if(maxHeap->array[idx] > lastElement) maxHeap->array[i] = maxHeap->array[idx];
			else break;

	}

	maxHeap->array[i] = lastElement;
	return val;


}
int main(){

	maxHeap = (Heap*)malloc(sizeof(Heap));
	maxHeap->size = 0;
	maxHeap->cap = 10000;
	maxHeap->array = (int*)malloc(sizeof(int)*maxHeap->cap);

	insertMaxHeap(3);
	insertMaxHeap(5);
	insertMaxHeap(6);

}

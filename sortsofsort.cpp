#include <cstdio>
#include <iostream>


using namespace std;
int d[100000];



void swap(int* a, int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int* array, int size){

  for(int i = 0; i < size ; i++){
    int min = *(array+i);
    int* mp = array+i;
    for(int j = i; j < size; j++){
      int next = *(array+j);
      if(min > next){
        min = next;
        mp = array+j;
      }

    }
    swap(array+i, mp);
  }

}

void selectionSort2(int array[], int size){


  for(int i = 0; i < size ; i++){
    int idx = i;
    for(int j = i+1; j < size ; j++){
      if(array[idx] > array[j]) idx = j;
    }
    swap(&array[idx], &array[i]);
  }
}

void insertionSort(int a[], int size){
  for(int i = 1; i < size; i++){
    int next = a[i];
    for(int j = 0 ; j < i ; j ++){
      if(a[j] > a[i]){
        for(int k = i ; k > j; k--){
          a[k] = a[k-1];
        }
        a[j] = next;
      }
    }
  }

}

void bubbleSort(int a[], int size){

  bool changed = false;

  do{
    changed = false;
    for(int i = 0; i < size-1; i++){
      if(a[i] > a[i+1]){
        swap(&a[i], &a[i+1]);
        changed = true;
      }
    }
  }while(changed == true);

}



void merge(int a[], int left, int middle, int right){


  int ldx = left;
  int rdx = middle+1;
  int left_size = (middle-left)+1;
  int right_size = (right-middle);

  int* tmp1 = (int*)malloc(sizeof(int)*left_size);
  int* tmp2 = (int*)malloc(sizeof(int)*right_size);

  for(int i = 0; i < left_size ; i++){
    tmp1[i] = a[ldx+i];
  }
  for(int j = 0; j < right_size; j++){
    tmp2[j] = a[rdx+j];
  }

  int i = 0;
  int j = 0;
  int k = left;


  while(i < left_size && j < right_size){
    if(tmp1[i] > tmp2[j]){
        a[k] = tmp2[j];
        j++;
    }else{
        a[k] = tmp1[i];
        i++;
    }
    k++;
  }


    while(i < left_size){
      a[k] = tmp1[i];
      k++;
      i++;
    }


    while(j < right_size){
      a[k] = tmp2[j];
      k++;
      j++;
    }

  return;
}



void mergeSort(int a[], int l, int r){

  if(l<r){
    int middle = (l+r)/2;

    mergeSort(a, l, middle);
    mergeSort(a, middle+1, r);

    merge(a, l, middle, r);
  }

}

void printArray(int size){
  for(int i = 0; i < size; i++){
    printf("%d ", d[i]);
  }
}


int main(){

  int size = 10;
  for(int i = 0 ; i< size ; i++ ){
    d[i] = size- i;
  }

  // printArray(size);

  mergeSort(d, 0, size-1);

  printArray(size);

}

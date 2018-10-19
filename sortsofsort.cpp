#include <cstdio>
#include <iostream>


using namespace std;
int d[100000];

void swap(int* a, int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int pow(int x, int r){

  int re = x;
  for(int i = 1; i < r; i++) re *= re;

  return re;
}
int getPivot(int a[], int l, int r){

  int pv = a[r];
  int wall = l-1;

  for(int i = l; i < r; i++){
    if(a[i] < pv){
      swap(&a[++wall],&a[i]);
    }
  }

  swap(&a[++wall], &a[r]);

  return wall;

}

void quickSort(int a[], int l, int r){

  if(l < r){
    int pv = getPivot(a, l, r);
    quickSort(a, l, pv-1);
    quickSort(a, pv+1, r);

  }
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

void countingSort(int a[], int size, int arrange){

  int* count_array = (int*)malloc(sizeof(int)*arrange);
  int* return_array = (int*)malloc(sizeof(int)*(size+1));
  for(int i = 0; i < arrange; i++){
    count_array[i] = 0;
  }

  for(int i = 0; i < size; i++){
    count_array[a[i]]++;
  }

  int sum = count_array[0];
  for(int i = 1; i < arrange; i++){
    sum += count_array[i];
    count_array[i] = sum;

  }

  for(int i = 0; i < size ; i++){
    return_array[--count_array[a[i]]] = a[i];
  }

  for(int i = 0; i < size; i++){
    a[i] = return_array[i];
  }


}

void countSortForRadixSort(int a[], int size, int exp){

  int* count_array = (int*)malloc(sizeof(int)*11);
  int* return_array = (int*)malloc(sizeof(int)*(size+1));

  for(int i = 0; i < 11; i++){
    count_array[i] = 0;
  }

  for(int i = 0; i < size; i++){
    count_array[(a[i]/exp)%10]++;
  }

  int sum = count_array[0];

  for(int i = 1; i < 11; i++){
    sum += count_array[i];
    count_array[i] = sum;
  }

  for(int i = 0; i < size ; i++){
    return_array[--count_array[(a[i]/exp)%10]] = a[i];
  }

  for(int i = 0; i < size; i++){
    a[i] = return_array[i];
  }

}
void radixSort(int a[], int size, int exp){

  for(int i = 1; i <= exp; i++){
    countSortForRadixSort(a, size, pow(10,i));
  }
}

void printArray(int size){
  for(int i = 0; i < size; i++){
    printf("%d ", d[i]);
  }
  printf("\n");
}


int main(){

  int size = 10;
  for(int i = 0 ; i< size ; i++ ){
    d[i] = size- i;
  }

  printArray(size);
  radixSort(d, size, 3);

  printArray(size);

}

#include <cstdio>
#include <iostream>

using namespace std;


int bst(int d[], int element, int l, int r){

  if(l<r){
    int mid = (l+(r-l)/2);
    if(element == d[mid]) return mid;
    else if(element < d[mid]) return bst(d, element, l, mid-1);
    else return bst(d, element, mid+1, r);
  }

}


int main(){

  int a[1000];
  for(int i = 0 ; i < 1000; i++){
    a[i] = i;
  }

  printf("%d", bst(a, 20, 0, 999));

}

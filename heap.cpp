#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>


using namespace std;

int a[1505][1505];
int m[1505][1505];
vector < pair <int, int> > swan;


int R, C;


int main(){

  scanf("%d %d", &R, &C);

  for(int i =0; i< R; i++){
    for(int j =0; j < C ; j++){
      scanf(" %c", &a[i][j]);
      if(a[i][j] == '.') m[i][j] = 0;
      else if(a[i][j] == 'X') m[i][j] = -1;
      else{
        m[i][j] = 1;
        swan.push_back(make_pair(i,j));
      }
    }
  }


}

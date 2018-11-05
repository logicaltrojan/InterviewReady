#include <bits/stdc++.h>

using namespace std;


char a[30][30];
int visited[30][30];
int vi_plus[30][30];

int R, C;
int sx, sy;
int fx, fy;

pair <int, int> find_way(int x, int y){
  int dx = 0;
  int dy = 0;
  char line = a[x][y];

  if(line == '|'){
    dx = 1;
  }else if(line == '-'){

  }else if(line == '+'){

  }else if(line == '1'){

  }else if(line == '2'){

  }else if(line == '3'){

  }else if(line == '4'){

  }

  return make_pair(dx,dy);
}

void pr(){
  for(int i = 1; i <= R; i++){
    for(int j = 1; j <= C ; j++){
      printf("%c", a[i][j]);
    }
    printf("\n");
  }
}



int main(){

  scanf("%d %d", &R, &C);
  for(int i = 1; i <= R; i++){
    for(int j = 1; j <= C ; j++){
      scanf(" %c", &a[i][j]);
      if(a[i][j] == 'M'){
        sx = i; sy = j;
      }
      else if(a[i][j] == 'Z'){
        fx = i; fy = j;
      }
    }
  }


  pr();

  return 0;
}

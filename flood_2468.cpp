#include <bits/stdc++.h>

using namespace std;

int a[105][105];
int visited[105][105];
int N;
int max_fl;
int dx[4] = {-1, 0 , 1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt;

void init(){
  for(int i = 0 ; i <= N ; i++){
    for(int j = 0; j <= N ; j++){
      visited[i][j] = 0 ;
    }
  }
}

bool safety(int x, int y){
  return x > 0 && y > 0 && x <= N && y <= N;
}

void bfs(int x, int y, int fl){ // x is flood point

  queue < pair <int , int> > q;

  q.push(make_pair(x,y));
  visited[x][y] = 1;
  cnt++;

  while(!q.empty()){
    int nowx = q.front().first; int nowy = q.front().second;
    q.pop();
    for(int i = 0; i < 4 ; i++){
      int nx = nowx + dx[i]; int ny = nowy + dy[i];
      if(safety(nx,ny) && a[nx][ny] > fl && visited[nx][ny] == 0){
        q.push(make_pair(nx,ny));
        visited[nx][ny] = 1;
      }
    }
  }

}



int mach(int fl){

  cnt = 0;

  for(int i = 1; i <= N ; i++){
    for(int j =  1; j <= N ; j++){
      if(visited[i][j] == 0 && a[i][j] > fl){
        bfs(i,j,fl);
      }
    }
  }

  return cnt;

}

int main(){
  scanf("%d", &N);
  int ans = 0;

  for(int i = 1; i <= N ; i++){
    for(int j = 1; j <= N; j++){
      scanf("%d", &a[i][j]);
      max_fl = max(max_fl, a[i][j]);
    }
  }

  for(int i = 0; i <= max_fl; i++){
    ans = max(ans, mach(i));
    init();
  }

  printf("%d", ans);

  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};


int visited[21][21][11];
vector < pair <int, int> > CP;
vector < cleanPoint > v;
map < <int, int> , int> MP;


char c[21][21];
int R,C;
int robot_x, robot_y;



struct cleanPoint{
  int x, y;
  int value;
};

bool acompare(cleanPoint a, cleanPoint b){
  return a.value < b.value;
}

struct cmp{

  bool operator ()(cleanPoint a, cleanPoint b){
    return a.value < b.value;
  }

};
void init(){

  for(int i = 0 ; i < C; i++){
    for(int j = 0; j < R ; j++){
      visited[i][j] = 0;
    }

  }
}


bool safety(int x, int y){

  return x >= 0 && y >= 0 && x < C && y < R;

}


void bfs(int x, int y, int z){

  queue < pair <int, int> > q;

  visited[x][y][z] = 0;
  q.push(make_pair(x,y));

  while(!q.empty()){
    int tx = q.front().first;
    int ty = q.front().second;
    q.pop();
    for(int i = 0; i < 4; i++){
      int nx = tx + dx[i];
      int ny = ty + dy[i];
      if(safety(nx,ny) && c[nx][ny] != 'X' && visited[nx][ny] == 0){
        visited[nx][ny][z] = visited[tx][ty][z] +1;
        q.push(make_pair(nx,ny));
      }
    }
  }


  visited[x][y][z] = 0;



}


void printV(){
  for(int i =0; i < C; i++){
    for(int j = 0; j < R ; j++){
      printf("%d", visited[i][j]);
    }
    cout << endl;
  }


}

int main(){


  scanf("%d %d", &R, &C);

  int val = 1;

  for(int i =0; i < C; i++){
    for(int j = 0; j < R ; j++){
      scanf(" %c", &c[i][j]);
      if(c[i][j] == 'o'){
        robot_x = i;
        robot_y = j;
      }
      if(c[i][j] == '*'){
        CP.push_back(make_pair(i,j));
        MP.insert(make_pair(make_pair(i,j),val++));
      }
    }
  }








}

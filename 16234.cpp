#include <bits/stdc++.h>

using namespace std;

int a[55][55];
int d[3000];
int c[3000];
int visited[55][55];
int N; 
int L, R;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int flag = 0;

bool safety(int x, int y){
	return x >= 0 && y>= 0 && x < N && y < N;
}
int mach(int x, int y, int uni_num){
	
	queue < pair <int, int> > q;
	
	visited[x][y] = uni_num;	
	d[uni_num] = a[x][y];
	c[uni_num] = 1;
	q.push(make_pair(x,y));
	
	while(!q.empty()){
		int cx = q.front().first; int cy = q.front().second();
		q.pop();
		for(int i = 0; i < 4; i++){
			int nx = cx + dx[i]; int ny = cy + dy[i];
			int diff = abs(a[nx][ny] - a[cx][cy]);
			if(safety(nx,ny) && visited[nx][ny] == 0){
				if(diff <= R && diff >= L){
					visited[nx][ny] = uni_num;
					d[uni_num] += a[nx][ny];				
					c[uni_num]++;
					flag = 1;
				}
			}	
		}		
	}
}

int mach2(){
	
	int uni_num = 1;
	flag = 0;

	for(int i = 0; i < N ; i++){
		for(int j = 0; j < N ; j++){
			if(visited[i][j] == 0)
				mach(i,j,uni_num++);
		}
	}

	for(int i = 1; i <= N ; i++){
		u

}	
int main(){

	
	scanf("%d", &N);
	for(int i = 0; i < N ; i++){
		for(int j = 0; j < N ; j++){
			scanf("%d", &a[i][j]);
		}
	}

	
	return 0;


}

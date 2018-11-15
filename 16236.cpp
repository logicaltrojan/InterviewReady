#include <bits/stdc++.h>

using namespace std;


struct Fish{
    int x, y;
    int fsize;
};

struct cmp{
	bool operator()(Fish a, Fish b){
		return a.fsize < b.fsize;
	}
}


int a[23][23];
int d[23][23];
int N;
int shark_x, shark_y;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int shark_size = 2; 
int grow_count = 2;
priority_queue < Fish > q;

bool safety(int x, int y){
	return x > 0 && y >0 && x <= N && y <= N
}

int find_path(int tx, int ty){
	
	queue < pair <int , int > > bfs_q;
	for(int i = 0; i < = N ; i++){
		for(int j = 0 ; j < = N; j++){
			d[i][j] = -1;
		}
	}

	d[shark_x][shark_y] = 0;

	q.push(make_pair(shark_x, shark_y);
				
	while(!q.empty()){
		int tmp_x = q.front().first; int tmp_y = q.front().second;
		q.pop();
		if(tmp_x == tx && tmp_y == ty) break;
		for(int i = 0 ; i < 4; i++){
			int nx = tmp_x + dx[i]; int ny = tmp_y+ dy[i];
			if(safety(nx,ny) && a[nx][ny] == 0 && d[nx][ny] == 0){
				bfs_q.push(make_pair(nx,ny));	
				d[nx][ny] = d[tmp_x][tmp_y]+1;
				}
		}
	}

	return d[tx][ty];

	
}

void mach2(){


void mach(){
	
	for(int i = 1; i <= N; i++){
		for(int j =1; j <= N; j++){
			q.push(a[j][i]);
		}
	}

	int count1 = 0; 
	while(true){
		struct Fish tmp = q.front(); q.pop();
		int tx = tmp.x; int ty = tmp.y;
		int res = find_path(tx,ty));
		if(res == -1) break;
		shark_x = tx; shark_y = ty; 
		count1 += res;
		if(--grow_count == 0){
			shark_size++;
			grow_count = shark_size;
		}

	}
	
	return count1;

}

int main(){
	
	scanf("%d", &N);
	for(int i = 1; 1 <= N; i++){
		for(int j = 1; j < = N ; j++){
			scanf("%d", &a[i][j]);
		}
	}

	printf("%d\n", mach());


	
}

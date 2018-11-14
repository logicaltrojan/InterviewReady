#include <bits/stdc++.h>

using namespace std;

int N;
int a[23][23];
int visited[23][23];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int shark_size = 2;
int shark_x, shark_y;
int grow_count = 2;
	
typedef struct fish{
	int x,y;
	int dis;
	int val;
} Fish;

struct cmp{
	bool operator()(Fish a, Fish b){
		if(a.dis != b.dis) return a.dis > b.dis;
		if(a.x == b.x) return a.y > b.y;
		else return a.x > b.x;
	}
};


bool safety(int x, int y){
	return x > 0 && y > 0 && x <= N && y <= N;
}
int mach(int sx, int sy){

	priority_queue < Fish, vector <Fish>, cmp > q;

	for(int i = 0; i <= N ; i++){
		for(int j = 0; j <= N ; j++){
			visited[i][j] = -1;
		}
	}
	
	q.push(Fish{sx,sy,0,INT_MAX});
	visited[sx][sy] = 0;

	while(!q.empty()){
		int cx = q.top().x;  int cy = q.top().y;
		int cv = q.top().val; int cd = q.top().dis;
		q.pop();
		if(cv != 0 && cv < shark_size){
			shark_x = cx;
			shark_y = cy;
			a[cx][cy] = 0;
			grow_count--;
			return cd; 
		}
		for(int i = 0 ; i < 4; i++){
			int nx = cx + dx[i]; int ny = cy+dy[i];
			if(safety(nx, ny) && visited[nx][ny] == -1){
				if(a[nx][ny] == 0 || a[nx][ny] <= shark_size){
					q.push(Fish{nx,ny,cd+1,a[nx][ny]});
					visited[nx][ny] = visited[cx][cy]+1;
				}
			}
		}
	}

	return -1;	
					
					
}

int mach2(){

	
	int ans = 0;

	while(true){
		int dis = mach(shark_x, shark_y);
		if(dis == -1) return ans; 
		ans += dis;
		if(grow_count == 0){
			shark_size++;
			grow_count = shark_size;
		}
	}		

}
int main(){
	
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			scanf("%d", &a[i][j]);
			if(a[i][j] == 9){
				shark_x = i;
				shark_y = j;
				a[i][j] = 0;	
			}
		}
	}

	printf("%d", mach2());
	
	
	
}

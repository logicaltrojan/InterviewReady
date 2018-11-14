#include <bits/stdc++.h>

using namsespace std;
int N, M; 
int a[105][105];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0 , -1};
bool safety(int x, int y){
    return x >= 0 && y >= 0 && x < N && y < M; 
}
bool triCheck(int x, int y){
    int count = 0;
    if(x > 0 && y > 0 && x < N-1 && y < M-1) return false;

    for(int i = 0; i < 4; i++){
	int nx = x + dx[i]; int ny = y + dy[i];

		
void mach(){

    for(int i = 

int main(){
	
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++){
	    for(int j = 0; j < M; j++){
		scanf("%d",&a[i][j]);
	    }
	}
	return 0;

}

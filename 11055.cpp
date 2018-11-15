include <bits/stdc++.h>

using namespace std;

int N;
int a[1005];
int d[1004];
vector < int> v;

void mach(int x){ //x is range
	
	v.push_back(a[0]);
		
	int endOfVector = 0;


	for(int i = 0; i < x ; i++){
		if(a[i] > v[endOfVector]){
		    d[i] = endOfVector++;
		    v[endOfVector] = a[i];
		}else{
			    	
		}	

		    
}


int main(){
	scanf("%d", &N);
	for(int i = 0; i < N ; i++){
	    scanf("%d", &a[i]);
	}

}

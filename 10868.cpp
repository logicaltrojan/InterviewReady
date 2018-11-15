#include <bits/stdc++.h>

using namespace std;

int Q;
int N;
vector < int > input;
vector < int> tree;


int query(int left, int right, int start, int end, int node){
    
    if(right < start || end < left) return INT_MAX;
    if(left <= start && end <= right) return tree[node];
    
    int mid = (start + end)/2;

    return min(query(left,right,start,mid,node*2),query(left,right,mid+1,end,node*2+1));

}

int makeSegmentTree(int start, int end, int node){

    if(start == end){
       return tree[node] = input[start];
    }else{
        int mid = (start+end)/2;
        return tree[node] =  min(makeSegmentTree(start, mid, node*2),makeSegmentTree(mid+1, end, node*2+1));
    }

}

void printTree(){
    for(int i = 0; i < tree.size(); i++)
        cout << tree[i] << endl;
}
int main(){
	
        scanf("%d %d", &N, &Q);
        input.resize(N+5);
        tree.resize(pow(2, log2(N)+2));
	for(int i = 1 ; i<=N ; i++){
		scanf("%d", &input[i]);
        }

        makeSegmentTree(1, N, 1);

        int l,r;

      for(int i = 0; i < Q; i++){
          scanf("%d %d", &l, &r);
          printf("%d\n", query(l,r,1,N,1));
        }


}


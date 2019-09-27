#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define MAXN 200100
using namespace std;
 
struct Lazy{
	int a;
	int x;
};
Lazy lazy[4*MAXN];
 
int tree[4*MAXN];
int A[MAXN];
// push back e pop back ?
 
void build(int no,int i,int j){
	Lazy aux = {0,0};
	lazy[no] = aux;
	if(i==j){
		tree[no] = A[i];
	}else{
		int l = 2*no,r= 2*no+1,mid = (i+j)>>1;
		build(l,i,mid);
		build(r,mid+1,j);
		tree[no] = tree[l]+tree[r];
	}
}
 
void att(int no,int i,int j,int a,int b){
	int l = 2*no,r= 2*no+1,mid = (i+j)>>1;
	
	if(lazy[no].a){
		int y = ((lazy[no].a+lazy[no].x)*(j-i+1))/2;
		tree[no]+=y;
		if(i!=j){
			int step = (lazy[no].x - lazy[no].a)/(j-i);
			int m = (j-i)/2;
			lazy[l].a+=lazy[no].a;
			lazy[l].x+=lazy[no].a + (step*m);
			lazy[r].a+= lazy[no].a + (step)*(m+1);
			lazy[r].x+= lazy[no].x;
		}
		lazy[no].a=0;
		lazy[no].x=0;
	}
	
	if(i>b || j<a || i>j)return;
	if(a<=i && j<=b){
		int first = i-a+1;
		int last = j-a+1;
			  		
		int y = ((first + last)*(j-i+1))/2;
		tree[no]+=y;
		int m = (j-i)/2;
		if(i!=j){
			int step = (last - first)/(j-i);
			
			lazy[l].a+=first;
			lazy[l].x+=first + (step*m);
			lazy[r].a+= first + (step)*(m+1);
			lazy[r].x+= last;
		}
	}else{
		att(l,i,mid,a,b);
		att(r,mid+1,j,a,b);
		tree[no] = tree[l]+tree[r];
	}
}
 
int query(int no,int i,int j,int a,int b){
	
	int l = 2*no,r= 2*no+1,mid = (i+j)>>1;
	if(lazy[no].a){
		int y = ((lazy[no].a+lazy[no].x)*(j-i+1))/2;
		tree[no]+=y;
		if(i!=j){
			int step = (lazy[no].x - lazy[no].a)/(j-i);
			int m = (j-i)/2;
			lazy[l].a+=lazy[no].a;
			lazy[l].x+=lazy[no].a + (step*m);
			lazy[r].a+= lazy[no].a + (step)*(m+1);
			lazy[r].x+= lazy[no].x;
		}
		lazy[no].a=0;
		lazy[no].x=0;
	}
	if(i>b || j<a || i>j)return 0;
	if(a<=i && j<=b){
		return tree[no];
	}else{
		return query(l,i,mid,a,b)+query(r,mid+1,j,a,b);
	}
	
}
 
 
 
 
signed main(){
	fastio;
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>A[i];
	}
	build(1,1,n);
	while(q--){
		int op,a,b;
		cin>>op>>a>>b;
		if(op==1){
			att(1,1,n,a,b);
		}else{
			cout<<query(1,1,n,a,b)<<endl;
		}
	}
	return 0;
}

/*

100 100
7 6 4 6 2 9 4 8 10 4 10 3 7 10 2 9 4 1 7 4 5 9 9 7 9 6 5 10 8 4 7 10 5 3 3 1 6 7 6 1 5 7 7 7 7 2 3 5 10 8 4 8 7 5 8 6 8 6 7 9 3 10 6 6 8 1 5 8 5 9 9 5 8 8 4 6 6 3 1 2 1 2 9 2 10 9 9 6 5 7 9 10 5 8 2 7 4 1 4 7
2 72 77
1 62 83
1 72 96
1 20 81
2 42 51
1 70 79
1 60 86
1 95 98
2 88 90
1 45 66
2 15 85
2 24 86
1 70 80
2 28 66
2 39 47
2 51 69
2 12 33
1 80 84
2 93 97
1 86 100
2 60 86
2 50 50
1 98 100
2 62 98
2 3 80
1 76 92
2 80 89
2 68 92
1 43 88
1 17 77
2 64 95
1 20 26
2 92 97
1 92 92
1 79 86
2 48 58
1 85 95
1 59 60
2 68 99
1 56 61
2 40 56
2 29 78
1 86 90
1 77 84
2 6 78
1 77 96
2 40 50
1 68 74
1 19 98
2 79 82
1 61 64
1 19 20
2 53 89
1 93 95
1 71 85
2 33 85
2 34 80
1 54 86
1 69 81
1 40 99
1 62 78
1 100 100
2 57 99
1 99 100
2 75 75
1 23 71
1 21 86
1 34 59
1 83 98
1 55 58
2 49 56
1 21 92
2 17 20
1 24 51
1 66 91
1 53 97
2 41 52
1 84 96
2 54 85
1 92 92
2 29 92
2 26 50
2 65 84
2 54 55
1 84 99
1 89 96
2 17 48
2 3 10
1 70 81
1 80 90
2 41 68
2 13 46
1 8 38
1 57 88
1 11 27
1 42 72
2 51 85
2 67 85
2 31 57
1 52 89


*/
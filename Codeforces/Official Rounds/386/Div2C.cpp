#include <bits/stdc++.h>
#define N (int)1e5+1
#define ii pair<int,int>
#define ff first
#define ss second
 
using namespace std;
 
int main(){
	int n, st, end;
	cin >> n >> st >> end;
	int v1, v2;
	cin >> v1 >> v2;
	int pos, dir;
	cin >> pos >> dir;
	int time = 0;
	int cnt1 = 0, cnt2 = 0;
	if(st > end){
		st = n - st;
		end = n - end;
		pos = n - pos;
		dir = -1*dir;
	}
	//cout << pos << " " << dir << endl;
	if(v1 >= v2){
		cout << (end-st)*v2 << endl;
	}
	else{	
		if(dir == -1){
			time += (pos)*v1 + end*v1;
			pos = 0;
		}
		else if(dir == 1 && st >= pos){
			time += (end-pos)*v1;
		}
		else {
			time += (end*v1) + (n-pos)*v1 + n*v1;
		}
	
		cout << min(time, (end-st)*v2) << endl;
	}
}

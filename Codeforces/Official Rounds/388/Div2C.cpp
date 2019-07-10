#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	
	int n;
	cin >> n;
	queue<int> d,r;
	for(int i=0; i<n; i++){
		char c;
		cin >> c;
		if(c == 'D') d.push(i);
		else r.push(i);
	}
 
	while(!d.empty() && !r.empty()){
		int x,y;
		x = d.front();
		d.pop();
		y = r.front();
		r.pop();
		if(x < y) d.push(x+n);
		else r.push(y+n);
	}
 
	if(d.empty()) cout << "R" << endl;
	else cout << "D" << endl;
}

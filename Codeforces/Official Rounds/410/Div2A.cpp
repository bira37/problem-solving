#include <bits/stdc++.h>
 
using namespace std;
 
bool check(string x){
	string v = x;
	reverse(v.begin(), v.end());
	if(x == v) return true;
	else return false;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	string x;
	cin >> x;
	for(int i=0; i<x.size(); i++){
		char k = x[i];
		for(int j=0; j<26; j++){
			if(('a'+j) != k){
				x[i] = ('a'+j);
				if(check(x)){
					cout << "YES" << endl;
					return 0;
				}
			}
			x[i] = k;
		}
	}
 
	cout << "NO" << endl;
}

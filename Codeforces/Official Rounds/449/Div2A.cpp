#include <bits/stdc++.h>
#define endl '\n'
#define ff first
#define ss second
#define ii pair<int, int>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n,q;
	string s;
	cin >> n >> q;
	cin >> s;
	while(q--){
		int l, r;
		char c1,c2;
		cin >> l >> r >> c1 >> c2;
		l--, r--;
		for(int i=l; i<=r; i++){
			if(s[i] == c1) s[i] = c2;
		}
	}
	cout <<s << endl;
}
	
	
	
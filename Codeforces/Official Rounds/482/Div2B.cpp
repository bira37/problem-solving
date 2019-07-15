#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	string a,b,c;
	cin >> n;
	cin >> a >> b >> c;
	
	int cnt[256];
	for(int i=0; i<256; i++) cnt[i] = 0;
	int ca = 0, cb = 0, cc = 0;
	
	for(char k : a) ca = max(ca, ++cnt[k]);
	
	for(int i=0; i<256; i++) cnt[i] = 0;
	
	for(char k : b) cb = max(cb, ++cnt[k]);
	
	for(int i=0; i<256; i++) cnt[i] = 0;
	
	for(char k : c) cc = max(cc, ++cnt[k]);
	
	if(n == 1 && ca == a.size()) a.pop_back();
	
	if(n == 1 && cb == b.size()) b.pop_back();
	
	if(n == 1 && cc == c.size()) c.pop_back();
	
	ca = min(ca + n, (int)a.size());
	
	cb = min(cb + n, (int)b.size());
	
	cc = min(cc + n, (int)c.size());
	
	if(ca > cb && ca > cc) cout << "Kuro" << endl;
	
	else if(cb > ca && cb > cc) cout << "Shiro" << endl;
	
	else if(cc > cb && cc > ca) cout << "Katie" << endl;
	
	else cout << "Draw" << endl;
}
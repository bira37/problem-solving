#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	string x;
	map<string, int> words;
	cin >> x;
	int ans = 0;
	for(int i=0, len = x.size(); i<len; i++){
		char c = x[len-1];
		x = c + x.substr(0,len-1);
		//x+= c;
		//cout << x << endl;
		if(!words.count(x)){
			ans++;
			words[x] = 1;
		}
	}
	cout << ans << endl; 
}

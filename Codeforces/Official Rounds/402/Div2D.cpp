#include <bits/stdc++.h>
 
using namespace std;
 
 
bool check_substr(string & a, string & b){
	int pointer1=0, pointer2=0;
	while(pointer2 < b.size() && pointer1 < a.size()){
		if(a[pointer1++] == b[pointer2]) pointer2++;
	}
	if(pointer2 == b.size()) return true;
	else return false;
}
 
int main(){
 
	string a, b;
	cin >> a >> b;
	int remove[a.size()];
	bool mark[a.size()];
	
	for(int i=0; i<a.size(); i++){
		cin >> remove[i];
		remove[i]--;
	}
 
	int l = 0;
	int r = a.size() - b.size();
	
	int ans = 0;
	while(l <= r){
		int mid = (l+r)/2;
 
		//new substr
		string aux;
		for(int i=0; i<a.size(); i++) mark[i] = false;
		for(int i=0; i<mid; i++){
			mark[remove[i]] = true;
		}
 
		for(int i=0; i<a.size(); i++){
			if(mark[i]) continue;
			aux+= a[i];
		}
		//cout << mid << endl;
 		//cout << aux << endl;
		bool flag = check_substr(aux, b);
		//cout << flag << endl;
		if(flag){
			ans = mid;
			l = mid+1;
		}
 
		else r = mid-1;
	}
 
	cout << ans << endl;
}

#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n,s;
	char x;
	vector<int> size;
	cin >> n;
	s=0;
	for(int i=0; i<n; i++){
		cin >> x;
		if(x== 'W'){
			if(s!=0) size.push_back(s);
			s=0;
		}
		else s++;
	}
	if(x=='B') size.push_back(s);
	cout << size.size() << endl;
	if(size.size() > 0){
		cout << size[0];
		for(int i=1; i<size.size(); i++) cout << " " << size[i];
		cout << endl;
	}
}

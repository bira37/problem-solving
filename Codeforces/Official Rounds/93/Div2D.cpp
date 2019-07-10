#include <bits/stdc++.h>
 
using namespace std;
 
void precompute(string & s, int * z){
	//string s = str + pattern;
	for(int i=0; i<s.size(); i++) z[i] = 0;
	z[0] = s.size();
	for(int i=1, l = 0, r = 0; i<s.size(); i++){
		if(i <= r) z[i] = min(z[i-l], r-i+1);
		while(s[z[i]] == s[i+z[i]]) z[i]++;
		if(i+z[i] -1 > r){
			r = i+z[i]-1;
			l = i;
		}
	}
}
 
int main(){
	string a;
	cin >> a;
	int z[a.size()];
	precompute(a,z);
	int aux = 0;
	for(int i=1; i<a.size(); i++){
		if(i + z[i] == a.size()) aux = max(aux, z[i]-1);
		else aux = max(aux, z[i]);
	}
	//cout << aux << endl;
	for(int i=1; i<a.size(); i++){
		if(i+z[i] == a.size() && z[i] <= aux) {
			cout << a.substr(0, z[i]) << endl;
			return 0;
		}
	}
	cout << "Just a legend" << endl;
}

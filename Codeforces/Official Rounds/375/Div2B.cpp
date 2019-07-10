#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n;
	cin >> n;
	string x;
	int leng = 0,number=0, maxlen=0, lengpar=0;
	bool par = false;
	cin >> x;
	for(int i=0; i<n; i++){
		if(x[i] == '('){
			par = true;
			maxlen = max(maxlen,leng);
			leng = 0;
			continue;
		}
		if(x[i] == ')'){
			if(lengpar > 0) number++;
			lengpar = 0;
			par = false;
			continue;
		}
		if(!par){
			if(('a' <= x[i] && 'z' >= x[i]) || ('A' <= x[i] && 'Z' >= x[i])){
				leng++;
			}
			else if(x[i] == '_'){
				maxlen = max(maxlen,leng);
				leng = 0;
			}
		}
		else {
			if(('a' <= x[i] && 'z' >= x[i]) || ('A' <= x[i] && 'Z' >= x[i])){
				lengpar ++;
			}
			else if(x[i] == '_'){
				if(lengpar > 0){
					number++;
					lengpar = 0;
				}
			}
		}
	}
	maxlen = max(maxlen,leng);
	cout << maxlen << " " << number << endl;
}

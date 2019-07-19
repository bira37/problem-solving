#include <bits/stdc++.h>

using namespace std;

void precompute(int * KMPnext, string pattern){
	KMPnext[0] = -1;
	for(int i=0, len = pattern.size(); i<len; i++){
		KMPnext[i+1] = KMPnext[i] + 1; //assume um valor aparentemente correto 

		while(KMPnext[i+1] > 0 && pattern[i] != pattern[KMPnext[i+1] -1]) KMPnext[i+1] = KMPnext[KMPnext[i+1] -1] + 1; //corrige o valor
		
	}
}

int main(){
	int n; 
	string x;
	while(cin >> n){
		cin >> x;
		if(n == -1) return 0;
		n -= x.size();
		int KMPnext[x.size()+1];
		precompute(KMPnext, x);
		if(n < 0) cout << 0 << endl;
		else cout << n/(x.size()-KMPnext[x.size()]) + 1 << endl;
	}
}


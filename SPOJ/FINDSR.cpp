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
	string x;
	while(cin >> x, x!= "*"){
		int KMPnext[x.size()+1];
		KMPnext[0] = -1;
		precompute(KMPnext, x);
		int last;
		for(int i=0; i<=x.size(); i++){
			if(KMPnext[i] == 0) last = i;
		}
		cout << (x.size()%last == 0 ? x.size()/last : 1) << endl;
	}
}



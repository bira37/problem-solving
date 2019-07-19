#include <bits/stdc++.h>

using namespace std;

void precompute(int* b, string & pattern){
	int i=0, j=-1;
	b[i] = j;
	while(i < pattern.size()){
		while(j>=0 && pattern[i] != pattern[j]) j = b[j];
		i++;
		j++;
		b[i] = j;
	}
}



int main(){
	int n;
	while(cin >> n){
		string pattern;
		cin >> pattern;
		cin.ignore();
		int b[pattern.size()+1];
		precompute(b, pattern);
		char c;
		int ans = 0;
		int cont = 0;
		int i=0, j=0;
		while(c = getchar(), c!= '\n' && c != EOF){ 
			while(j >=0 && c != pattern[j]) j = b[j];
			j++;
			if(j == pattern.size()){
				cout << cont-j+1 << endl;
				j = b[j];
			}
			cont++;
		}
		if(ans == 0) cout << endl;
	}
}
		



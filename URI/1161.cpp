#include <bits/stdc++.h>

using namespace std;

unsigned long long fat(unsigned long long n){
	if(n == 1 || n == 0) return 1;
	else return n*fat(n-1);
}

int main(){
	unsigned long long n,m;
	while(cin >> n >> m){
		cout << fat(n) + fat(m) << endl;
	}
}

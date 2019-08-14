#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,p;
	while(cin >> n >> p, n +p != 0) cout << "Poo" << string(max(min((n/p + (n%p != 0))-6, 14), 0), 'o') << "dle" << endl;
}


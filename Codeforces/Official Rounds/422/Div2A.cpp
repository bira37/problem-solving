#include <bits/stdc++.h>
 
using namespace std;
 
int fat(int n){
	if(n <= 1) return 1;
	else return n*fat(n-1);
}
 
int main(){
	int a,b;
	cin >> a >> b;
	cout << fat(min(a,b)) << endl;
}

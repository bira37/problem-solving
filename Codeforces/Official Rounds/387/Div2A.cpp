#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	long long int n;
	cin >> n;
	long long int a,b;
	a = 1;
	b= n;
	long long int pa=1,pb=n;
	while(a <=  b){
		while(a*b < n) a++;
		if(a*b == n){
			pa = a;
			pb = b;
		}
		b--;
	}
	if(pa > pb) swap(pa,pb);
	cout << pa << " " << pb << endl;
}

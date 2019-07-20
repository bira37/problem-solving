#include <bits/stdc++.h>
 
using namespace std;
 
#define INF 1 << 30
#define mp make_pair
#define pb push_back
#define ii pair<int,int>
#define OK cout<<"OK"<<endl
#define debug(x) cout << #x " = " << (x) << endl
#define ff first
#define ss second
#define int long long
 
signed main () {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int n;
 
	cin >> n;
 
	vector<int> arr(n);
 
	for(int i = 0;i < n; i++)
		cin>>arr[i];
 
	int qtd = n;
 
	int soma = 0;
	while(qtd != 1) {
		for(int i = 0, j = 0; j < qtd; i++, j+= 2) {
			soma += (int) abs(arr[j]-arr[j+1]);
			if(arr[j] >= arr[j+1]) {
				arr[i] = arr[j];
 
			} else {
 
				arr[i] = arr[j+1];
			}
		}
		qtd/=2;
	}
 
	cout << soma << endl;
 
 
	
}

#include <bits/stdc++.h>
#define endl '\n'
#define ff first
#define ss second
#define ii pair<int,int>
#define pb push_back
#define N
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	int total = 0;
	for(int i=0; i<n; i++){
		cin >> a[i];
		total += a[i];
	}
	int curr = 0;
	int ans = 9000000;
	for(int j=0; j<n; j++){
		int i = j;
		int curr = 0;
		while(true){
			int novo = curr + a[i];
			int diffatual = abs(curr - (360-curr));
			int novadiff = abs(novo - (360-novo));
			if(diffatual <= novadiff){
				ans = min(ans, diffatual);
				break;
			}
			else {
				curr += a[i];
			}
			i++;
			i%=n;
		}
	}
	cout << ans << endl;
}
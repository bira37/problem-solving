#include<bits/stdc++.h>
#define int long long
#define ii pair<int,int>
#define ff first
#define ss second
#define pb(x) push_back(x)
#define td(x) x.begin(),x.end()
#define endl '\n'
using namespace std;
 
tuple<int,int,int> arr[1123];
 
bool better(ii a, ii b){
	if(a.ff*b.ss >= a.ss*b.ff) return true;
	else return false;
}
 
int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}
 
int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int sum = 0;
		int den = 0;
		for(int i=0; i<n; i++){
			int p,v;
			cin >> p >> v;
			sum += p*v;
			den += v;
			arr[i] = make_tuple(p, v, i+1);
		}
		sort(arr, arr+n);
		reverse(arr, arr+n);
		vector<int> ptr;
		ii ans(sum, den);
		for(int i=0; i<n; i++){
			int v,p, id;
			tie(p, v, id) = arr[i];
			int nsum = ans.ff - v*p;
			int nden = ans.ss - v;
			nsum += (v+1)*p;
			nden += (v+1);
			if(better(ii(nsum, nden), ans)){
				ans = ii(nsum, nden);
				ptr.pb(id);
			}
		}
		sort(ptr.begin(), ptr.end());
		int g = gcd(ans.ff, ans.ss);
		cout << ans.ff/g << "/" << ans.ss/g << endl;
		cout << ptr.size() << endl;
		for(int x : ptr) cout << x << " ";
		cout << endl;
	}	 	
}
	
